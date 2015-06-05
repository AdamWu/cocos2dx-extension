--[[
    marquee 走马灯
--]]
CCMarquee = {}
CCMarquee.__index = CCMarquee

function CCMarquee:create(w, h, fontSize, speed, interval)
    local instance = {}
    instance.size = CCSizeMake(w, h)
    instance.fontSize = fontSize
    instance.speed = speed or 60
    instance.interval = interval or 2
    instance.msg_list = {}
    instance.msg_idx = 0
    instance.render_list = {}

    -- 模板
    --local stencil = CCSprite:create("image/gui/public/bg_t3.png")
    --stencil:setPosition(0, 0)
    local stencil = UIImageView:create()
    stencil:setTexture("image/gui/public/bg_t5.png")
    stencil:setScale9Size(CCSizeMake(w, h))

    -- 裁剪节点
    local clippingNode = CCClippingNode:create()
    clippingNode:setAnchorPoint(ccp(0.5, 0.5))
    clippingNode:setStencil(stencil:getVirtualRenderer())
    self.clippingNode = clippingNode

    setmetatable(instance, CCMarquee)
    return instance
end

function CCMarquee:getRender()
    return self.clippingNode
end

-- str: colorful label
-- bloop: loop or not
-- binstant: instant or not
function CCMarquee:addMsg(str, bLoop, bInstant)
    if bInstant == true then
        table.insert(self.msg_list, self.msg_idx+1, {str=str, loop=bLoop or false})
        
        -- modify backward
        for k, v in ipairs(self.render_list) do
            if v["idx"] > self.msg_idx+1 then
                v["idx"] = v["idx"] + 1
            end
            if self.msg_idx > idx then self.msg_idx = self.msg_idx + 1 end
        end
    else
        table.insert(self.msg_list,  {str=str, loop=bLoop or false})
    end
    --print(table.inspect(self.msg_list))
end

function CCMarquee:removeAllMsgs()
    self.msg_list = {}
    self.msg_idx = 0
end

function CCMarquee:restart()
    self:clear()

    local render_list = self.render_list
    local dur = self.interval
    local function update(dt)
        local offset = self.speed * dt
        for k, v in ipairs(render_list) do
            -- move one step for all existing labels
            local node = v["node"]
            local x, y = node:getPosition()
            node:setPosition(ccp(x-offset, y))
        end
        -- check label add
        if dur >= self.interval then
            local idx = self.msg_idx % #self.msg_list + 1
            local msg = self.msg_list[idx]

            if msg then
                --print("add msg:", msg["str"]) 
                local flag = true
                for k, v in ipairs(render_list) do
                    --print(idx, v["idx"])
                    if v["idx"] == idx and msg["loop"] == false then
                        flag = false
                    end
                end
                if flag == true then
                    -- use this one   
                    local label = CCLabelColorful:create()
                    label:setAnchorPoint(ccp(0, 0))
                    label:setString(msg["str"])
                    --label:setPosition(ccp(self.size.width/2, 0))
                    label:setPosition(ccp(self.size.width/2+label:getContentSize().width/2, 0))
                    self.clippingNode:addChild(label)

                    table.insert(render_list, {node=label, idx=idx})
                    self.msg_idx = idx
                    dur = 0
                else
                    --use next one 
                    self.msg_idx = idx
                end
            end
        end
        -- check label move
        local last = render_list[#render_list]
        if last then
            local node = last["node"]
            local x, y = node:getPosition()
            local size = node:getContentSize()
            if self.size.width/2 + size.width/2 - x > size.width then
                --print("counter", dur)
                dur = dur + dt
            end
            self.clippingNode:getParent():setVisible(true)
        else
            self.clippingNode:getParent():setVisible(false)
        end
        -- check label remove
        local top = render_list[1]
        if top then
            local idx = top["idx"]
            local node = top["node"]
            local x, y = node:getPosition()
            local size = node:getContentSize()
            if self.size.width/2 + size.width/2 - x > size.width + self.size.width then
                --print("remove top msg")
                node:removeFromParentAndCleanup(true)
                table.remove(render_list, 1)
                local msg = self.msg_list[idx]
                if msg and msg["loop"] == false then
                    table.remove(self.msg_list, idx)
                    --print("delete msg:", msg["str"])
                    -- modify forward
                    for k, v in ipairs(render_list) do
                        if v["idx"] > idx then
                            v["idx"] = v["idx"] - 1
                        end
                    end
                    if self.msg_idx > idx then self.msg_idx = self.msg_idx - 1 end
                end
            end
        end
    end
    self.clippingNode:scheduleUpdateWithPriorityLua(update, 0)
end

function CCMarquee:clear()
    self.render_list = {}
    self.clippingNode:removeAllChildrenWithCleanup(true)
    self.clippingNode:unscheduleUpdate()
end