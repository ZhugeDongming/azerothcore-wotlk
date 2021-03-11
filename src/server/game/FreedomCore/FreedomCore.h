#ifndef __FREEDOMCORE_H_
#define __FREEDOMCORE_H_

#pragma execution_character_set("utf-8")

#include "fcConfig.h"


class FreedomCore
{
private:
    FreedomCore() { };
    ~FreedomCore() { };

public:
    void LoadSetting();
    void LoadLocalString();
    void Initialize();

    static FreedomCore* instance()
    {
        static FreedomCore instance;
        return &instance;
    }

public:
    //安全调用设置方法,如不能通过断言说明调用时有致命错误
    const uint32 GetUint32Config(const char* key, uint32 default) { ASSERT(key[0] == 'u'); return GetConfig<uint32>(key) ? *GetConfig<uint32>(key) : default; }
    const int32 GetInt32Config(const char* key, int32 default) { ASSERT(key[0] == 'i'); return GetConfig<int32>(key) ? *GetConfig<int32>(key) : default; }
    const uint64 GetUint64Config(const char* key, uint64 default) { ASSERT(key[0] == 'U'); return GetConfig<uint64>(key) ? *GetConfig<uint64>(key) : default;}
    const int64 GetInt64Config(const char* key, int64 default) { ASSERT(key[0] == 'I'); return GetConfig<int64>(key) ? *GetConfig<int64>(key) : default;}
    const bool GetBoolConfig(const char* key, bool default) { ASSERT(key[0] == 'b'); return GetConfig<bool>(key) ? *GetConfig<bool>(key) : default;}
    const std::string GetStringConfig(const char* key, std::string default) { ASSERT(key[0] == 's'); return GetConfig<std::string>(key) ? *GetConfig<std::string>(key) : default;}

    template<class T>
    T* const GetConfig(std::string key)
    {
        auto val = m_configs.find(key);
        if (val != m_configs.end())
            return &std::get<T>(val->second);

        return nullptr;
    };

    template<class T>
    void SetConfig(std::string key, T val) { m_configs[key] = T(val); }

public:
    inline std::string GetStringLoc(std::string key, LocaleConstant loc = LOCALE_zhCN)
    {
        auto val = m_localStrings.find(key);
        if (loc)
            if (val != m_localStrings.end())
                if (val->second[loc - 1] != "")
                    return val->second[loc - 1];
        return key;
    }

    inline const char* GetStringLoc(const char* key, LocaleConstant loc = LOCALE_zhCN)
    {
        return GetStringLoc(std::string(key), loc).c_str();
    }


private:
    std::unordered_map<std::string, SettingData> m_configs;
    std::unordered_map<std::string, StringVector> m_localStrings;



};


#define FC  FreedomCore::instance()

//调用本地化文本
#define FCSL(...)  FC->GetStringLoc(__VA_ARGS__)



#endif //__FREEDOMCORE_H_