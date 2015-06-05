--场景管理
SceneManager = class("SceneManager", nil)

SceneId = {
	MENU 	= 0,
	UI  = 1,
	SHADER = 2,
	AI 	= 3,
	RPG = 4,
}

local instance = SceneManager.new()

function SceneManager:ctor()
	-- body
end

function SceneManager:getInstance()
	return instance
end

function SceneManager:getCurrentScene()
	return self._currentScene
end

function SceneManager:getCurrentSceneId()
	return self._currentSceneId
end

function SceneManager:setCurrentScene(sceneId, scene)
	self._currentScene = scene
	self._currentSceneId = sceneId
end

function SceneManager:gotoScene(sceneId, param)
	print("SceneManager:gotoScene", sceneId, param)

	if sceneId == SceneId.MENU then
		self._currentScene = require("scene/menu_scene").new()
		self._currentSceneId = SceneId.MENU
		display.replaceScene(self._currentScene)
	elseif sceneId == SceneId.UI then
		self._currentScene = require("scene/ui_scene").new()
		self._currentSceneId = SceneId.UI
		display.replaceScene(self._currentScene)
	elseif sceneId == SceneId.SHADER then
		self._currentScene = require("scene/shader_scene").new()
		self._currentSceneId = SceneId.UI
		display.replaceScene(self._currentScene)
	elseif sceneId == SceneId.AI then
		self._currentScene = require("scene/ai_scene").new()
		self._currentSceneId = SceneId.AI
		display.replaceScene(self._currentScene)
	elseif sceneId == SceneId.AI then
		self._currentScene = require("scene/rpg_scene").new()
		self._currentSceneId = SceneId.AI
		display.replaceScene(self._currentScene)
	end
end
