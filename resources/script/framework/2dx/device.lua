local device = {}

device.platform    = "unknown"
device.model       = "unknown"

local sharedApplication = CCApplication:sharedApplication()
local target = sharedApplication:getTargetPlatform()
if target == kTargetWindows then
    device.platform = "windows"
elseif target == kTargetMacOS then
    device.platform = "mac"
elseif target == kTargetAndroid then
    device.platform = "android"
elseif target == kTargetIphone or target == kTargetIpad then
    device.platform = "ios"
    if target == kTargetIphone then
        device.model = "iphone"
    else
        device.model = "ipad"
    end
end

local language_ = sharedApplication:getCurrentLanguage()
if language_ == kLanguageChinese then
    language_ = "cn"
elseif language_ == kLanguageFrench then
    language_ = "fr"
elseif language_ == kLanguageItalian then
    language_ = "it"
elseif language_ == kLanguageGerman then
    language_ = "gr"
elseif language_ == kLanguageSpanish then
    language_ = "sp"
elseif language_ == kLanguageRussian then
    language_ = "ru"
else
    language_ = "en"
end

device.language = language_
device.writablePath = CCFileUtils:sharedFileUtils():getWritablePath()
--device.cachePath = CCFileUtils:sharedFileUtils():getCachePath()
device.directorySeparator = "/"
device.pathSeparator = ":"
if device.platform == "windows" then
    device.directorySeparator = "\\"
    device.pathSeparator = ";"
end

echoInfo("# device.platform              = " .. device.platform)
echoInfo("# device.model                 = " .. device.model)
echoInfo("# device.language              = " .. device.language)
echoInfo("# device.writablePath          = " .. device.writablePath)
--echoInfo("# device.cachePath             = " .. device.cachePath)
echoInfo("# device.directorySeparator    = " .. device.directorySeparator)
echoInfo("# device.pathSeparator         = " .. device.pathSeparator)
echoInfo("#")

return device