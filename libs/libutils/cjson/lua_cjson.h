#ifndef __CJSON_H_
#define __CJSON_H_

#ifdef __cplusplus
extern "C" {
#endif
#include "tolua++.h"

int luaopen_cjson (lua_State * L);

#ifdef __cplusplus
}
#endif

#endif // __CJSON_H_
