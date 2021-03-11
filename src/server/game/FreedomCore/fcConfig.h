#pragma once
#include <variant>
#include "Define.h"
#include <string>


typedef std::variant<std::nullptr_t, int32, uint32, int64, uint64, std::string, bool> SettingData;
