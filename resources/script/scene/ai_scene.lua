local TAG = "AIScene"

local AIScene = class("AIScene", function ()
	return display.newScene("AIScene")
end)

local astar = require("framework/core/astar")
--local astar = require("astar")

local astar_idx = 1
local astars = {
    require("astar"),
    require("astar2"),
    require("framework/core/astar"),
}
local astars_title = {
    "AStar - array",
    "AStar - map",
    "AStar - map, heap sort",
}

local scale_map = 0.4

function AIScene:ctor()

	local layer = CCLayer:create()
	self:addChild(layer)

	local ui = TouchGroup:create()
	layer:addChild(ui)
	self.ui = ui

	local layout = Layout:create()
	layout:setTouchEnabled(true)
	ui:addWidget(layout)

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

    -- btn switch
    local function onBtnSwitch(sender, event)
        if event == ccs.TouchEventType.ended then
            astar_idx = astar_idx % (#astars) + 1
            self.label_title:setText(astars_title[astar_idx])
        end
    end
    local btn_switch = Button:create()
    btn_switch:loadTextures("gui/btn_1.png", "", "")
    btn_switch:setPosition(ccp(100, 100))
    btn_switch:setTouchEnabled(true)
    btn_switch:setTitleText("switch")
    btn_switch:setTitleFontSize(30)
    btn_switch:addTouchEventListener(onBtnSwitch)
    layout:addChild(btn_switch)


    -- 
    local label = Label:create()
    label:setFontSize(24)
    label:setText(astars_title[astar_idx])
    label:setAnchorPoint(ccp(0, 0.5))
    label:setPosition(ccp(50, display.height-40))
    layout:addChild(label)
    self.label_title = label
    local label2 = Label:create()
    label2:setFontSize(24)
    label2:setText("Elapsed time (s):")
    label2:setAnchorPoint(ccp(0, 0.5))
    label2:setPosition(ccp(50, display.height-80))
    layout:addChild(label2)
    self.label_tip = label2


	local map = CCTMXTiledMap:create("map/map_50x50.tmx")
    map:setScale(scale_map)
    ui:addChild(map)
    print("mapsize", map:getMapSize().width, map:getMapSize().height)
    local background = map:layerNamed("background")
    local collisionlayer = map:layerNamed("collision")
    local layersize = collisionlayer:getLayerSize()
    print("LayerSize", layersize.width, layersize.height)

    local map = {}
    for i = 0, layersize.width-1 do 
        map[i+1] = {}
        for j = 0, layersize.height-1 do 
            map[i+1][j+1] = collisionlayer:tileGIDAt(ccp(i, j))
        end
    end

   -- print(table.inspect(map))

    local function search(_start, _end)
        print(string.format("search (%s, %s), (%s, %s)", _start.row, _start.col, _end.row, _end.col))
        astars[astar_idx]:init(map, _start, _end)

        local time = os.clock()
        local path = astars[astar_idx]:searchPath()
        print("search using ", os.clock()-time)
        self.label_tip:setText("Elapsed time (s):" .. string.format("%.4f", os.clock()-time))

       -- print(table.inspect(path))
       if path then
            local resultPath = {}
            for k, v in ipairs(path) do
                resultPath[#path - k + 1] = v
            end
            for k, v in ipairs(resultPath) do
                local row, col = v.row, v.col
                local sprite = background:tileAt(ccp(row-1, col-1))
                if sprite then sprite:setColor(COLOR_RED) end
            end
        end
    end

    local function search2(_start, _end)
        print(string.format("search (%s, %s), (%s, %s)", _start.row, _start.col, _end.row, _end.col))

        AStarMap:getInstance():init(layersize.width, layersize.height, 0)
        for i = 0, layersize.width-1 do
            for j = 0, layersize.height-1 do 
                MapSearch:getInstance():initMap(i, j, map[i+1][j+1])
            end
        end

        local time = os.clock()
        MapSearch:getInstance():search(_start.row-1, _start.col-1, _end.row-1, _end.col-1)
        print("search using ", os.clock()-time)
        self.label_tip:setText("Elapsed time (s):" .. string.format("%.4f", os.clock()-time))
       -- print(table.inspect(path))

        local state = MapSearch:getInstance():getSearchState()
        if state == 2 then
            local steps = MapSearch:getInstance():getSearchSteps()
            local resultPath = {}
            for i = 0, steps-1 do
                local x = MapSearch:getInstance():getSearchNodeX(i)
                local y = MapSearch:getInstance():getSearchNodeY(i)
                table.insert(resultPath, {row=x, col=y})
            end
            for k, v in ipairs(resultPath) do
                local row, col = v.row, v.col
                local sprite = background:tileAt(ccp(row, col))
                if sprite then sprite:setColor(COLOR_RED) end
            end
        end
    end


    local function search3(_start, _end)
        print(string.format("search (%s, %s), (%s, %s)", _start.row, _start.col, _end.row, _end.col))

        local astar = AStarMap(layersize.width, layersize.height)
        for i = 0, layersize.width-1 do
            for j = 0, layersize.height-1 do 
                astar:initMap(i, j, map[i+1][j+1])
            end
        end 
        astar:initNode()

        local time = os.clock()
        local state = astar:Search(_start.row-1, _start.col-1, _end.row-1, _end.col-1)
        print("search using ", os.clock()-time)
        self.label_tip:setText("Elapsed time (s):" .. string.format("%.4f", os.clock()-time))
       -- print(table.inspect(path))

        if state == 2 then
            local steps = astar:getResultSteps()
            local resultPath = {}
            for i = 0, steps-1 do
                local x = astar:getResultNodeX(i)
                local y = astar:getResultNodeY(i)
                table.insert(resultPath, {row=x, col=y})
            end
            for k, v in ipairs(resultPath) do
                local row, col = v.row, v.col
                local sprite = background:tileAt(ccp(row, col))
                if sprite then sprite:setColor(COLOR_RED) end
            end
        end
        astar:release()
    end

    local function getCoordByPos(x, y)
        -- recenter
        local cell_w = 64*scale_map
        local cell_h = 32*scale_map
        x = x * scale_map
        y = y * scale_map
        x = x - cell_w/2
        y = y - cell_h/2
        local i = math.max(x/cell_w - y/cell_h - 20/2 + 20, 0) / scale_map
        local j = math.max(-x/cell_w - y/cell_h + 20/2 + 20 - 1, 0) / scale_map
        return ccp(math.floor(i), math.floor(j))
    end

    local function onTouchBegan(x, y)
        local coord = getCoordByPos(x, y)
        print(coord.x, coord.y)
        if coord.x >= 0 and coord.y >= 0 and coord.x < layersize.width and coord.y < layersize.height then
            local id = collisionlayer:tileGIDAt(coord)
            print("touch mapid", id)
            
            local size = background:getLayerSize()
            for i = 0, size.width-1 do
                for j = 0, size.height-1 do
                    local sprite = background:tileAt(ccp(i, j))
                    if sprite then sprite:setColor(COLOR_WHITE) end
                end
            end

            search({row=1, col=1}, {row=coord.x+1, col=coord.y+1})
        end
        return false
    end

    local function onTouch(eventType, x, y)
        if eventType == "began" then
            return onTouchBegan(x,y)
        end
    end

    layer:setTouchEnabled(true) 
    layer:registerScriptTouchHandler(onTouch)
end


return AIScene