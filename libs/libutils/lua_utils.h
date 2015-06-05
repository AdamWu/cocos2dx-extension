#ifndef __LUA_UTILS_H__
#define __LUA_UTILS_H__

#ifdef __cplusplus
extern "C" {
#endif
#include "tolua++.h"
#ifdef __cplusplus
}
#endif

TOLUA_API int  tolua_utils_open (lua_State* tolua_S);

#endif //__LUA_UTILS_H__