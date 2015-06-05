--[[
    cocos2dx ccnode extend to lua
    (override)
--]]

ccnode_extend = {}
ccnode_extend.__index = ccnode_extend

function ccnode_extend.extend(target)
    local super = tolua.getpeer(target)
    if not super then
        super = {}
        tolua.setpeer(target, super)
    end
    setmetatable(super, ccnode_extend)
    return target
end

function ccnode_extend:onEnter()
    print("ccnode_extend:onEnter")
end

function ccnode_extend:onExit()
    print("ccnode_extend:onExit")
end
