--[[
    cocos2dx cclabelttf
    outline
--]]
CCLabelOutline = {}

function CCLabelOutline:create(label, size, color, opacity, dir)
    local tex_size = label:getTexture():getContentSize()
    local rt = CCRenderTexture:create(tex_size.width + size*2, tex_size.height + size*2);

    local orignalPos = ccp(label:getPosition())
    local orignalColor = label:getColor();
    local orignalOpacity = label:getOpacity();
    local originalBlend = label:getBlendFunc();

    local newBlend = blendfunc(GL_SRC_ALPHA, GL_ONE)

    label:setBlendFunc(newBlend);
    label:setColor(color);
    label:setOpacity(opacity);

    local bottomLeft = ccp(tex_size.width * label:getAnchorPoint().x + size,tex_size.height * label:getAnchorPoint().y + size);
    local positionOffset = ccp(-tex_size.width/2, -tex_size.height/2);

    local position = ccpSub(orignalPos, positionOffset);

    local function degree_to_radian(degree)
        return degree*math.pi/180
    end
    -- render to texture
    rt:begin()

    if dir == -1 then
        for i = 0, 360, 10 do
            label:setPosition(ccp(bottomLeft.x + math.sin(degree_to_radian(i))*size, bottomLeft.y + math.cos(degree_to_radian(i))*size));
            label:visit()
        end
    else
        local degree  = dir % 360;
        label:setPosition(ccp(bottomLeft.x + sin(degree_to_radian(degree))*size, bottomLeft.y + cos(degree_to_radian(degree))*size));
        label:visit();
    end
    
    rt:endToLua()

    rt:getSprite():getTexture():setAntiAliasTexParameters()

    -- restore label
    label:setColor(orignalColor);
    label:setOpacity(orignalOpacity);
    label:setBlendFunc(originalBlend);
    label:setPosition(orignalPos);

    rt:setPosition(orignalPos);

    return rt;
end
