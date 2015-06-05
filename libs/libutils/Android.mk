LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := utils_static

LOCAL_MODULE_FILENAME := libutils

LOCAL_SRC_FILES := \
lua_utils.cpp \
cjson/dtoa.c \
cjson/g_fmt.c \
cjson/strbuf.c \
cjson/lua_cjson.c \
shader/blind_sprite.cpp \
shader/bloom_sprite.cpp \
shader/blur_sprite.cpp \
shader/color_sprite.cpp \
shader/frost_sprite.cpp \
shader/gray_sprite.cpp \
shader/hue_sprite.cpp \
shader/laser_sprite.cpp \
shader/normal_sprite.cpp \
shader/ripple_sprite.cpp \
shader/stream_sprite.cpp \
shader/shader_manager.cpp \
io/FileSystem.cpp \
ui/VEScrollView.cpp \

LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)

LOCAL_C_INCLUDES := $(LOCAL_PATH)
                                
LOCAL_WHOLE_STATIC_LIBRARIES += cocos2dx_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocos_lua_static
 
include $(BUILD_STATIC_LIBRARY)

$(call import-module,cocos2dx)
$(call import-module,scripting/lua/proj.android)