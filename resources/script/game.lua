require "config"
require "framework/init"
require "scene/scene_manager"

-- avoid memory leak
collectgarbage("setpause", 100)
collectgarbage("setstepmul", 5000)

-- for CCLuaEngine traceback
function __G__TRACKBACK__(msg)
	print("----------------------------------------")
	print("LUA ERROR: " .. tostring(msg) .. "")
	print(debug.traceback())
	print("----------------------------------------")
end

local function main()
	ShaderManager:getInstance()
   	SceneManager:getInstance():gotoScene(SceneId.MENU)
end

main()
