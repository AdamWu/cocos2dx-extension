local display = {}

local sharedDirector         = CCDirector:sharedDirector()
local sharedTextureCache     = CCTextureCache:sharedTextureCache()
local sharedSpriteFrameCache = CCSpriteFrameCache:sharedSpriteFrameCache()
local sharedAnimationCache   = CCAnimationCache:sharedAnimationCache()

-- check device screen size
local glview = sharedDirector:getOpenGLView()
local size = glview:getFrameSize()
display.sizeInPixels = {width = size.width, height = size.height}

local w = display.sizeInPixels.width
local h = display.sizeInPixels.height

if CONFIG_SCREEN_WIDTH == nil or CONFIG_SCREEN_HEIGHT == nil then
    CONFIG_SCREEN_WIDTH = w
    CONFIG_SCREEN_HEIGHT = h
end

local function checkScale(w, h)
    local scale = 1
    local wscale, hscale = w / CONFIG_SCREEN_WIDTH, h / CONFIG_SCREEN_HEIGHT
    if CONFIG_SCREEN_AUTOSCALE == "FIXED_WIDTH" then
        scale = wscale
    elseif CONFIG_SCREEN_AUTOSCALE == "FIXED_WIDTH_PRIOR" then
        if wscale > hscale then
            scale = wscale
        else
            scale = hscale
        end
    elseif CONFIG_SCREEN_AUTOSCALE == "FIXED_HEIGHT" then
        scale = hscale
    elseif CONFIG_SCREEN_AUTOSCALE == "FIXED_HEIGHT_PRIOR" then
        if wscale < hscale then
            scale = wscale
        else
            scale = hscale
        end
    end
    return scale, wscale, hscale
end

local scale, wscale, hscale = 1, 1, 1
if type(CONFIG_SCREEN_AUTOSCALE) == "function" then
    CONFIG_SCREEN_AUTOSCALE(w, h)
    glview:setDesignResolutionSize(CONFIG_SCREEN_WIDTH, CONFIG_SCREEN_HEIGHT, kResolutionNoBorder)
elseif CONFIG_SCREEN_AUTOSCALE then
    scale, wscale, hscale = checkScale(w, h)

    if type(CONFIG_RESOURCE_SIZE) == "table" then
        local selectedSize, lastSize
        for i, size in ipairs(CONFIG_RESOURCE_SIZE) do
            local maxContentScale = size.scale or 99999
            if scale <= maxContentScale then
                selectedSize = size
                break
            end
            lastSize = size
        end

        if not selectedSize and lastSize then selectedSize = lastSize end
        CCFileUtils:sharedFileUtils():addSearchPath(selectedSize.path)

        w = w / scale * selectedSize.scale
        h = h / scale * selectedSize.scale
        scale, wscale, hscale = checkScale(w, h)
    end

    CONFIG_SCREEN_AUTOSCALE = string.upper(CONFIG_SCREEN_AUTOSCALE)
    if CONFIG_SCREEN_AUTOSCALE == "FIXED_WIDTH" then
        CONFIG_SCREEN_HEIGHT = h / scale
    elseif CONFIG_SCREEN_AUTOSCALE == "FIXED_WIDTH_PRIOR" then
        if wscale > hscale then
            CONFIG_SCREEN_HEIGHT = h / scale
        else
            CONFIG_SCREEN_WIDTH = w / scale
        end
    elseif CONFIG_SCREEN_AUTOSCALE == "FIXED_HEIGHT" then
        CONFIG_SCREEN_WIDTH = w / scale
    elseif CONFIG_SCREEN_AUTOSCALE == "FIXED_HEIGHT_PRIOR" then
        if wscale < hscale then
            CONFIG_SCREEN_HEIGHT = h / scale
        else
            CONFIG_SCREEN_WIDTH = w / scale
        end
    else
        echoError(string.format("display - invalid CONFIG_SCREEN_AUTOSCALE \"%s\"", CONFIG_SCREEN_AUTOSCALE))
    end

    glview:setDesignResolutionSize(CONFIG_SCREEN_WIDTH, CONFIG_SCREEN_HEIGHT, kResolutionNoBorder)
end

local winSize = sharedDirector:getWinSize()
display.contentScaleFactor = scale
display.size               = {width = winSize.width, height = winSize.height}
display.width              = display.size.width
display.height             = display.size.height
display.cx                 = display.width / 2
display.cy                 = display.height / 2
display.c_left             = -display.width / 2
display.c_right            = display.width / 2
display.c_top              = display.height / 2
display.c_bottom           = -display.height / 2
display.left               = 0
display.right              = display.width
display.top                = display.height
display.bottom             = 0
display.widthInPixels      = display.sizeInPixels.width
display.heightInPixels     = display.sizeInPixels.height

echoInfo(string.format("# CONFIG_SCREEN_AUTOSCALE      = %s", CONFIG_SCREEN_AUTOSCALE))
echoInfo(string.format("# CONFIG_SCREEN_WIDTH          = %0.2f", CONFIG_SCREEN_WIDTH))
echoInfo(string.format("# CONFIG_SCREEN_HEIGHT         = %0.2f", CONFIG_SCREEN_HEIGHT))
echoInfo(string.format("# display.widthInPixels        = %0.2f", display.widthInPixels))
echoInfo(string.format("# display.heightInPixels       = %0.2f", display.heightInPixels))
echoInfo(string.format("# display.contentScaleFactor   = %0.2f", display.contentScaleFactor))
echoInfo(string.format("# display.width                = %0.2f", display.width))
echoInfo(string.format("# display.height               = %0.2f", display.height))
echoInfo(string.format("# display.cx                   = %0.2f", display.cx))
echoInfo(string.format("# display.cy                   = %0.2f", display.cy))
echoInfo(string.format("# display.left                 = %0.2f", display.left))
echoInfo(string.format("# display.right                = %0.2f", display.right))
echoInfo(string.format("# display.top                  = %0.2f", display.top))
echoInfo(string.format("# display.bottom               = %0.2f", display.bottom))
echoInfo(string.format("# display.c_left               = %0.2f", display.c_left))
echoInfo(string.format("# display.c_right              = %0.2f", display.c_right))
echoInfo(string.format("# display.c_top                = %0.2f", display.c_top))
echoInfo(string.format("# display.c_bottom             = %0.2f", display.c_bottom))
echoInfo("#")

display.TEXTURES_PIXEL_FORMAT = {}

display.COLOR_WHITE = ccc3(255, 255, 255)
display.COLOR_BLACK = ccc3(0, 0, 0)

display.CENTER        = 1
display.LEFT_TOP      = 2; display.TOP_LEFT      = 2
display.CENTER_TOP    = 3; display.TOP_CENTER    = 3
display.RIGHT_TOP     = 4; display.TOP_RIGHT     = 4
display.CENTER_LEFT   = 5; display.LEFT_CENTER   = 5
display.CENTER_RIGHT  = 6; display.RIGHT_CENTER  = 6
display.BOTTOM_LEFT   = 7; display.LEFT_BOTTOM   = 7
display.BOTTOM_RIGHT  = 8; display.RIGHT_BOTTOM  = 8
display.BOTTOM_CENTER = 9; display.CENTER_BOTTOM = 9

display.ANCHOR_POINTS = {
    ccp(0.5, 0.5),  -- CENTER
    ccp(0, 1),      -- TOP_LEFT
    ccp(0.5, 1),    -- TOP_CENTER
    ccp(1, 1),      -- TOP_RIGHT
    ccp(0, 0.5),    -- CENTER_LEFT
    ccp(1, 0.5),    -- CENTER_RIGHT
    ccp(0, 0),      -- BOTTOM_LEFT
    ccp(1, 0),      -- BOTTOM_RIGHT
    ccp(0.5, 0),    -- BOTTOM_CENTER
}

display.SCENE_TRANSITIONS = {
    CROSSFADE       = {CCTransitionCrossFade, 2},
    FADE            = {CCTransitionFade, 3, ccc3(0, 0, 0)},
    FADEBL          = {CCTransitionFadeBL, 2},
    FADEDOWN        = {CCTransitionFadeDown, 2},
    FADETR          = {CCTransitionFadeTR, 2},
    FADEUP          = {CCTransitionFadeUp, 2},
    FLIPANGULAR     = {CCTransitionFlipAngular, 3, kCCTransitionOrientationLeftOver},
    FLIPX           = {CCTransitionFlipX, 3, kCCTransitionOrientationLeftOver},
    FLIPY           = {CCTransitionFlipY, 3, kCCTransitionOrientationUpOver},
    JUMPZOOM        = {CCTransitionJumpZoom, 2},
    MOVEINB         = {CCTransitionMoveInB, 2},
    MOVEINL         = {CCTransitionMoveInL, 2},
    MOVEINR         = {CCTransitionMoveInR, 2},
    MOVEINT         = {CCTransitionMoveInT, 2},
    PAGETURN        = {CCTransitionPageTurn, 3, false},
    ROTOZOOM        = {CCTransitionRotoZoom, 2},
    SHRINKGROW      = {CCTransitionShrinkGrow, 2},
    SLIDEINB        = {CCTransitionSlideInB, 2},
    SLIDEINL        = {CCTransitionSlideInL, 2},
    SLIDEINR        = {CCTransitionSlideInR, 2},
    SLIDEINT        = {CCTransitionSlideInT, 2},
    SPLITCOLS       = {CCTransitionSplitCols, 2},
    SPLITROWS       = {CCTransitionSplitRows, 2},
    TURNOFFTILES    = {CCTransitionTurnOffTiles, 2},
    ZOOMFLIPANGULAR = {CCTransitionZoomFlipAngular, 2},
    ZOOMFLIPX       = {CCTransitionZoomFlipX, 3, kCCTransitionOrientationLeftOver},
    ZOOMFLIPY       = {CCTransitionZoomFlipY, 3, kCCTransitionOrientationUpOver},
}

function display.newScene(name)
    local scene = CCScene:create()
    scene.name = name or "<unknown-scene>"
    return scene
end

function display.wrapSceneWithTransition(scene, transitionType, time, more)
    local key = string.upper(tostring(transitionType))
    if string.sub(key, 1, 12) == "CCTRANSITION" then
        key = string.sub(key, 13)
    end

    if key == "RANDOM" then
        local keys = table.keys(display.SCENE_TRANSITIONS)
        key = keys[math.random(1, #keys)]
    end

    if display.SCENE_TRANSITIONS[key] then
        local cls, count, default = unpack(display.SCENE_TRANSITIONS[key])
        time = time or 0.2
        
        if count == 3 then
            scene = cls:create(time, scene, more or default)
        else
            scene = cls:create(time, scene)
        end
    else
        echoError("display.wrapSceneWithTransition() - invalid transitionType %s", tostring(transitionType))
    end
    return scene
end

function display.replaceScene(newScene, transitionType, time, more)
    if sharedDirector:getRunningScene() then
        if transitionType then
            newScene = display.wrapSceneWithTransition(newScene, transitionType, time, more)
        end
        sharedDirector:replaceScene(newScene)
    else
        sharedDirector:runWithScene(newScene)
    end
end

function display.getRunningScene()
    return sharedDirector:getRunningScene()
end

function display.pause()
    sharedDirector:pause()
end

function display.resume()
    sharedDirector:resume()
end

function display.align(target, anchorPoint, x, y)
    target:setAnchorPoint(display.ANCHOR_POINTS[anchorPoint])
    if x and y then target:setPosition(x, y) end
end

function display.addSpriteFramesWithFile(plistFilename, image)
    if display.TEXTURES_PIXEL_FORMAT[image] then
        CCTexture2D:setDefaultAlphaPixelFormat(display.TEXTURES_PIXEL_FORMAT[image])
        sharedSpriteFrameCache:addSpriteFramesWithFile(plistFilename, image)
        CCTexture2D:setDefaultAlphaPixelFormat(kCCTexture2DPixelFormat_RGBA8888)
    else
        sharedSpriteFrameCache:addSpriteFramesWithFile(plistFilename, image)
    end
end

function display.removeSpriteFramesWithFile(plistFilename, imageName)
    sharedSpriteFrameCache:removeSpriteFramesFromFile(plistFilename)
    if imageName then
        display.removeSpriteFrameByImageName(imageName)
    end
end

function display.setTexturePixelFormat(filename, format)
    display.TEXTURES_PIXEL_FORMAT[filename] = format
end

function display.removeSpriteFrameByImageName(imageName)
    sharedSpriteFrameCache:removeSpriteFrameByName(imageName)
    CCTextureCache:sharedTextureCache():removeTextureForKey(imageName)
end

return display