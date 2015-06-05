local TAG = "ShaderScene"

local ShaderScene = class("ShaderScene", function ()
	return display.newScene("ShaderScene")
end)


function ShaderScene:ctor()

	local layer = CCLayer:create()
	self:addChild(layer)

	local ui = TouchGroup:create()
	layer:addChild(ui)
	self.ui = ui

	local layout = Layout:create()
	layout:setTouchEnabled(true)
	ui:addWidget(layout)

	local label_title = Label:create()
	label_title:setFontSize(40)
	label_title:setPosition(ccp(display.width/2, display.height-100))
	layout:addChild(label_title)
	self.label_title = label_title

	-- btn back
	local function onBtnBack(sender, event)
		print("onBtnBack", event)
		if event == ccs.TouchEventType.ended then
			if self.type == 0 then 
	   			SceneManager:getInstance():gotoScene(SceneId.MENU)
	   		else
	   			self:showMain()
	   		end
		end
	end
	local btn_back = Button:create()
	btn_back:loadTextures("gui/back.png", "", "")
	btn_back:setPosition(ccp(display.width-50, display.height-100))
	btn_back:setTouchEnabled(true)
	btn_back:addTouchEventListener(onBtnBack)
	layout:addChild(btn_back)

	self.panel = Layout:create()
	ui:addWidget(self.panel)

	self.type = 0
	self:showMain()
end

function ShaderScene:showMain()
	self.type = 0
	self.label_title:setText("Shader")

	self.panel:removeAllChildren()

	local listview = ListView:create()
	listview:setSize(CCSizeMake(display.width, 300))
	listview:setDirection(ccs.ListViewDirection.horizontal)
	listview:setPosition(ccp(0, 100))
	self.panel:addChild(listview)

	local function onBtnItem(sender, event)
		if event == ccs.TouchEventType.ended then
			local tag = sender:getTag()
			if tag == 1 then
				self:showStream()
			elseif tag == 2 then
				self:showBlur()
			elseif tag == 3 then 
				self:showBlind()
			elseif tag == 4 then
				self:showBloom()
			elseif tag == 5 then 
				self:showFrost()
			elseif tag == 6 then 
				self:showNormal()
			elseif tag == 7 then 
				self:showRipple()
			elseif tag == 8 then 
				self:showHue()
			end
		end
	end

	local demos = {"Stream.jpg", "Blur.jpg", "Blind.jpg", "Bloom.jpg", "Frost.jpg", "default.png", "default.png", "default.png"}
	local desc = {"Stream", "Blur", "Blind", "Bloom", "Frost", "Normal", "Ripple", "Hue"}
	for i = 1, #demos do
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

function ShaderScene:showStream()
	self.type = 1
	self.label_title:setText("Stream")

	self.panel:removeAllChildren()

	local sprite = StreamSprite:create("gui/powered.png")
	sprite:setPosition(ccp(display.width/2, display.height/2))
	local widget = Widget:create()
	widget:addNode(sprite)
	self.panel:addChild(widget)
end

function ShaderScene:showBlur()
	self.type = 1
	self.label_title:setText("Blur")
	self.panel:removeAllChildren()
	
	local sprite = BlurSprite:create("gui/powered.png")
	sprite:setPosition(ccp(display.width/2, display.height/2))
	local widget = Widget:create()
	widget:addNode(sprite)
	self.panel:addChild(widget)
end

function ShaderScene:showBlind()
	self.type = 1
	self.label_title:setText("Blind")
	self.panel:removeAllChildren()
	
	local arr = CCArray:create()
	arr:addObject(CCString:create("gui/tex_1.jpg"))
	arr:addObject(CCString:create("gui/tex_2.png"))
	local sprite = BlindSprite:create(arr)
	sprite:setPosition(ccp(display.width/2, display.height/2))
	local widget = Widget:create()
	widget:addNode(sprite)
	self.panel:addChild(widget)
end

function ShaderScene:showBloom()
	self.type = 1
	self.label_title:setText("Bloom")
	self.panel:removeAllChildren()

	local widget = Widget:create()
		
	local sprite = BloomSprite:create("gui/batfly.png")
	sprite:setPosition(ccp(display.width/2, display.height/2))
	widget:addNode(sprite)

	local sprite = CCSprite:create("gui/batfly.png")
	sprite:setPosition(ccp(display.width/2, display.height/2))
	widget:addNode(sprite)

	self.panel:addChild(widget)
end

function ShaderScene:showFrost()
	self.type = 1
	self.label_title:setText("Frost")
	self.panel:removeAllChildren()
		
	local sprite = FrostSprite:create("gui/powered.png")
	sprite:setPosition(ccp(display.width/2, display.height/2))
	local widget = Widget:create()
	widget:addNode(sprite)
	self.panel:addChild(widget)
end

function ShaderScene:showNormal()
	self.type = 1
	self.label_title:setText("Normal")
	self.panel:removeAllChildren()
		
	local layer = CCLayer:create()
	local sprite = NormalSprite:create("gui/powered.png","gui/powered_n.jpg")
	sprite:setPosition(ccp(display.width/2, display.height/2))
	sprite:setAnchorPoint(ccp(0.5, 0.5))
	--sprite:setLightColor(COLOR_RED)
	layer:addChild(sprite)
	local widget = Widget:create()
	widget:addNode(layer)
	self.panel:addChild(widget)

	local size = sprite:getContentSize()
	
    local function onTouchBegan(x, y)
		sprite:setLightPos(ccp(x, y))
        return false
    end
    local function onTouchMove(x, y)
		sprite:setLightPos(ccp(x, y))
    end
    local function onTouch(eventType, pos)
    	local x = pos[1] - size.width/2
    	local y = pos[2] - size.height/2
    	print(x, y)
        if eventType == "began" then
            return onTouchBegan(x, y)
        elseif eventType == "moved" then
        	return onTouchMove(x, y)
        end
    end
    layer:setTouchEnabled(true) 
    layer:registerScriptTouchHandler(onTouch)

end

function ShaderScene:showRipple()
	self.type = 1
	self.label_title:setText("Ripple")
	self.panel:removeAllChildren()
	
	local widget = Widget:create()

	local sprite = RippleSprite:create("gui/powered.png")
	sprite:setPosition(ccp(display.width/2-200, display.height/2))
	widget:addNode(sprite)

	local sprite = RippleSprite:create("gui/powered.png")
	sprite:setPosition(ccp(display.width/2+200, display.height/2))
	sprite:setTile(0.1)
	sprite:setNoiseFactor(0.01)
	sprite:setSpeed(0.02)
	widget:addNode(sprite)

	self.panel:addChild(widget)
end

function ShaderScene:showHue()
	self.type = 1
	self.label_title:setText("Hue")
	self.panel:removeAllChildren()
	
	local widget = Widget:create()

	local sprite = CCSprite:create("gui/powered.png")
	sprite:setPosition(ccp(display.width/2-300, display.height/2))
	widget:addNode(sprite)

	local sprite = HueSprite:create("gui/powered.png")
	sprite:setPosition(ccp(display.width/2-100, display.height/2))
	sprite:setHue(0.5*math.pi)
	widget:addNode(sprite)

	local sprite = HueSprite:create("gui/powered.png")
	sprite:setPosition(ccp(display.width/2+100, display.height/2))
	sprite:setHue(1.2*math.pi)
	widget:addNode(sprite)
	
	local sprite = HueSprite:create("gui/powered.png")
	sprite:setPosition(ccp(display.width/2+300, display.height/2))
	sprite:setHue(1.8*math.pi)
	widget:addNode(sprite)

	self.panel:addChild(widget)
end


return ShaderScene