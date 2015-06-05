local TAG = "MenuScene"

local MenuScene = class("MenuScene", function ()
	return display.newScene("MenuScene")
end)


function MenuScene:ctor()
	local ui = TouchGroup:create()
	self:addChild(ui)
	self.ui = ui

	local layout = Layout:create()
	layout:setTouchEnabled(true)
	ui:addWidget(layout)

	local label_title = Label:create()
	label_title:setFontSize(40)
	label_title:setText("Expriment")
	label_title:setPosition(ccp(display.width/2, display.height-100))
	layout:addChild(label_title)

	local listview = ListView:create()
	listview:setSize(CCSizeMake(display.width, 300))
	listview:setDirection(ccs.ListViewDirection.horizontal)
	--listview:setBackGroundColorType(ccs.LayoutBackGroundColorType.solid)
	--listview:setBackGroundColorOpacity(128)
	--listview:setBackGroundColor(ccc3(100, 0, 0))
	listview:setPosition(ccp(0, 100))
	ui:addWidget(listview)

	local function onBtnItem(sender, event)
		if event == ccs.TouchEventType.ended then
			local tag = sender:getTag()
			if tag == 1 then
  			 	SceneManager:getInstance():gotoScene(SceneId.UI)
			elseif tag == 2 then
   				SceneManager:getInstance():gotoScene(SceneId.SHADER)
			elseif tag == 3 then 
   				SceneManager:getInstance():gotoScene(SceneId.AI)
			elseif tag == 4 then 
   				--SceneManager:getInstance():gotoScene(SceneId.AI)
			elseif tag == 5 then 
			end
		end
	end

	local demos = {"UI.jpg", "Shader.jpg", "default.png", "RPG.jpg"}
	local desc = {"UI", "Shader", "AI", "RPG"}
	for i = 1, 4 do
		local panel_row = Layout:create()
		panel_row:setSize(CCSizeMake(300, 300))
		listview:pushBackCustomItem(panel_row)

		local img = ImageView:create()
		img:loadTexture("demo/"..demos[i])
		img:setScale(0.2)
		img:setPosition(ccp(150, 200))
		img:setTag(i)
		img:setTouchEnabled(true)
		img:addTouchEventListener(onBtnItem)
		panel_row:addChild(img)

		local label_desc = Label:create()
		label_desc:setFontSize(30)
		label_desc:setText(desc[i])
		label_desc:setPosition(ccp(150, 50))
		panel_row:addChild(label_desc)
	end
end

return MenuScene