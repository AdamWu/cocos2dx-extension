--[[
    cocos2dx ccsprite extend to lua
    (override)
--]]

ccsprite_extend = class("ccsprite_extend")
ccsprite_extend.__index = ccsprite_extend

function ccsprite_extend.extend(target)
    local super = tolua.getpeer(target)
    if not super then
        super = {}
        tolua.setpeer(target, super)
    end
    setmetatable(super, ccsprite_extend)
    return target
end

function ccsprite_extend:onEnter()
    print("ccsprite_extend:onEnter")
end

function ccsprite_extend:onExit()
    print("ccsprite_extend:onExit")
end