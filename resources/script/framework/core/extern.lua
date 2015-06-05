
--Create an class.
function class(classname, super)
    local superType = type(super)
    local cls

    if superType ~= "function" and superType ~= "table" then
        superType = nil
        super = nil
    end

    if superType == "function" or (super and super.__ctype == 1) then
        -- inherited from native C++ Object
        cls = {}

        if superType == "table" then
            -- copy fields from super
            for k,v in pairs(super) do cls[k] = v end
            cls.__create = super.__create
            cls.super    = super
        else
            cls.__create = super
        end

        cls.ctor    = function() end
        cls.__cname = classname
        cls.__ctype = 1

        function cls.new(...)
            local instance = cls.__create(...)
            -- copy fields from class to native object
            for k,v in pairs(cls) do instance[k] = v end
            instance.class = cls
            instance:ctor(...)
            return instance
        end

    else
        -- inherited from Lua Object
        if super then
            --cls = clone(super)
            cls = {}
            for k,v in pairs(super) do cls[k] = v end
            cls.super = super
        else
            cls = {ctor = function() end}
        end

        cls.__cname = classname
        cls.__ctype = 2 -- lua
        cls.__index = cls

        function cls.new(...)
            local instance = setmetatable({}, cls)
            local create
            create = function(c, ...)
                if c.super then -- 递归向上调用create
                    create(c.super, ...)
                end
                if c.ctor then
                    c.ctor(instance, ...)
                end
            end
            create(instance, ...)
            instance.class = cls
            return instance
        end
    end

    return cls
end


function super(classname, instance)
    if classname == instance.__cname then
        return instance.super
    elseif instance.super then
        return super(classname, instance.super)
    end
    return nil
end

Logger = {}
function Logger:debug(msg)
    print("LUA DEBUG:", msg)
end

function Logger:info(msg)
    print("LUA INFO:", msg)
end

function Logger:error(msg)
    print("LUA ERROR", msg)
end

function Logger:warning(msg)
    print("LUA WARNING:", msg)
end