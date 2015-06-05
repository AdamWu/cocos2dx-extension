-- usage: (use instead of ant)
-- tolua++ "-L" "basic.lua" "-o" "../../scripting/lua/cocos2dx_support/LuaCocos2d.cpp" "Cocos2d.pkg"

_is_functions = _is_functions or {}
_to_functions = _to_functions or {}
_push_functions = _push_functions or {}

local CCObjectTypes = {
    "CCObject",
    "CCAction",
    "CCImage",
    "CCFiniteTimeAction",
    "CCActionInstant",
    "CCCallFunc",
    "CCCallFuncN",
    "CCFlipX",
    "CCFlipY",
    "CCHide",
    "CCPlace",
    "CCReuseGrid",
    "CCShow",
    "CCStopGrid",
    "CCToggleVisibility",
    "CCActionInterval",
    "CCAccelAmplitude",
    "CCAccelDeccelAmplitude",
    "CCActionCamera",
    "CCOrbitCamera",
    "CCCardinalSplineTo",
    "CCCardinalSplineBy",
    "CCCatmullRomTo",
    "CCCatmullRomBy",
    "CCActionEase",
    "CCEaseBackIn",
    "CCEaseBackInOut",
    "CCEaseBackOut",
    "CCEaseBounce",
    "CCEaseElastic",
    "CCEaseExponentialIn",
    "CCEaseExponentialInOut",
    "CCEaseExponentialOut",
    "CCEaseRateAction",
    "CCEaseSineIn",
    "CCEaseSineInOut",
    "CCEaseSineOut",
    "CCAnimate",
    "CCBezierBy",
    "CCBezierTo",
    "CCBlink",
    "CCDeccelAmplitude",
    "CCDelayTime",
    "CCFadeIn",
    "CCFadeOut",
    "CCFadeTo",
    "CCGridAction",
    "CCJumpBy",
    "CCJumpTo",
    "CCMoveTo",
    "CCMoveBy",
    "CCProgressFromTo",
    "CCProgressTo",
    "CCRepeat",
    "CCRepeatForever",
    "CCReverseTime",
    "CCRotateBy",
    "CCRotateTo",
    "CCScaleTo",
    "CCScaleBy",
    "CCSequence",
    "CCSkewTo",
    "CCSkewBy",
    "CCSpawn",
    "CCTintBy",
    "CCTintTo",
    "CCActionManager",
    "CCAnimation",
    "CCAnimationCache",
    "CCArray",
    "CCAsyncObject",
    "CCAutoreleasePool",
    "CCBMFontConfiguration",
    "CCCamera",
    "CCConfiguration",
    "CCData",
    "CCDirector",
    "CCDisplayLinkDirector",
    "CCEvent",
    "CCGrabber",
    "CCGrid3D",
    "CCTiledGrid3D",
    "CCKeypadDispatcher",
    "CCKeypadHandler",
    "CCDictionary",
    "CCNode",
    "CCAtlasNode",
    "CCLabelAtlas",
    "CCTileMapAtlas",
    "CCLayer",
    "CCLayerColor",
    "CCLayerGradient",
    "CCLayerMultiplex",
    "CCMenu",
    "CCMenuItem",
    "CCMenuItemLabel",
    "CCMenuItemAtlasFont",
    "CCMenuItemFont",
    "CCMenuItemSprite",
    "CCMenuItemImage",
    "CCMenuItemToggle",
    "CCMotionStreak",
    "CCParallaxNode",
    "CCParticleSystem",
    "CCParticleBatchNode",
    "CCParticleSystemQuad",
    "CCProgressTimer",
    "CCRenderTexture",
    "CCRibbon",
    "CCScene",
    "CCTransitionScene",
    "CCTransitionCrossFade",
    "CCTransitionFade",
    "CCTransitionFadeTR",
    "CCTransitionFadeBL",
    "CCTransitionFadeDown",
    "CCTransitionFadeUp",
    "CCTransitionJumpZoom",
    "CCTransitionMoveInL",
    "CCTransitionMoveInB",
    "CCTransitionMoveInR",
    "CCTransitionMoveInT",
    "CCTransitionPageTurn",
    "CCTransitionRotoZoom",
    "CCTransitionSceneOriented",
    "CCTransitionFlipAngular",
    "CCTransitionFlipX",
    "CCTransitionFlipY",
    "CCTransitionZoomFlipAngular",
    "CCTransitionZoomFlipX",
    "CCTransitionZoomFlipY",
    "CCTransitionShrinkGrow",
    "CCTransitionSlideInL",
    "CCTransitionSlideInB",
    "CCTransitionSlideInR",
    "CCTransitionSlideInT",
    "CCTransitionSplitCols",
    "CCTransitionSplitRows",
    "CCTransitionTurnOffTiles",
    "CCTransitionProgress",
    "CCTransitionProgressRadialCCW",
    "CCTransitionProgressRadialCW",
    "CCTransitionProgressHorizontal",
    "CCTransitionProgressVertical",
    "CCTransitionProgressInOut",
    "CCTransitionProgressOutIn",
    "CCSprite",
    "CCLabelTTF",
    "CCTextFieldTTF",
    "CCSpriteBatchNode",
    "CCLabelBMFont",
    "CCTMXLayer",
    "CCTMXTiledMap",
    "CCPointObject",
    "CCProjectionProtocol",
    "CCRibbonSegment",
    "CCScheduler",
    "CCSet",
    "CCSpriteFrame",
    "CCSpriteFrameCache",
    "CCString",
    "CCTexture2D",
    "CCTextureAtlas",
    "CCTextureCache",
    "CCTexturePVR",
    "CCTimer",
    "CCTMXLayerInfo",
    "CCTMXMapInfo",
    "CCTMXObjectGroup",
    "CCTMXTilesetInfo",
    "CCTouch",
    "CCTouchDispatcher",
    "CCTouchHandler",
    "CCParticleFire",
    "CCParticleFireworks",
    "CCParticleSun",
    "CCParticleGalaxy",
    "CCParticleFlower",
    "CCParticleMeteor",
    "CCParticleSpiral",
    "CCParticleExplosion",
    "CCParticleSmoke",
    "CCParticleSnow",
    "CCParticleRain",
    "CCScale9Sprite",
    "CCControl",
    "CCControlButton",
    "CCControlColourPicker",
    "CCControlPotentiometer",
    "CCControlSlider",
    "CCControlStepper",
    "CCControlSwitch",
    "CCEditBox",
    "CCInteger",
}

-- register CCObject types
for i = 1, #CCObjectTypes do
    _push_functions[CCObjectTypes[i]] = "toluafix_pushusertype_ccobject"
end

-- register LUA_FUNCTION, LUA_TABLE, LUA_HANDLE type
_to_functions["LUA_FUNCTION"] = "toluafix_ref_function"
_is_functions["LUA_FUNCTION"] = "toluafix_isfunction"
_to_functions["LUA_TABLE"] = "toluafix_totable"
_is_functions["LUA_TABLE"] = "toluafix_istable"

local toWrite = {}
local currentString = ''
local out
local WRITE, OUTPUT = write, output

function output(s)
    out = _OUTPUT
    output = OUTPUT -- restore
    output(s)
end

function write(a)
    if out == _OUTPUT then
        currentString = currentString .. a
        if string.sub(currentString,-1) == '\n'  then
            toWrite[#toWrite+1] = currentString
            currentString = ''
        end
    else
        WRITE(a)
    end
end

function post_output_hook(package)
    local result = table.concat(toWrite)
    local function replace(pattern, replacement)
        local k = 0
        local nxt, currentString = 1, ''
        repeat
            local s, e = string.find(result, pattern, nxt, true)
            if e then
                currentString = currentString .. string.sub(result, nxt, s-1) .. replacement
                nxt = e + 1
                k = k + 1
            end
        until not e
        result = currentString..string.sub(result, nxt)
        if k == 0 then print('Pattern not replaced', pattern) end
    end

    replace([[#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"]],
      [[/****************************************************************************
 Copyright (c) 2013 ice

****************************************************************************/
extern "C" {
#include "tolua_fix.h"
}

#include <map>
#include <string>
#include "cocos2d.h"
#include "CCLuaValue.h"
#include "io/FileSystem.h"
#include "shader/shader_manager.h"
#include "shader/color_sprite.h"
#include "shader/gray_sprite.h"
#include "shader/blind_sprite.h"
#include "shader/bloom_sprite.h"
#include "shader/blur_sprite.h"
#include "shader/frost_sprite.h"
#include "shader/hue_sprite.h"
#include "shader/laser_sprite.h"
#include "shader/normal_sprite.h"
#include "shader/ripple_sprite.h"
#include "shader/stream_sprite.h"
#include "ui/VEScrollView.h"

using namespace cocos2d;]])

      replace([[/* Exported function */
TOLUA_API int  tolua_Cocos2d_open (lua_State* tolua_S);]], [[]])

      replace([[*((LUA_FUNCTION*)]], [[(]])

      replace([[unsigned void* tolua_ret = (unsigned void*)  self->getTiles();]],
        [[unsigned int* tolua_ret = (unsigned int*)  self->getTiles();]])

      replace([[ccColor3B color = *((ccColor3B*)  tolua_tousertype(tolua_S,4,(void*)&(const ccColor3B)ccBLACK));]],
        [[const ccColor3B clr = ccBLACK;
  ccColor3B color = *((ccColor3B*)  tolua_tousertype(tolua_S,4,(void*)&clr));]])

      replace([[tolua_usertype(tolua_S,"LUA_FUNCTION");]], [[]])

      replace([[toluafix_pushusertype_ccobject(tolua_S,(void*)tolua_ret]],
        [[int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret]])

      replace('\t', '    ')

    WRITE(result)
end
