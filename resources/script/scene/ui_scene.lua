local TAG = "UIScene"

local UIScene = class("UIScene", function ()
	return display.newScene("UIScene")
end)


function UIScene:ctor()
	local layer = CCLayer:create()
	self:addChild(layer)
	
	local ui = TouchGroup:create()
	layer:addChild(ui)
	self.ui = ui

	local layout = Layout:create()
	layout:setTouchEnabled(true)
	ui:addWidget(layout)

	local bg = ImageView:create()
	bg:loadTexture("gui/bg.png")
	bg:setPosition(ccp(display.width/2, display.height/2));
	bg:setScale(2)
	layout:addChild(bg)

	-- btn back
	local function onBtnBack(sender, event)
		print("onBtnBack", event)
		if event == ccs.TouchEventType.ended then
   			SceneManager:getInstance():gotoScene(SceneId.MENU)
		end
	end
	local btn_back = Button:create()
	btn_back:loadTextures("gui/back.png", "", "")
	btn_back:setPosition(ccp(display.width-50, display.height-100))
	btn_back:setTouchEnabled(true)
	btn_back:addTouchEventListener(onBtnBack)
	layout:addChild(btn_back)


	-- test1
	local scrollview = VEScrollView:create()
	scrollview:setPosition(ccp(display.width/2-150, display.height/2+20))
	scrollview:setViewSize(CCSizeMake(180, 300))
	scrollview:setType(SCROLLVIEW_VERTICAL)
	for i = 1, 10 do
		local sprite = CCSprite:create("gui/btn_1.png")
		sprite:setTag(i)
		scrollview:addCell(sprite)

		local label_title = CCLabelTTF:create()
		label_title:setFontSize(40)
		label_title:setString(i)
		label_title:setPosition(ccp(sprite:getContentSize().width/2, sprite:getContentSize().height/2))
		sprite:addChild(label_title)
	end
	ui:addChild(scrollview)

	-- test2
	local scrollview2 = VEScrollView:create()
	scrollview2:setPosition(ccp(display.width/2+150, display.height/2+20))
	scrollview2:setViewSize(CCSizeMake(180, 300))
	scrollview2:setType(SCROLLVIEW_VERTICAL)
	local label = CCLabelTTF:create()
	label:setFontSize(40);
	label:setString("Test")
	scrollview2:addCell(label)
	label = CCLabelTTF:create()
	label:setFontSize(26)
	label:setString("this is a test for scroll view, this is a test for scroll view, this is a test for scroll view")
	label:setDimensions(CCSizeMake(170, 200))
	scrollview2:addCell(label)	
	local sprite = CCSprite:create("gui/btn_1.png")
	scrollview2:addCell(sprite)
	label = CCLabelTTF:create()
	label:setFontSize(26)
	label:setString("ok")
	label:setPosition(ccp(sprite:getContentSize().width/2, sprite:getContentSize().height/2))
	sprite:addChild(label)
	ui:addChild(scrollview2)

	-- test3
	local scrollview3 = VEScrollView:create()
	scrollview3:setPosition(ccp(display.width/2, display.height/2-250))
	scrollview3:setViewSize(CCSizeMake(600, 130))
	scrollview3:setType(SCROLLVIEW_HORIZONTAL)
	for i = 1, 10 do
		local sprite = CCSprite:create("gui/item1.png")
		scrollview3:addCell(sprite)

		local label = CCLabelTTF:create()
		label:setFontSize(26)
		label:setString(i)
		label:setPosition(ccp(sprite:getContentSize().width/2, sprite:getContentSize().height/2))
		sprite:addChild(label)
	end
	ui:addChild(scrollview3)
end


return UIScene