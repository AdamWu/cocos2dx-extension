/*
** Lua binding: utils
** Generated automatically by tolua++-1.0.92 on 06/04/15 18:06:21.
*/

/****************************************************************************
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

using namespace cocos2d;

/* Exported function */
TOLUA_API int  tolua_utils_open (lua_State* tolua_S);

#include "LuaCocos2d.h"

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_NormalSprite (lua_State* tolua_S)
{
 NormalSprite* self = (NormalSprite*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}

static int tolua_collect_StreamSprite (lua_State* tolua_S)
{
 StreamSprite* self = (StreamSprite*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}

static int tolua_collect_CCPoint (lua_State* tolua_S)
{
 CCPoint* self = (CCPoint*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}

static int tolua_collect_HueSprite (lua_State* tolua_S)
{
 HueSprite* self = (HueSprite*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}

static int tolua_collect_FrostSprite (lua_State* tolua_S)
{
 FrostSprite* self = (FrostSprite*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}

static int tolua_collect_SpotLight (lua_State* tolua_S)
{
 SpotLight* self = (SpotLight*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}

static int tolua_collect_CCSize (lua_State* tolua_S)
{
 CCSize* self = (CCSize*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}

static int tolua_collect_LaserSprite (lua_State* tolua_S)
{
 LaserSprite* self = (LaserSprite*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}

static int tolua_collect_BlindSprite (lua_State* tolua_S)
{
 BlindSprite* self = (BlindSprite*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}

static int tolua_collect_BloomSprite (lua_State* tolua_S)
{
 BloomSprite* self = (BloomSprite*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}

static int tolua_collect_CCRect (lua_State* tolua_S)
{
 CCRect* self = (CCRect*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}

static int tolua_collect_BlurSprite (lua_State* tolua_S)
{
 BlurSprite* self = (BlurSprite*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}

static int tolua_collect_RippleSprite (lua_State* tolua_S)
{
 RippleSprite* self = (RippleSprite*) tolua_tousertype(tolua_S,1,0);
    Mtolua_delete(self);
    return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"NormalSprite");
 tolua_usertype(tolua_S,"StreamSprite");
 tolua_usertype(tolua_S,"CCTexture2D");
 tolua_usertype(tolua_S,"CCTouch");
 tolua_usertype(tolua_S,"scroll_touch");
 tolua_usertype(tolua_S,"HueSprite");
 tolua_usertype(tolua_S,"FrostSprite");
 tolua_usertype(tolua_S,"FileSystem");
 tolua_usertype(tolua_S,"ccColor4F");
 tolua_usertype(tolua_S,"CCSize");
 tolua_usertype(tolua_S,"CCNode");
 tolua_usertype(tolua_S,"BloomSprite");
 tolua_usertype(tolua_S,"GraySprite");
 tolua_usertype(tolua_S,"ColorSprite");
 tolua_usertype(tolua_S,"CCArray");
 tolua_usertype(tolua_S,"CCSet");
 tolua_usertype(tolua_S,"CCLayer");
 tolua_usertype(tolua_S,"CCEvent");
 tolua_usertype(tolua_S,"VEScrollView");
 tolua_usertype(tolua_S,"RippleSprite");
 tolua_usertype(tolua_S,"CCPoint");
 tolua_usertype(tolua_S,"CCRect");
 tolua_usertype(tolua_S,"SpotLight");
 tolua_usertype(tolua_S,"ccColor3B");
 tolua_usertype(tolua_S,"BlindSprite");
 tolua_usertype(tolua_S,"LaserSprite");
 tolua_usertype(tolua_S,"CCSprite");
 tolua_usertype(tolua_S,"ccVertex3F");
 tolua_usertype(tolua_S,"CCObject");
 tolua_usertype(tolua_S,"BlurSprite");
 tolua_usertype(tolua_S,"ShaderManager");
}

/* method: getInstance of class  FileSystem */
#ifndef TOLUA_DISABLE_tolua_utils_FileSystem_getInstance00
static int tolua_utils_FileSystem_getInstance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"FileSystem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   FileSystem* tolua_ret = (FileSystem*)  FileSystem::getInstance();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"FileSystem");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getInstance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getFileData of class  FileSystem */
#ifndef TOLUA_DISABLE_tolua_utils_FileSystem_getFileData00
static int tolua_utils_FileSystem_getFileData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FileSystem",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FileSystem* self = (FileSystem*)  tolua_tousertype(tolua_S,1,0);
  const char* fullPath = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getFileData'", NULL);
#endif
  {
   const char* tolua_ret = (const char*)  self->getFileData(fullPath);
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getFileData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getInstance of class  ShaderManager */
#ifndef TOLUA_DISABLE_tolua_utils_ShaderManager_getInstance00
static int tolua_utils_ShaderManager_getInstance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ShaderManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   ShaderManager* tolua_ret = (ShaderManager*)  ShaderManager::getInstance();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ShaderManager");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getInstance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  ColorSprite */
#ifndef TOLUA_DISABLE_tolua_utils_ColorSprite_create00
static int tolua_utils_ColorSprite_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ColorSprite",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* filename = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   ColorSprite* tolua_ret = (ColorSprite*)  ColorSprite::create(filename);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ColorSprite");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createWithTexture of class  ColorSprite */
#ifndef TOLUA_DISABLE_tolua_utils_ColorSprite_createWithTexture00
static int tolua_utils_ColorSprite_createWithTexture00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ColorSprite",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCTexture2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCTexture2D* pTexture = ((CCTexture2D*)  tolua_tousertype(tolua_S,2,0));
  {
   ColorSprite* tolua_ret = (ColorSprite*)  ColorSprite::createWithTexture(pTexture);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ColorSprite");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createWithTexture'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: initWithFile of class  ColorSprite */
#ifndef TOLUA_DISABLE_tolua_utils_ColorSprite_initWithFile00
static int tolua_utils_ColorSprite_initWithFile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ColorSprite",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ColorSprite* self = (ColorSprite*)  tolua_tousertype(tolua_S,1,0);
  const char* filename = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'initWithFile'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->initWithFile(filename);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'initWithFile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: initWithTexture of class  ColorSprite */
#ifndef TOLUA_DISABLE_tolua_utils_ColorSprite_initWithTexture00
static int tolua_utils_ColorSprite_initWithTexture00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ColorSprite",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCTexture2D",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const CCRect",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ColorSprite* self = (ColorSprite*)  tolua_tousertype(tolua_S,1,0);
  CCTexture2D* pTexture = ((CCTexture2D*)  tolua_tousertype(tolua_S,2,0));
  const CCRect* rect = ((const CCRect*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'initWithTexture'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->initWithTexture(pTexture,*rect);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'initWithTexture'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setColor of class  ColorSprite */
#ifndef TOLUA_DISABLE_tolua_utils_ColorSprite_setColor00
static int tolua_utils_ColorSprite_setColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ColorSprite",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"ccColor3B",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ColorSprite* self = (ColorSprite*)  tolua_tousertype(tolua_S,1,0);
  ccColor3B color = *((ccColor3B*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setColor'", NULL);
#endif
  {
   self->setColor(color);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  GraySprite */
#ifndef TOLUA_DISABLE_tolua_utils_GraySprite_create00
static int tolua_utils_GraySprite_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GraySprite",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* filename = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   GraySprite* tolua_ret = (GraySprite*)  GraySprite::create(filename);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GraySprite");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createWithTexture of class  GraySprite */
#ifndef TOLUA_DISABLE_tolua_utils_GraySprite_createWithTexture00
static int tolua_utils_GraySprite_createWithTexture00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"GraySprite",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCTexture2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCTexture2D* pTexture = ((CCTexture2D*)  tolua_tousertype(tolua_S,2,0));
  {
   GraySprite* tolua_ret = (GraySprite*)  GraySprite::createWithTexture(pTexture);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"GraySprite");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createWithTexture'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: initWithFile of class  GraySprite */
#ifndef TOLUA_DISABLE_tolua_utils_GraySprite_initWithFile00
static int tolua_utils_GraySprite_initWithFile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GraySprite",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GraySprite* self = (GraySprite*)  tolua_tousertype(tolua_S,1,0);
  const char* filename = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'initWithFile'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->initWithFile(filename);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'initWithFile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: initWithTexture of class  GraySprite */
#ifndef TOLUA_DISABLE_tolua_utils_GraySprite_initWithTexture00
static int tolua_utils_GraySprite_initWithTexture00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"GraySprite",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCTexture2D",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const CCRect",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  GraySprite* self = (GraySprite*)  tolua_tousertype(tolua_S,1,0);
  CCTexture2D* pTexture = ((CCTexture2D*)  tolua_tousertype(tolua_S,2,0));
  const CCRect* rect = ((const CCRect*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'initWithTexture'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->initWithTexture(pTexture,*rect);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'initWithTexture'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  BlindSprite */
#ifndef TOLUA_DISABLE_tolua_utils_BlindSprite_new00
static int tolua_utils_BlindSprite_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"BlindSprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   BlindSprite* tolua_ret = (BlindSprite*)  Mtolua_new((BlindSprite)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"BlindSprite");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  BlindSprite */
#ifndef TOLUA_DISABLE_tolua_utils_BlindSprite_new00_local
static int tolua_utils_BlindSprite_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"BlindSprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   BlindSprite* tolua_ret = (BlindSprite*)  Mtolua_new((BlindSprite)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"BlindSprite");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  BlindSprite */
#ifndef TOLUA_DISABLE_tolua_utils_BlindSprite_delete00
static int tolua_utils_BlindSprite_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"BlindSprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  BlindSprite* self = (BlindSprite*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  BlindSprite */
#ifndef TOLUA_DISABLE_tolua_utils_BlindSprite_create00
static int tolua_utils_BlindSprite_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"BlindSprite",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCArray",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCArray* filelist = ((CCArray*)  tolua_tousertype(tolua_S,2,0));
  {
   BlindSprite* tolua_ret = (BlindSprite*)  BlindSprite::create(filelist);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"BlindSprite");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: initWithFile of class  BlindSprite */
#ifndef TOLUA_DISABLE_tolua_utils_BlindSprite_initWithFile00
static int tolua_utils_BlindSprite_initWithFile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"BlindSprite",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCArray",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  BlindSprite* self = (BlindSprite*)  tolua_tousertype(tolua_S,1,0);
  CCArray* filelist = ((CCArray*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'initWithFile'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->initWithFile(filelist);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'initWithFile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setSplitNum of class  BlindSprite */
#ifndef TOLUA_DISABLE_tolua_utils_BlindSprite_setSplitNum00
static int tolua_utils_BlindSprite_setSplitNum00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"BlindSprite",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  BlindSprite* self = (BlindSprite*)  tolua_tousertype(tolua_S,1,0);
  int num = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setSplitNum'", NULL);
#endif
  {
   self->setSplitNum(num);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setSplitNum'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setDuration of class  BlindSprite */
#ifndef TOLUA_DISABLE_tolua_utils_BlindSprite_setDuration00
static int tolua_utils_BlindSprite_setDuration00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"BlindSprite",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  BlindSprite* self = (BlindSprite*)  tolua_tousertype(tolua_S,1,0);
  float duration = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setDuration'", NULL);
#endif
  {
   self->setDuration(duration);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setDuration'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  BloomSprite */
#ifndef TOLUA_DISABLE_tolua_utils_BloomSprite_new00
static int tolua_utils_BloomSprite_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"BloomSprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   BloomSprite* tolua_ret = (BloomSprite*)  Mtolua_new((BloomSprite)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"BloomSprite");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  BloomSprite */
#ifndef TOLUA_DISABLE_tolua_utils_BloomSprite_new00_local
static int tolua_utils_BloomSprite_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"BloomSprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   BloomSprite* tolua_ret = (BloomSprite*)  Mtolua_new((BloomSprite)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"BloomSprite");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  BloomSprite */
#ifndef TOLUA_DISABLE_tolua_utils_BloomSprite_delete00
static int tolua_utils_BloomSprite_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"BloomSprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  BloomSprite* self = (BloomSprite*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  BloomSprite */
#ifndef TOLUA_DISABLE_tolua_utils_BloomSprite_create00
static int tolua_utils_BloomSprite_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"BloomSprite",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* filename = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   BloomSprite* tolua_ret = (BloomSprite*)  BloomSprite::create(filename);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"BloomSprite");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: initWithFile of class  BloomSprite */
#ifndef TOLUA_DISABLE_tolua_utils_BloomSprite_initWithFile00
static int tolua_utils_BloomSprite_initWithFile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"BloomSprite",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  BloomSprite* self = (BloomSprite*)  tolua_tousertype(tolua_S,1,0);
  const char* filename = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'initWithFile'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->initWithFile(filename);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'initWithFile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  BlurSprite */
#ifndef TOLUA_DISABLE_tolua_utils_BlurSprite_new00
static int tolua_utils_BlurSprite_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"BlurSprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   BlurSprite* tolua_ret = (BlurSprite*)  Mtolua_new((BlurSprite)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"BlurSprite");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  BlurSprite */
#ifndef TOLUA_DISABLE_tolua_utils_BlurSprite_new00_local
static int tolua_utils_BlurSprite_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"BlurSprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   BlurSprite* tolua_ret = (BlurSprite*)  Mtolua_new((BlurSprite)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"BlurSprite");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  BlurSprite */
#ifndef TOLUA_DISABLE_tolua_utils_BlurSprite_delete00
static int tolua_utils_BlurSprite_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"BlurSprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  BlurSprite* self = (BlurSprite*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  BlurSprite */
#ifndef TOLUA_DISABLE_tolua_utils_BlurSprite_create00
static int tolua_utils_BlurSprite_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"BlurSprite",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* filename = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   BlurSprite* tolua_ret = (BlurSprite*)  BlurSprite::create(filename);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"BlurSprite");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: createWithTexture of class  BlurSprite */
#ifndef TOLUA_DISABLE_tolua_utils_BlurSprite_createWithTexture00
static int tolua_utils_BlurSprite_createWithTexture00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"BlurSprite",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCTexture2D",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCTexture2D* pTexture = ((CCTexture2D*)  tolua_tousertype(tolua_S,2,0));
  {
   BlurSprite* tolua_ret = (BlurSprite*)  BlurSprite::createWithTexture(pTexture);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"BlurSprite");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'createWithTexture'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: initWithTexture of class  BlurSprite */
#ifndef TOLUA_DISABLE_tolua_utils_BlurSprite_initWithTexture00
static int tolua_utils_BlurSprite_initWithTexture00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"BlurSprite",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCTexture2D",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const CCRect",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  BlurSprite* self = (BlurSprite*)  tolua_tousertype(tolua_S,1,0);
  CCTexture2D* pTexture = ((CCTexture2D*)  tolua_tousertype(tolua_S,2,0));
  const CCRect* rect = ((const CCRect*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'initWithTexture'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->initWithTexture(pTexture,*rect);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'initWithTexture'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: initWithFile of class  BlurSprite */
#ifndef TOLUA_DISABLE_tolua_utils_BlurSprite_initWithFile00
static int tolua_utils_BlurSprite_initWithFile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"BlurSprite",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  BlurSprite* self = (BlurSprite*)  tolua_tousertype(tolua_S,1,0);
  const char* filename = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'initWithFile'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->initWithFile(filename);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'initWithFile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  FrostSprite */
#ifndef TOLUA_DISABLE_tolua_utils_FrostSprite_new00
static int tolua_utils_FrostSprite_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"FrostSprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   FrostSprite* tolua_ret = (FrostSprite*)  Mtolua_new((FrostSprite)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"FrostSprite");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  FrostSprite */
#ifndef TOLUA_DISABLE_tolua_utils_FrostSprite_new00_local
static int tolua_utils_FrostSprite_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"FrostSprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   FrostSprite* tolua_ret = (FrostSprite*)  Mtolua_new((FrostSprite)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"FrostSprite");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  FrostSprite */
#ifndef TOLUA_DISABLE_tolua_utils_FrostSprite_delete00
static int tolua_utils_FrostSprite_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FrostSprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FrostSprite* self = (FrostSprite*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  FrostSprite */
#ifndef TOLUA_DISABLE_tolua_utils_FrostSprite_create00
static int tolua_utils_FrostSprite_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"FrostSprite",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* filename = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   FrostSprite* tolua_ret = (FrostSprite*)  FrostSprite::create(filename);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"FrostSprite");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: initWithFile of class  FrostSprite */
#ifndef TOLUA_DISABLE_tolua_utils_FrostSprite_initWithFile00
static int tolua_utils_FrostSprite_initWithFile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"FrostSprite",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  FrostSprite* self = (FrostSprite*)  tolua_tousertype(tolua_S,1,0);
  const char* filename = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'initWithFile'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->initWithFile(filename);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'initWithFile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  HueSprite */
#ifndef TOLUA_DISABLE_tolua_utils_HueSprite_new00
static int tolua_utils_HueSprite_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"HueSprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   HueSprite* tolua_ret = (HueSprite*)  Mtolua_new((HueSprite)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"HueSprite");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  HueSprite */
#ifndef TOLUA_DISABLE_tolua_utils_HueSprite_new00_local
static int tolua_utils_HueSprite_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"HueSprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   HueSprite* tolua_ret = (HueSprite*)  Mtolua_new((HueSprite)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"HueSprite");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  HueSprite */
#ifndef TOLUA_DISABLE_tolua_utils_HueSprite_delete00
static int tolua_utils_HueSprite_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"HueSprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  HueSprite* self = (HueSprite*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  HueSprite */
#ifndef TOLUA_DISABLE_tolua_utils_HueSprite_create00
static int tolua_utils_HueSprite_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"HueSprite",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* filename = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   HueSprite* tolua_ret = (HueSprite*)  HueSprite::create(filename);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"HueSprite");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: initWithFile of class  HueSprite */
#ifndef TOLUA_DISABLE_tolua_utils_HueSprite_initWithFile00
static int tolua_utils_HueSprite_initWithFile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"HueSprite",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  HueSprite* self = (HueSprite*)  tolua_tousertype(tolua_S,1,0);
  const char* filename = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'initWithFile'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->initWithFile(filename);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'initWithFile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setHue of class  HueSprite */
#ifndef TOLUA_DISABLE_tolua_utils_HueSprite_setHue00
static int tolua_utils_HueSprite_setHue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"HueSprite",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  HueSprite* self = (HueSprite*)  tolua_tousertype(tolua_S,1,0);
  float hue = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setHue'", NULL);
#endif
  {
   self->setHue(hue);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setHue'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getHue of class  HueSprite */
#ifndef TOLUA_DISABLE_tolua_utils_HueSprite_getHue00
static int tolua_utils_HueSprite_getHue00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"HueSprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  HueSprite* self = (HueSprite*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getHue'", NULL);
#endif
  {
   float tolua_ret = (float)  self->getHue();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getHue'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  LaserSprite */
#ifndef TOLUA_DISABLE_tolua_utils_LaserSprite_new00
static int tolua_utils_LaserSprite_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LaserSprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   LaserSprite* tolua_ret = (LaserSprite*)  Mtolua_new((LaserSprite)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"LaserSprite");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  LaserSprite */
#ifndef TOLUA_DISABLE_tolua_utils_LaserSprite_new00_local
static int tolua_utils_LaserSprite_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LaserSprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   LaserSprite* tolua_ret = (LaserSprite*)  Mtolua_new((LaserSprite)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"LaserSprite");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  LaserSprite */
#ifndef TOLUA_DISABLE_tolua_utils_LaserSprite_delete00
static int tolua_utils_LaserSprite_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LaserSprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LaserSprite* self = (LaserSprite*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  LaserSprite */
#ifndef TOLUA_DISABLE_tolua_utils_LaserSprite_create00
static int tolua_utils_LaserSprite_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"LaserSprite",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* filename = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   LaserSprite* tolua_ret = (LaserSprite*)  LaserSprite::create(filename);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"LaserSprite");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: initWithFile of class  LaserSprite */
#ifndef TOLUA_DISABLE_tolua_utils_LaserSprite_initWithFile00
static int tolua_utils_LaserSprite_initWithFile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"LaserSprite",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LaserSprite* self = (LaserSprite*)  tolua_tousertype(tolua_S,1,0);
  const char* filename = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'initWithFile'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->initWithFile(filename);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'initWithFile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: pos of class  SpotLight */
#ifndef TOLUA_DISABLE_tolua_get_SpotLight_pos
static int tolua_get_SpotLight_pos(lua_State* tolua_S)
{
  SpotLight* self = (SpotLight*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'pos'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->pos,"ccVertex3F");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: pos of class  SpotLight */
#ifndef TOLUA_DISABLE_tolua_set_SpotLight_pos
static int tolua_set_SpotLight_pos(lua_State* tolua_S)
{
  SpotLight* self = (SpotLight*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'pos'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"ccVertex3F",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->pos = *((ccVertex3F*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: diffuse of class  SpotLight */
#ifndef TOLUA_DISABLE_tolua_get_SpotLight_diffuse
static int tolua_get_SpotLight_diffuse(lua_State* tolua_S)
{
  SpotLight* self = (SpotLight*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'diffuse'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->diffuse,"ccColor4F");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: diffuse of class  SpotLight */
#ifndef TOLUA_DISABLE_tolua_set_SpotLight_diffuse
static int tolua_set_SpotLight_diffuse(lua_State* tolua_S)
{
  SpotLight* self = (SpotLight*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'diffuse'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"ccColor4F",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->diffuse = *((ccColor4F*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  SpotLight */
#ifndef TOLUA_DISABLE_tolua_utils_SpotLight_new00
static int tolua_utils_SpotLight_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"SpotLight",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   SpotLight* tolua_ret = (SpotLight*)  Mtolua_new((SpotLight)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"SpotLight");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  SpotLight */
#ifndef TOLUA_DISABLE_tolua_utils_SpotLight_new00_local
static int tolua_utils_SpotLight_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"SpotLight",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   SpotLight* tolua_ret = (SpotLight*)  Mtolua_new((SpotLight)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"SpotLight");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  NormalSprite */
#ifndef TOLUA_DISABLE_tolua_utils_NormalSprite_new00
static int tolua_utils_NormalSprite_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"NormalSprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   NormalSprite* tolua_ret = (NormalSprite*)  Mtolua_new((NormalSprite)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"NormalSprite");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  NormalSprite */
#ifndef TOLUA_DISABLE_tolua_utils_NormalSprite_new00_local
static int tolua_utils_NormalSprite_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"NormalSprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   NormalSprite* tolua_ret = (NormalSprite*)  Mtolua_new((NormalSprite)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"NormalSprite");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  NormalSprite */
#ifndef TOLUA_DISABLE_tolua_utils_NormalSprite_delete00
static int tolua_utils_NormalSprite_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NormalSprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NormalSprite* self = (NormalSprite*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  NormalSprite */
#ifndef TOLUA_DISABLE_tolua_utils_NormalSprite_create00
static int tolua_utils_NormalSprite_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"NormalSprite",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* filename = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* normalmap = ((const char*)  tolua_tostring(tolua_S,3,0));
  {
   NormalSprite* tolua_ret = (NormalSprite*)  NormalSprite::create(filename,normalmap);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"NormalSprite");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: initWithFile of class  NormalSprite */
#ifndef TOLUA_DISABLE_tolua_utils_NormalSprite_initWithFile00
static int tolua_utils_NormalSprite_initWithFile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NormalSprite",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NormalSprite* self = (NormalSprite*)  tolua_tousertype(tolua_S,1,0);
  const char* filename = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* normalmap = ((const char*)  tolua_tostring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'initWithFile'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->initWithFile(filename,normalmap);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'initWithFile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setLight of class  NormalSprite */
#ifndef TOLUA_DISABLE_tolua_utils_NormalSprite_setLight00
static int tolua_utils_NormalSprite_setLight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NormalSprite",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"SpotLight",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NormalSprite* self = (NormalSprite*)  tolua_tousertype(tolua_S,1,0);
  SpotLight light = *((SpotLight*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setLight'", NULL);
#endif
  {
   self->setLight(light);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setLight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setLightPos of class  NormalSprite */
#ifndef TOLUA_DISABLE_tolua_utils_NormalSprite_setLightPos00
static int tolua_utils_NormalSprite_setLightPos00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NormalSprite",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CCPoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NormalSprite* self = (NormalSprite*)  tolua_tousertype(tolua_S,1,0);
  CCPoint pos = *((CCPoint*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setLightPos'", NULL);
#endif
  {
   self->setLightPos(pos);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setLightPos'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setLightColor of class  NormalSprite */
#ifndef TOLUA_DISABLE_tolua_utils_NormalSprite_setLightColor00
static int tolua_utils_NormalSprite_setLightColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"NormalSprite",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"ccColor3B",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  NormalSprite* self = (NormalSprite*)  tolua_tousertype(tolua_S,1,0);
  ccColor3B color = *((ccColor3B*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setLightColor'", NULL);
#endif
  {
   self->setLightColor(color);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setLightColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  RippleSprite */
#ifndef TOLUA_DISABLE_tolua_utils_RippleSprite_new00
static int tolua_utils_RippleSprite_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"RippleSprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   RippleSprite* tolua_ret = (RippleSprite*)  Mtolua_new((RippleSprite)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"RippleSprite");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  RippleSprite */
#ifndef TOLUA_DISABLE_tolua_utils_RippleSprite_new00_local
static int tolua_utils_RippleSprite_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"RippleSprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   RippleSprite* tolua_ret = (RippleSprite*)  Mtolua_new((RippleSprite)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"RippleSprite");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  RippleSprite */
#ifndef TOLUA_DISABLE_tolua_utils_RippleSprite_delete00
static int tolua_utils_RippleSprite_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"RippleSprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  RippleSprite* self = (RippleSprite*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  RippleSprite */
#ifndef TOLUA_DISABLE_tolua_utils_RippleSprite_create00
static int tolua_utils_RippleSprite_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"RippleSprite",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* filename = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   RippleSprite* tolua_ret = (RippleSprite*)  RippleSprite::create(filename);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"RippleSprite");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: initWithFile of class  RippleSprite */
#ifndef TOLUA_DISABLE_tolua_utils_RippleSprite_initWithFile00
static int tolua_utils_RippleSprite_initWithFile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"RippleSprite",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  RippleSprite* self = (RippleSprite*)  tolua_tousertype(tolua_S,1,0);
  const char* filename = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'initWithFile'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->initWithFile(filename);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'initWithFile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setTile of class  RippleSprite */
#ifndef TOLUA_DISABLE_tolua_utils_RippleSprite_setTile00
static int tolua_utils_RippleSprite_setTile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"RippleSprite",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  RippleSprite* self = (RippleSprite*)  tolua_tousertype(tolua_S,1,0);
  float tile = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTile'", NULL);
#endif
  {
   self->setTile(tile);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setTile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setNoiseFactor of class  RippleSprite */
#ifndef TOLUA_DISABLE_tolua_utils_RippleSprite_setNoiseFactor00
static int tolua_utils_RippleSprite_setNoiseFactor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"RippleSprite",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  RippleSprite* self = (RippleSprite*)  tolua_tousertype(tolua_S,1,0);
  float factor = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setNoiseFactor'", NULL);
#endif
  {
   self->setNoiseFactor(factor);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setNoiseFactor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setSpeed of class  RippleSprite */
#ifndef TOLUA_DISABLE_tolua_utils_RippleSprite_setSpeed00
static int tolua_utils_RippleSprite_setSpeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"RippleSprite",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  RippleSprite* self = (RippleSprite*)  tolua_tousertype(tolua_S,1,0);
  float speed = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setSpeed'", NULL);
#endif
  {
   self->setSpeed(speed);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setSpeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  StreamSprite */
#ifndef TOLUA_DISABLE_tolua_utils_StreamSprite_new00
static int tolua_utils_StreamSprite_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"StreamSprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   StreamSprite* tolua_ret = (StreamSprite*)  Mtolua_new((StreamSprite)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"StreamSprite");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  StreamSprite */
#ifndef TOLUA_DISABLE_tolua_utils_StreamSprite_new00_local
static int tolua_utils_StreamSprite_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"StreamSprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   StreamSprite* tolua_ret = (StreamSprite*)  Mtolua_new((StreamSprite)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"StreamSprite");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  StreamSprite */
#ifndef TOLUA_DISABLE_tolua_utils_StreamSprite_delete00
static int tolua_utils_StreamSprite_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"StreamSprite",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  StreamSprite* self = (StreamSprite*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  StreamSprite */
#ifndef TOLUA_DISABLE_tolua_utils_StreamSprite_create00
static int tolua_utils_StreamSprite_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"StreamSprite",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* filename = ((const char*)  tolua_tostring(tolua_S,2,0));
  {
   StreamSprite* tolua_ret = (StreamSprite*)  StreamSprite::create(filename);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"StreamSprite");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: initWithFile of class  StreamSprite */
#ifndef TOLUA_DISABLE_tolua_utils_StreamSprite_initWithFile00
static int tolua_utils_StreamSprite_initWithFile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"StreamSprite",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  StreamSprite* self = (StreamSprite*)  tolua_tousertype(tolua_S,1,0);
  const char* filename = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'initWithFile'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->initWithFile(filename);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'initWithFile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  VEScrollView */
#ifndef TOLUA_DISABLE_tolua_utils_VEScrollView_create00
static int tolua_utils_VEScrollView_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"VEScrollView",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   VEScrollView* tolua_ret = (VEScrollView*)  VEScrollView::create();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"VEScrollView");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: init of class  VEScrollView */
#ifndef TOLUA_DISABLE_tolua_utils_VEScrollView_init00
static int tolua_utils_VEScrollView_init00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"VEScrollView",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  VEScrollView* self = (VEScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'init'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->init();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'init'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setType of class  VEScrollView */
#ifndef TOLUA_DISABLE_tolua_utils_VEScrollView_setType00
static int tolua_utils_VEScrollView_setType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"VEScrollView",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  VEScrollView* self = (VEScrollView*)  tolua_tousertype(tolua_S,1,0);
  ScrollViewType type = ((ScrollViewType) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setType'", NULL);
#endif
  {
   self->setType(type);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getType of class  VEScrollView */
#ifndef TOLUA_DISABLE_tolua_utils_VEScrollView_getType00
static int tolua_utils_VEScrollView_getType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const VEScrollView",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const VEScrollView* self = (const VEScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getType'", NULL);
#endif
  {
   ScrollViewType tolua_ret = (ScrollViewType)  self->getType();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setViewSize of class  VEScrollView */
#ifndef TOLUA_DISABLE_tolua_utils_VEScrollView_setViewSize00
static int tolua_utils_VEScrollView_setViewSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"VEScrollView",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CCSize",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  VEScrollView* self = (VEScrollView*)  tolua_tousertype(tolua_S,1,0);
  CCSize size = *((CCSize*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setViewSize'", NULL);
#endif
  {
   self->setViewSize(size);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setViewSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getViewSize of class  VEScrollView */
#ifndef TOLUA_DISABLE_tolua_utils_VEScrollView_getViewSize00
static int tolua_utils_VEScrollView_getViewSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const VEScrollView",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const VEScrollView* self = (const VEScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getViewSize'", NULL);
#endif
  {
   CCSize tolua_ret = (CCSize)  self->getViewSize();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((CCSize)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"CCSize");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CCSize));
     tolua_pushusertype(tolua_S,tolua_obj,"CCSize");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getViewSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ccTouchBegan of class  VEScrollView */
#ifndef TOLUA_DISABLE_tolua_utils_VEScrollView_ccTouchBegan00
static int tolua_utils_VEScrollView_ccTouchBegan00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"VEScrollView",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCTouch",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"CCEvent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  VEScrollView* self = (VEScrollView*)  tolua_tousertype(tolua_S,1,0);
  CCTouch* pTouch = ((CCTouch*)  tolua_tousertype(tolua_S,2,0));
  CCEvent* pEvent = ((CCEvent*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ccTouchBegan'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->ccTouchBegan(pTouch,pEvent);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ccTouchBegan'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ccTouchMoved of class  VEScrollView */
#ifndef TOLUA_DISABLE_tolua_utils_VEScrollView_ccTouchMoved00
static int tolua_utils_VEScrollView_ccTouchMoved00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"VEScrollView",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCTouch",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"CCEvent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  VEScrollView* self = (VEScrollView*)  tolua_tousertype(tolua_S,1,0);
  CCTouch* pTouch = ((CCTouch*)  tolua_tousertype(tolua_S,2,0));
  CCEvent* pEvent = ((CCEvent*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ccTouchMoved'", NULL);
#endif
  {
   self->ccTouchMoved(pTouch,pEvent);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ccTouchMoved'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ccTouchEnded of class  VEScrollView */
#ifndef TOLUA_DISABLE_tolua_utils_VEScrollView_ccTouchEnded00
static int tolua_utils_VEScrollView_ccTouchEnded00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"VEScrollView",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCTouch",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"CCEvent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  VEScrollView* self = (VEScrollView*)  tolua_tousertype(tolua_S,1,0);
  CCTouch* pTouch = ((CCTouch*)  tolua_tousertype(tolua_S,2,0));
  CCEvent* pEvent = ((CCEvent*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ccTouchEnded'", NULL);
#endif
  {
   self->ccTouchEnded(pTouch,pEvent);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ccTouchEnded'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ccTouchesBegan of class  VEScrollView */
#ifndef TOLUA_DISABLE_tolua_utils_VEScrollView_ccTouchesBegan00
static int tolua_utils_VEScrollView_ccTouchesBegan00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"VEScrollView",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCSet",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"CCEvent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  VEScrollView* self = (VEScrollView*)  tolua_tousertype(tolua_S,1,0);
  CCSet* pTouches = ((CCSet*)  tolua_tousertype(tolua_S,2,0));
  CCEvent* pEvent = ((CCEvent*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ccTouchesBegan'", NULL);
#endif
  {
   self->ccTouchesBegan(pTouches,pEvent);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ccTouchesBegan'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ccTouchesMoved of class  VEScrollView */
#ifndef TOLUA_DISABLE_tolua_utils_VEScrollView_ccTouchesMoved00
static int tolua_utils_VEScrollView_ccTouchesMoved00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"VEScrollView",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCSet",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"CCEvent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  VEScrollView* self = (VEScrollView*)  tolua_tousertype(tolua_S,1,0);
  CCSet* pTouches = ((CCSet*)  tolua_tousertype(tolua_S,2,0));
  CCEvent* pEvent = ((CCEvent*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ccTouchesMoved'", NULL);
#endif
  {
   self->ccTouchesMoved(pTouches,pEvent);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ccTouchesMoved'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ccTouchesEnded of class  VEScrollView */
#ifndef TOLUA_DISABLE_tolua_utils_VEScrollView_ccTouchesEnded00
static int tolua_utils_VEScrollView_ccTouchesEnded00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"VEScrollView",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCSet",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"CCEvent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  VEScrollView* self = (VEScrollView*)  tolua_tousertype(tolua_S,1,0);
  CCSet* pTouches = ((CCSet*)  tolua_tousertype(tolua_S,2,0));
  CCEvent* pEvent = ((CCEvent*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ccTouchesEnded'", NULL);
#endif
  {
   self->ccTouchesEnded(pTouches,pEvent);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ccTouchesEnded'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: visit of class  VEScrollView */
#ifndef TOLUA_DISABLE_tolua_utils_VEScrollView_visit00
static int tolua_utils_VEScrollView_visit00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"VEScrollView",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  VEScrollView* self = (VEScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'visit'", NULL);
#endif
  {
   self->visit();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'visit'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: boundingBox of class  VEScrollView */
#ifndef TOLUA_DISABLE_tolua_utils_VEScrollView_boundingBox00
static int tolua_utils_VEScrollView_boundingBox00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"VEScrollView",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  VEScrollView* self = (VEScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'boundingBox'", NULL);
#endif
  {
   CCRect tolua_ret = (CCRect)  self->boundingBox();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((CCRect)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"CCRect");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CCRect));
     tolua_pushusertype(tolua_S,tolua_obj,"CCRect");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'boundingBox'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setTouchEnabled of class  VEScrollView */
#ifndef TOLUA_DISABLE_tolua_utils_VEScrollView_setTouchEnabled00
static int tolua_utils_VEScrollView_setTouchEnabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"VEScrollView",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  VEScrollView* self = (VEScrollView*)  tolua_tousertype(tolua_S,1,0);
  bool val = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTouchEnabled'", NULL);
#endif
  {
   self->setTouchEnabled(val);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setTouchEnabled'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getTouchEnabled of class  VEScrollView */
#ifndef TOLUA_DISABLE_tolua_utils_VEScrollView_getTouchEnabled00
static int tolua_utils_VEScrollView_getTouchEnabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const VEScrollView",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const VEScrollView* self = (const VEScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getTouchEnabled'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->getTouchEnabled();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getTouchEnabled'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getContentOffset of class  VEScrollView */
#ifndef TOLUA_DISABLE_tolua_utils_VEScrollView_getContentOffset00
static int tolua_utils_VEScrollView_getContentOffset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const VEScrollView",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const VEScrollView* self = (const VEScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getContentOffset'", NULL);
#endif
  {
   CCPoint tolua_ret = (CCPoint)  self->getContentOffset();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((CCPoint)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"CCPoint");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(CCPoint));
     tolua_pushusertype(tolua_S,tolua_obj,"CCPoint");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getContentOffset'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setContentOffset of class  VEScrollView */
#ifndef TOLUA_DISABLE_tolua_utils_VEScrollView_setContentOffset00
static int tolua_utils_VEScrollView_setContentOffset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"VEScrollView",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CCPoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  VEScrollView* self = (VEScrollView*)  tolua_tousertype(tolua_S,1,0);
  CCPoint offset = *((CCPoint*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setContentOffset'", NULL);
#endif
  {
   self->setContentOffset(offset);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setContentOffset'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addCell of class  VEScrollView */
#ifndef TOLUA_DISABLE_tolua_utils_VEScrollView_addCell00
static int tolua_utils_VEScrollView_addCell00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"VEScrollView",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  VEScrollView* self = (VEScrollView*)  tolua_tousertype(tolua_S,1,0);
  CCNode* cell = ((CCNode*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addCell'", NULL);
#endif
  {
   self->addCell(cell);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addCell'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeCell of class  VEScrollView */
#ifndef TOLUA_DISABLE_tolua_utils_VEScrollView_removeCell00
static int tolua_utils_VEScrollView_removeCell00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"VEScrollView",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  VEScrollView* self = (VEScrollView*)  tolua_tousertype(tolua_S,1,0);
  CCNode* cell = ((CCNode*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeCell'", NULL);
#endif
  {
   self->removeCell(cell);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeCell'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeAllCells of class  VEScrollView */
#ifndef TOLUA_DISABLE_tolua_utils_VEScrollView_removeAllCells00
static int tolua_utils_VEScrollView_removeAllCells00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"VEScrollView",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  VEScrollView* self = (VEScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeAllCells'", NULL);
#endif
  {
   self->removeAllCells();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeAllCells'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAllCells of class  VEScrollView */
#ifndef TOLUA_DISABLE_tolua_utils_VEScrollView_getAllCells00
static int tolua_utils_VEScrollView_getAllCells00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"VEScrollView",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  VEScrollView* self = (VEScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAllCells'", NULL);
#endif
  {
   CCArray* tolua_ret = (CCArray*)  self->getAllCells();
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCArray");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAllCells'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addTouchHandler of class  VEScrollView */
#ifndef TOLUA_DISABLE_tolua_utils_VEScrollView_addTouchHandler00
static int tolua_utils_VEScrollView_addTouchHandler00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"VEScrollView",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCObject",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"scroll_touch",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  VEScrollView* self = (VEScrollView*)  tolua_tousertype(tolua_S,1,0);
  CCObject* listener = ((CCObject*)  tolua_tousertype(tolua_S,2,0));
  scroll_touch callback = *((scroll_touch*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addTouchHandler'", NULL);
#endif
  {
   self->addTouchHandler(listener,callback);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addTouchHandler'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: touchCheck of class  VEScrollView */
#ifndef TOLUA_DISABLE_tolua_utils_VEScrollView_touchCheck00
static int tolua_utils_VEScrollView_touchCheck00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"VEScrollView",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CCPoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  VEScrollView* self = (VEScrollView*)  tolua_tousertype(tolua_S,1,0);
  CCPoint touchPoint = *((CCPoint*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'touchCheck'", NULL);
#endif
  {
   CCNode* tolua_ret = (CCNode*)  self->touchCheck(touchPoint);
    int nID = (tolua_ret) ? (int)tolua_ret->m_uID : -1;
    int* pLuaID = (tolua_ret) ? &tolua_ret->m_nLuaID : NULL;
    toluafix_pushusertype_ccobject(tolua_S, nID, pLuaID, (void*)tolua_ret,"CCNode");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'touchCheck'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_utils_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_cclass(tolua_S,"FileSystem","FileSystem","",NULL);
  tolua_beginmodule(tolua_S,"FileSystem");
   tolua_function(tolua_S,"getInstance",tolua_utils_FileSystem_getInstance00);
   tolua_function(tolua_S,"getFileData",tolua_utils_FileSystem_getFileData00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"ShaderManager","ShaderManager","CCObject",NULL);
  tolua_beginmodule(tolua_S,"ShaderManager");
   tolua_function(tolua_S,"getInstance",tolua_utils_ShaderManager_getInstance00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"ColorSprite","ColorSprite","CCSprite",NULL);
  tolua_beginmodule(tolua_S,"ColorSprite");
   tolua_function(tolua_S,"create",tolua_utils_ColorSprite_create00);
   tolua_function(tolua_S,"createWithTexture",tolua_utils_ColorSprite_createWithTexture00);
   tolua_function(tolua_S,"initWithFile",tolua_utils_ColorSprite_initWithFile00);
   tolua_function(tolua_S,"initWithTexture",tolua_utils_ColorSprite_initWithTexture00);
   tolua_function(tolua_S,"setColor",tolua_utils_ColorSprite_setColor00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"GraySprite","GraySprite","CCSprite",NULL);
  tolua_beginmodule(tolua_S,"GraySprite");
   tolua_function(tolua_S,"create",tolua_utils_GraySprite_create00);
   tolua_function(tolua_S,"createWithTexture",tolua_utils_GraySprite_createWithTexture00);
   tolua_function(tolua_S,"initWithFile",tolua_utils_GraySprite_initWithFile00);
   tolua_function(tolua_S,"initWithTexture",tolua_utils_GraySprite_initWithTexture00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"BlindSprite","BlindSprite","CCSprite",tolua_collect_BlindSprite);
  #else
  tolua_cclass(tolua_S,"BlindSprite","BlindSprite","CCSprite",NULL);
  #endif
  tolua_beginmodule(tolua_S,"BlindSprite");
   tolua_function(tolua_S,"new",tolua_utils_BlindSprite_new00);
   tolua_function(tolua_S,"new_local",tolua_utils_BlindSprite_new00_local);
   tolua_function(tolua_S,".call",tolua_utils_BlindSprite_new00_local);
   tolua_function(tolua_S,"delete",tolua_utils_BlindSprite_delete00);
   tolua_function(tolua_S,"create",tolua_utils_BlindSprite_create00);
   tolua_function(tolua_S,"initWithFile",tolua_utils_BlindSprite_initWithFile00);
   tolua_function(tolua_S,"setSplitNum",tolua_utils_BlindSprite_setSplitNum00);
   tolua_function(tolua_S,"setDuration",tolua_utils_BlindSprite_setDuration00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"BloomSprite","BloomSprite","CCSprite",tolua_collect_BloomSprite);
  #else
  tolua_cclass(tolua_S,"BloomSprite","BloomSprite","CCSprite",NULL);
  #endif
  tolua_beginmodule(tolua_S,"BloomSprite");
   tolua_function(tolua_S,"new",tolua_utils_BloomSprite_new00);
   tolua_function(tolua_S,"new_local",tolua_utils_BloomSprite_new00_local);
   tolua_function(tolua_S,".call",tolua_utils_BloomSprite_new00_local);
   tolua_function(tolua_S,"delete",tolua_utils_BloomSprite_delete00);
   tolua_function(tolua_S,"create",tolua_utils_BloomSprite_create00);
   tolua_function(tolua_S,"initWithFile",tolua_utils_BloomSprite_initWithFile00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"BlurSprite","BlurSprite","CCSprite",tolua_collect_BlurSprite);
  #else
  tolua_cclass(tolua_S,"BlurSprite","BlurSprite","CCSprite",NULL);
  #endif
  tolua_beginmodule(tolua_S,"BlurSprite");
   tolua_function(tolua_S,"new",tolua_utils_BlurSprite_new00);
   tolua_function(tolua_S,"new_local",tolua_utils_BlurSprite_new00_local);
   tolua_function(tolua_S,".call",tolua_utils_BlurSprite_new00_local);
   tolua_function(tolua_S,"delete",tolua_utils_BlurSprite_delete00);
   tolua_function(tolua_S,"create",tolua_utils_BlurSprite_create00);
   tolua_function(tolua_S,"createWithTexture",tolua_utils_BlurSprite_createWithTexture00);
   tolua_function(tolua_S,"initWithTexture",tolua_utils_BlurSprite_initWithTexture00);
   tolua_function(tolua_S,"initWithFile",tolua_utils_BlurSprite_initWithFile00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"FrostSprite","FrostSprite","CCSprite",tolua_collect_FrostSprite);
  #else
  tolua_cclass(tolua_S,"FrostSprite","FrostSprite","CCSprite",NULL);
  #endif
  tolua_beginmodule(tolua_S,"FrostSprite");
   tolua_function(tolua_S,"new",tolua_utils_FrostSprite_new00);
   tolua_function(tolua_S,"new_local",tolua_utils_FrostSprite_new00_local);
   tolua_function(tolua_S,".call",tolua_utils_FrostSprite_new00_local);
   tolua_function(tolua_S,"delete",tolua_utils_FrostSprite_delete00);
   tolua_function(tolua_S,"create",tolua_utils_FrostSprite_create00);
   tolua_function(tolua_S,"initWithFile",tolua_utils_FrostSprite_initWithFile00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"HueSprite","HueSprite","CCSprite",tolua_collect_HueSprite);
  #else
  tolua_cclass(tolua_S,"HueSprite","HueSprite","CCSprite",NULL);
  #endif
  tolua_beginmodule(tolua_S,"HueSprite");
   tolua_function(tolua_S,"new",tolua_utils_HueSprite_new00);
   tolua_function(tolua_S,"new_local",tolua_utils_HueSprite_new00_local);
   tolua_function(tolua_S,".call",tolua_utils_HueSprite_new00_local);
   tolua_function(tolua_S,"delete",tolua_utils_HueSprite_delete00);
   tolua_function(tolua_S,"create",tolua_utils_HueSprite_create00);
   tolua_function(tolua_S,"initWithFile",tolua_utils_HueSprite_initWithFile00);
   tolua_function(tolua_S,"setHue",tolua_utils_HueSprite_setHue00);
   tolua_function(tolua_S,"getHue",tolua_utils_HueSprite_getHue00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"LaserSprite","LaserSprite","CCSprite",tolua_collect_LaserSprite);
  #else
  tolua_cclass(tolua_S,"LaserSprite","LaserSprite","CCSprite",NULL);
  #endif
  tolua_beginmodule(tolua_S,"LaserSprite");
   tolua_function(tolua_S,"new",tolua_utils_LaserSprite_new00);
   tolua_function(tolua_S,"new_local",tolua_utils_LaserSprite_new00_local);
   tolua_function(tolua_S,".call",tolua_utils_LaserSprite_new00_local);
   tolua_function(tolua_S,"delete",tolua_utils_LaserSprite_delete00);
   tolua_function(tolua_S,"create",tolua_utils_LaserSprite_create00);
   tolua_function(tolua_S,"initWithFile",tolua_utils_LaserSprite_initWithFile00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"SpotLight","SpotLight","",tolua_collect_SpotLight);
  #else
  tolua_cclass(tolua_S,"SpotLight","SpotLight","",NULL);
  #endif
  tolua_beginmodule(tolua_S,"SpotLight");
   tolua_variable(tolua_S,"pos",tolua_get_SpotLight_pos,tolua_set_SpotLight_pos);
   tolua_variable(tolua_S,"diffuse",tolua_get_SpotLight_diffuse,tolua_set_SpotLight_diffuse);
   tolua_function(tolua_S,"new",tolua_utils_SpotLight_new00);
   tolua_function(tolua_S,"new_local",tolua_utils_SpotLight_new00_local);
   tolua_function(tolua_S,".call",tolua_utils_SpotLight_new00_local);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"NormalSprite","NormalSprite","CCSprite",tolua_collect_NormalSprite);
  #else
  tolua_cclass(tolua_S,"NormalSprite","NormalSprite","CCSprite",NULL);
  #endif
  tolua_beginmodule(tolua_S,"NormalSprite");
   tolua_function(tolua_S,"new",tolua_utils_NormalSprite_new00);
   tolua_function(tolua_S,"new_local",tolua_utils_NormalSprite_new00_local);
   tolua_function(tolua_S,".call",tolua_utils_NormalSprite_new00_local);
   tolua_function(tolua_S,"delete",tolua_utils_NormalSprite_delete00);
   tolua_function(tolua_S,"create",tolua_utils_NormalSprite_create00);
   tolua_function(tolua_S,"initWithFile",tolua_utils_NormalSprite_initWithFile00);
   tolua_function(tolua_S,"setLight",tolua_utils_NormalSprite_setLight00);
   tolua_function(tolua_S,"setLightPos",tolua_utils_NormalSprite_setLightPos00);
   tolua_function(tolua_S,"setLightColor",tolua_utils_NormalSprite_setLightColor00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"RippleSprite","RippleSprite","CCSprite",tolua_collect_RippleSprite);
  #else
  tolua_cclass(tolua_S,"RippleSprite","RippleSprite","CCSprite",NULL);
  #endif
  tolua_beginmodule(tolua_S,"RippleSprite");
   tolua_function(tolua_S,"new",tolua_utils_RippleSprite_new00);
   tolua_function(tolua_S,"new_local",tolua_utils_RippleSprite_new00_local);
   tolua_function(tolua_S,".call",tolua_utils_RippleSprite_new00_local);
   tolua_function(tolua_S,"delete",tolua_utils_RippleSprite_delete00);
   tolua_function(tolua_S,"create",tolua_utils_RippleSprite_create00);
   tolua_function(tolua_S,"initWithFile",tolua_utils_RippleSprite_initWithFile00);
   tolua_function(tolua_S,"setTile",tolua_utils_RippleSprite_setTile00);
   tolua_function(tolua_S,"setNoiseFactor",tolua_utils_RippleSprite_setNoiseFactor00);
   tolua_function(tolua_S,"setSpeed",tolua_utils_RippleSprite_setSpeed00);
  tolua_endmodule(tolua_S);
  #ifdef __cplusplus
  tolua_cclass(tolua_S,"StreamSprite","StreamSprite","CCSprite",tolua_collect_StreamSprite);
  #else
  tolua_cclass(tolua_S,"StreamSprite","StreamSprite","CCSprite",NULL);
  #endif
  tolua_beginmodule(tolua_S,"StreamSprite");
   tolua_function(tolua_S,"new",tolua_utils_StreamSprite_new00);
   tolua_function(tolua_S,"new_local",tolua_utils_StreamSprite_new00_local);
   tolua_function(tolua_S,".call",tolua_utils_StreamSprite_new00_local);
   tolua_function(tolua_S,"delete",tolua_utils_StreamSprite_delete00);
   tolua_function(tolua_S,"create",tolua_utils_StreamSprite_create00);
   tolua_function(tolua_S,"initWithFile",tolua_utils_StreamSprite_initWithFile00);
  tolua_endmodule(tolua_S);
  tolua_constant(tolua_S,"SCROLLVIEW_NONE",SCROLLVIEW_NONE);
  tolua_constant(tolua_S,"SCROLLVIEW_HORIZONTAL",SCROLLVIEW_HORIZONTAL);
  tolua_constant(tolua_S,"SCROLLVIEW_VERTICAL",SCROLLVIEW_VERTICAL);
  tolua_cclass(tolua_S,"VEScrollView","VEScrollView","CCLayer",NULL);
  tolua_beginmodule(tolua_S,"VEScrollView");
   tolua_function(tolua_S,"create",tolua_utils_VEScrollView_create00);
   tolua_function(tolua_S,"init",tolua_utils_VEScrollView_init00);
   tolua_function(tolua_S,"setType",tolua_utils_VEScrollView_setType00);
   tolua_function(tolua_S,"getType",tolua_utils_VEScrollView_getType00);
   tolua_function(tolua_S,"setViewSize",tolua_utils_VEScrollView_setViewSize00);
   tolua_function(tolua_S,"getViewSize",tolua_utils_VEScrollView_getViewSize00);
   tolua_function(tolua_S,"ccTouchBegan",tolua_utils_VEScrollView_ccTouchBegan00);
   tolua_function(tolua_S,"ccTouchMoved",tolua_utils_VEScrollView_ccTouchMoved00);
   tolua_function(tolua_S,"ccTouchEnded",tolua_utils_VEScrollView_ccTouchEnded00);
   tolua_function(tolua_S,"ccTouchesBegan",tolua_utils_VEScrollView_ccTouchesBegan00);
   tolua_function(tolua_S,"ccTouchesMoved",tolua_utils_VEScrollView_ccTouchesMoved00);
   tolua_function(tolua_S,"ccTouchesEnded",tolua_utils_VEScrollView_ccTouchesEnded00);
   tolua_function(tolua_S,"visit",tolua_utils_VEScrollView_visit00);
   tolua_function(tolua_S,"boundingBox",tolua_utils_VEScrollView_boundingBox00);
   tolua_function(tolua_S,"setTouchEnabled",tolua_utils_VEScrollView_setTouchEnabled00);
   tolua_function(tolua_S,"getTouchEnabled",tolua_utils_VEScrollView_getTouchEnabled00);
   tolua_function(tolua_S,"getContentOffset",tolua_utils_VEScrollView_getContentOffset00);
   tolua_function(tolua_S,"setContentOffset",tolua_utils_VEScrollView_setContentOffset00);
   tolua_function(tolua_S,"addCell",tolua_utils_VEScrollView_addCell00);
   tolua_function(tolua_S,"removeCell",tolua_utils_VEScrollView_removeCell00);
   tolua_function(tolua_S,"removeAllCells",tolua_utils_VEScrollView_removeAllCells00);
   tolua_function(tolua_S,"getAllCells",tolua_utils_VEScrollView_getAllCells00);
   tolua_function(tolua_S,"addTouchHandler",tolua_utils_VEScrollView_addTouchHandler00);
   tolua_function(tolua_S,"touchCheck",tolua_utils_VEScrollView_touchCheck00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_utils (lua_State* tolua_S) {
 return tolua_utils_open(tolua_S);
};
#endif

