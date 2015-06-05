--[[
    cocos2dx cclabelttf
    colorfull, multi-line
--]]
CCLabelColorMulti = {}
CCLabelColorMulti.__index = CCLabelColorMulti

function CCLabelColorMulti:create(w, h, fontSize, lineSpace)
    local instance = {}
    instance.size = CCSizeMake(w, h)
    instance.position = ccp(0, h)
    instance.rt = CCRenderTexture:create(w, h)
    instance.fontSize = fontSize
    instance.lineSpace = lineSpace or 0
    instance.lines = 1
    instance.layer = CCSprite:create()
    instance.layer:setAnchorPoint(ccp(0, 0))
    instance.layer:setContentSize(CCSizeMake(w, h))
    instance.layer:addChild(instance.rt)
    instance.bVerticalCenter = false
    setmetatable(instance, CCLabelColorMulti)

    instance.rt:retain()
    
    return instance
end

function CCLabelColorMulti:getRender()
    return self.layer
end

function CCLabelColorMulti:getRealSize()
    return CCSizeMake(self.size.width, self.lines*(self.fontSize+self.lineSpace))
end

function CCLabelColorMulti:setVerticalCenter(bCenter)
    self.bVerticalCenter = bCenter
end

function CCLabelColorMulti:addString(str, fontName, fontColor, bRender)
    local fontSize = self.fontSize
    local width = self.fontSize
    local point = self.position
    local bRender = bRender or false

    local label = CCLabelTTF:create("", fontName, fontSize)
    label:setAnchorPoint(ccp(0, 1))

    local pos = 1
    while pos <= str:len() do
        local l = 0
        local x = point.x
        local bRet = false
        while pos + l <= str:len() do
            local tp = 0

            -- 换行符(\n)
            --print(str:sub(pos, pos+l), string.byte(str:sub(pos+l-1, pos+l)))
            local _start, _end = string.find(str:sub(pos, pos+l), "\n")
            if (str:sub(pos, pos+l)) == "\n" or (_start and _end) then
                l = l + 1
                bRet = true
                break
            end

            if string.byte(str, pos+l) > 0x80 then
                tp = 1
                l = l + 3
                x = x + fontSize
            else
                tp = 2
                l = l + 1
                x = x + fontSize/2 
            end
            if x > self.size.width - fontSize*2 then 
                if tp == 1 then
                    l = l - 3
                else
                    l = l - 1
                end
                bRet = true
                break 
            end
        end

        --print("label", pos, l, str:sub(pos, pos+l-1))
        if bRender then
            label:setString(str:sub(pos, pos+l-1))
            label:setColor(fontColor)
            self.rt:begin()
            label:setPosition(point)
            label:visit()
            self.rt:endToLua()
        end

        pos = pos + l
        if bRet then    -- 换行 
            point.x = 0
            point.y = point.y - fontSize - self.lineSpace
            self.lines = self.lines + 1
        else
            point.x = x
        end
    end 
    self.position = point

    if self.bVerticalCenter then
        local offset = self.position.y - fontSize
        self.rt:setPosition(ccp(0, -offset/2))
    end
end

function CCLabelColorMulti:addFormatString(str, fontName, bRender)
    --print(str)
    local result = require("framework.common.html").parsestr(str)
    local function parse(str, result, default)
        for k, v in ipairs(str) do
            if type(v) == "table" then
                parse(v, result)
            else
                table.insert(result, {v, attr=str._attr})
            end 
        end
    end
    local list = {}
    parse(result, list)
    --print(table.inspect(list))
    for k, v in ipairs(list) do
        local word = v[1]
        local color = v.attr.c
        if color then
            local l = string.split(color, ',')
            self:addString(word, fontName, ccc3(tonumber(l[1]), tonumber(l[2]), tonumber(l[3])), bRender)
        else
            self:addString(word, fontName, ccc3(255, 255, 255), bRender)
        end
    end
end