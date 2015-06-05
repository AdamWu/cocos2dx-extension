--[[
	register gobal module
--]]
math.randomseed(os.time())
math.random()
math.random()
math.random()
math.random()

require "framework.core.extern"
require "framework.common.init"
require "framework.debug.init"
require "framework.2dx.init"

echoInfo("#")
echoInfo("# DEBUG                        = "..DEBUG)
echoInfo("#")

--json		= require "cjson"

-- show fps
if DEBUG_FPS then
    CCDirector:sharedDirector():setDisplayStats(true)
end

local timeCount = 0
local function showMemoryUsage(dt)
    timeCount = timeCount + dt
    echoInfo(string.format("MEMORY USED: %0.2f KB, UPTIME: %04.2fs", collectgarbage("count"), timeCount))
end
-- show memory usage
if DEBUG_MEM then
    CCDirector:sharedDirector():getScheduler():scheduleScriptFunc(showMemoryUsage, 10.0, false)
end

