-- 0 - disable debug info, 1 - less debug info, 2 - verbose debug info
DEBUG = 2

-- Show fps
DEBUG_FPS = false

-- Show mem usage
DEBUG_MEM = false

-- 配置加密
CONFIG_CFG_ENCRYPT = false

-- design resolution, used in display
CONFIG_SCREEN_WIDTH  = 1136
CONFIG_SCREEN_HEIGHT = 640

-- window design resolution, used in window manager
WINDOW_DESIGN_WIDTH = 1136
WINDOW_DESIGN_HEIGHT = 640

-- Auto Scale Mode
--CONFIG_SCREEN_AUTOSCALE = "FIXED_WIDTH"
--CONFIG_SCREEN_AUTOSCALE = "FIXED_HEIGHT_PRIOR"
--CONFIG_SCREEN_AUTOSCALE = "FIXED_WIDTH_PRIOR"


-- FPS、帧率
CONFIG_FPS = 60
CONFIG_DELTA_TIME = 1 / CONFIG_FPS
CONFIG_CCS_ANI_SCALE = 60 / CONFIG_FPS



-- --------------------------------------------------------------------
--  Network Config
-----------------------------------------------------------------------
CONFIG_HTTP_ADDR = "http://wwww.mankorgames.sinaapp.com/skycity/"

CONFIG_GATE_ADDR = "http://192.168.1.111:12001/servers"

-- test
CONFIG_SOCKET_ADDR = "192.168.1.111"
CONFIG_SOCKET_PORT = 12014


-- --------------------------------------------------------------------
--  Other Config
-----------------------------------------------------------------------
-- color
COLOR_WHITE 	= ccc3(255, 255, 255)
COLOR_BLACK 	= ccc3(0, 0, 0)
COLOR_GREEN 	= ccc3(0, 255, 0)
COLOR_BLUE  	= ccc3(0, 0, 255)
COLOR_PURPLE 	= ccc3(160, 32, 240)
COLOR_ORANGE	= ccc3(238, 154, 0)
COLOR_RED		= ccc3(255,0,0)
COLOR_YELLOW	= ccc3(255,255,0)
COLOR_GOLD		= ccc3(255,215,0)
COLOR_GRAY		= ccc3(128,128,128)
COLOR_BROWN     = ccc3(139,69,19)

COMMOM_QUALITY_COLOR = {
	COLOR_QUALITY_1 = ccc3(255,255,255),
	COLOR_QUALITY_2 = ccc3(0,255,0),
	COLOR_QUALITY_3 = ccc3(0,255,255),
	COLOR_QUALITY_4 = ccc3(255,0,255),
	COLOR_QUALITY_5 = ccc3(238,154,0)
}

---------------------------------
-- battlemap
---------------------------------

BattleMapSize = 
{
    width = 1136,
    height = 640
}

BattleMapTileSize = 
{
    width = 142,
    height = 80
}

CombatUnitType = 
{
    wujiang = 0,
    shibing = 1
}

CombatUnitOwnerType = 
{
    player = 0,
    npc = 1
}

-- --------------------------------------------------------------------
--  cocos Config
-----------------------------------------------------------------------

ccs = {}

ccs.TouchEventType = 
{
    began = 0,
    moved = 1,
    ended = 2,
    canceled = 3,
}

ccs.LoadingBarType = 
{ 
    left = 0, 
    right = 1,
}

ccs.CheckBoxEventType = 
{
    selected = 0,
    unselected = 1,
}

ccs.SliderEventType = 
{
    percent_changed = 0
}

ccs.TextFiledEventType = 
{
    attach_with_ime = 0,
    detach_with_ime = 1,
    insert_text = 2,
    delete_backward = 3,
}

ccs.LayoutBackGroundColorType = 
{
    none = 0,
    solid = 1,
    gradient = 2,
}

ccs.LayoutType = 
{
    absolute = 0,
    linearVertical = 1,
    linearHorizontal = 2,
    relative = 3,
}

ccs.UILinearGravity = 
{
    none = 0,
    left = 1,
    top = 2,
    right = 3,
    bottom = 4,
    centerVertical = 5,
    centerHorizontal = 6,
}

ccs.SCROLLVIEW_DIR = {
    none = 0,
    vertical = 1,
    horizontal = 2,
    both = 3,
}

ccs.PageViewEventType = {
   turning = 0,  
}

ccs.ListViewEventType = {
    init_child = 0,
    update_child = 1,
}

ccs.ListViewDirection = {
    none = 0,
    vertical = 1,
    horizontal = 2,
}

ccs.TextureResType = {
    tex_local = 0,
    tex_plist = 1,
}

ccs.MovementEventType = {
    start = 0,
    complete = 1,
    loopComplete = 2
}