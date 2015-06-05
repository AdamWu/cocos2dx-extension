require "framework/core/extern"


Model = class("Model", nil)
local modelInstance = nil

function Model:ctor(...)
	self._proxyMap = {}
end

function Model:getInstance()
	if modelInstance == nil then
		modelInstance = Model:new()
	end
	return modelInstance
end

function Model:registerProxy(proxy)
	local name = proxy._proxyName
	if self._proxyMap[name] == nil then
		self._proxyMap[name] = proxy
	else
		Logger:error("A proxy with same name has been registered.")
	end

end

function Model:removeProxy(proxyName)
	self._proxyMap[proxyName] = nil
end

function Model:retrieveProxy(proxyName)
	return self._proxyMap[proxyName]
end

----------------------------------------------------

View = class("View", nil)
local viewInstance = nil

function View:ctor(...)
	self._observerMap = {}
	self._mediatorMap = {}
end

function View:getInstance()
	if viewInstance == nil then
		viewInstance = View:new()
	end
	return viewInstance
end

function View:registerObserver(notiName, observer)
	if self._observerMap[notiName] == nil then
		self._observerMap[notiName] = {}
	end
	table.insert(self._observerMap[notiName], observer)
end

function View:removeObserver(notiName, context)
	local obList = self._observerMap[notiName]
	if obList ~= nil then
		for k,v in pairs(obList) do
			if v:compareNotifyContext(context) then
				table.remove(obList, k)
			end
		end
	end
end

function View:registerMediator(mediator)
	local name = mediator._mediatorName
	if self._mediatorMap[name] == nil then
		self._mediatorMap[name] = mediator

		local interests = mediator:listNotificationInterests()
		if next(interests) ~= nil then
			local observer = IObserver:new(mediator)
			function observer:notifyObserver(notification)
				mediator:handleNotification(notification)
			end
			for k,v in pairs(interests) do
				self:registerObserver(v, observer)
			end
		end
	else
		Logger:warning("A mediator with same name has been registered.")
	end
end

function View:removeMediator(mediatorName)
	local mediator = self._mediatorMap[mediatorName]
	if mediator ~= nil then
		local interests = mediator:listNotificationInterests()
		for k,v in pairs(interests) do
			self:removeObserver(v, mediator)
		end
		self._mediatorMap[mediatorName] = nil
	end
end

function View:retrieveMediator(mediatorName)
	return self._mediatorMap[mediatorName]
end

function  View:notifyObservers(notification)
	if self._observerMap[notification._name] ~= nil then
		for k,v in pairs(self._observerMap[notification._name]) do
			v:notifyObserver(notification)
		end
	end
end

------------------------------------------------------

Controller = class("Controller", nil)
local controllerInstance = nil

function Controller:ctor(...)
	self._commandMap = {}
	self._view = View:getInstance()
end


function Controller:executeCommand(notification)
	local command = self._commandMap[notification._name]
	if command ~= nil then
		command:execute(notification)
	end
end

--Register a particular ICommand class as the handler for a particular INotification.
function Controller:registerCommand(notiName, command)
	if self._commandMap[notiName] == nil then
		self._commandMap[notiName] = command
		local observer = IObserver:new(self)
		local controller = self
		function observer:notifyObserver(notification)
			controller:executeCommand(notification)
		end
		self._view:registerObserver(notiName, observer)
	else
		Logger:warning("the notification has been registered by another command")
	end
	
end

function Controller:removeCommand(notiName)
	if self._commandMap[notiName] ~= nil then
		self._view:removeObserver(notiName, self)
		self._commandMap[notiName] = nil
	end
end

function Controller:getInstance()
	if controllerInstance == nil then
		controllerInstance = Controller:new()
	end
	return controllerInstance
end

----------------------------------------------------

IMediator = class ("IMediator", nil)

function IMediator:ctor(...)
	self._mediatorName = ""
	self._viewComponent = nil
end


function IMediator:listNotificationInterests() -- return a list of interests notifications
	return {}
end

function IMediator:handleNotification(notification)
	Logger:warning("unimplemented abstract method")
end


-----------------------------------------------------

IProxy = class ("IProxy", nil)

function IProxy:ctor(...)
	self._proxyName = ""
end

function IProxy:sendNotification(notiName, body, type)
	local notification = INotification:new()
	notification._name = notiName
	notification._body = body
	notification._type = type
	View:getInstance():notifyObservers(notification)
end

------------------------------------------------------

INotification = class ("INotification", nil)

function INotification:ctor(...)
	local this, name, body, type_ = ...
	self._name = name
	self._body = body
	self._type = type_
end


-------------------------------------------------------
ICommand = class ("ICommand", nil)

function ICommand:ctor(...)
end

function ICommand:execute(notification)
	Logger:warning("unimplemented abstract method")
end

function ICommand:sendNotification(notiName, body, type)
	local notification = INotification:new()
	notification._name = notiName
	notification._body = body
	notification._type = type
	View:getInstance():notifyObservers(notification)
end

-----------------------------------------------------
IObserver = class ("IObserver", nil)

function IObserver:ctor(...)
	local this, context = ...
	self._context = context
end

function IObserver:compareNotifyContext(obj)
	return self._context == obj
end

function IObserver:notifyObserver(notification)
	Logger:warning("unimplemented abstract method")
end

------------------------------------------------------

Facade = class("Facade", nil)
local facadeInstance = nil

function Facade:ctor(...)
	self._view = View:getInstance()
	self._model = Model:getInstance()
	self._controller = Controller:getInstance()
end

function Facade:getInstance()
	if facadeInstance == nil then
		facadeInstance = Facade:new()
	end
	return facadeInstance
end


function Facade:registerCommand(notiName, command)
	self._controller:registerCommand(notiName, command)
end

function Facade:removeCommand(notiName)
	self._controller:removeCommand(notiName)
end

function Facade:registerMediator(mediator)
	self._view:registerMediator(mediator)
end 

function Facade:removeMediator(mediatorName)
	self._view:removeMediator(mediatorName)
end

function Facade:retrieveMediator(mediatorName)
	return self._view:retrieveMediator(mediatorName)
end

function Facade:removeMediator(mediatorName)
	self._view:removeMediator(mediatorName)
end

function Facade:registerProxy(proxy)
	self._model:registerProxy(proxy)
end

function Facade:retrieveProxy(proxyName)
	return self._model:retrieveProxy(proxyName)
end

function Facade:notifyObservers(notification)
	self._view:notifyObservers(notification)
end

function Facade:sendNotification(notiName, body, type)
	self:notifyObservers(INotification:new(notiName, body, type))
end
