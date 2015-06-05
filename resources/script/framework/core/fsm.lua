local TAG = "fsm"

-- fsm state 
local FSMState = {}

function FSMState:new(super)
	local obj = super or {}
	obj.super = self
	return setmetatable(obj, {__index = self})
end


function FSMState:enter()
	--echoLog(TAG, "%s enter", self.name)
end


function FSMState:exit()
	--echoLog(TAG, "%s exit", self.name)
end


-- fsm state machine
local FSMStateMachine = {}

function FSMStateMachine:new()
	local obj = {}
	obj._pause = true
	obj._curState = nil
	return setmetatable(obj, {__index = self})
end

function FSMStateMachine:addState(stateName)
	if self[stateName] then
		echoLog(TAG, "state:%s already added", stateName)
	else 
		self[stateName] = {state=FSMState:new{name=stateName}, events={}}
	end
end

function FSMStateMachine:start(stateName)
	self._pause = false
	self._preState = nil
	self._curState = stateName
end

function FSMStateMachine:addTransition(before, input, after)
	local preStates = {} 
	local inputs = {}
	local postStates = {}
	if type(before) == "table" then
		preStates = before
	else
		table.insert(preStates, before)
	end
	if type(input) == "table" then
		assert(type(after) == "table" and #input == #after)
		inputs = input
		postStates = after
	else
		assert(type(after) ~= "table")
		table.insert(inputs, input)
		table.insert(postStates, after)
	end

	for i, preState in ipairs(preStates) do 
		local state = self[preState]["state"]
		local events = self[preState]["events"]
		if events then
			for j, ip in ipairs(inputs) do
				if events[ip] then
					echoLog(TAG, "event:%s already be added", ip)
				else
					events[ip] = postStates[j]
				end
			end
		else
			echoError(TAG, "state not found:%s", preState)
		end
	end
end

function FSMStateMachine:checkStateTransion(event)
	assert(self._curState)
	local state = self[self._curState]["state"]
	local out = self[self._curState]["events"][event]
	--print("fsm", out, "cur",self._curState, "event", event)
	if out then 
		return true
	else
		return false
	end
end

function FSMStateMachine:stateTransition(event)
	assert(self._curState)
	local state = self[self._curState]["state"]
	local out = self[self._curState]["events"][event]

	if out then
		echoLog(TAG, "reponse to event:%s", event)
		-- respond to this event
		self[self._curState]["state"]:exit()
		self._preState = state.name
		self._curState = out
		if self[self._curState] then
			self[self._curState]["state"]:enter()
		else
			echoLog(TAG, "state not exist:%s", self._curState)
		end
		return true, self._curState
	else
		-- no related event
		echoLog(TAG, "no reponse to event:[%s] in state [%s]", event, state.name)
		return false
	end
end

return FSMStateMachine


------------------------------------------------------------------
--	test
------------------------------------------------------------------
--[[
local fsm = FSMStateMachine:new()
--print(require("framework/debug/inspect")(sm))
fsm:addTransition("idle", "seen player", "walk")
fsm:addTransition("idle", "player attack", "attack")
fsm:addTransition("walk", "player attack", "attack")
fsm:addTransition("walk", "player go away", "idle")
fsm:addTransition("attack", "player die", "idle")
--print(require("framework/debug/inspect")(sm))

fsm:stateTransition("player attack")
fsm:stateTransition("seen player")
fsm:stateTransition("player die")
--]]

