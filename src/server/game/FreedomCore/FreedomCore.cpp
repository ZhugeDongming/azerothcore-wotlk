#include "FreedomCore.h"

//void FreedomCore::LoadSetting()
//{
//    auto result = FreedomDatabase.Query("SELECT `key`, `value` FROM `_setting`");
//
//    if (!result)
//        return;
//
//    do
//    {
//        Field* fields = result->Fetch();
//        auto key = fields[0].GetCString();
//
//        //u->uint32 U->uint64 i->int32 I->Int64 b->bool s->string
//        switch (key[0])
//        {
//        case 'u': SetConfig(key, fields[1].GetUInt32()); break;
//        case 'U': SetConfig(key, fields[1].GetUInt64()); break;
//        case 'i': SetConfig(key, fields[1].GetInt32()); break;
//        case 'I': SetConfig(key, fields[1].GetUInt64()); break;
//        case 'b': SetConfig(key, fields[1].GetBool()); break;
//        case 's': SetConfig(key, fields[1].GetString()); break;
//        default:
//            sLog->outError("[FreedomCore]设置项'%s'命名不正确,设置数据已忽略,正确命名方式是[u->uint32;U->uint64;i->int32;I->Int64;b->bool;s->string].", key);
//            break;
//        }
//    } while (result->NextRow());
//
//    sLog->outString("读取FreedomCore数据库设置完成,读取到%u条数据.", m_configs.bucket_count());
//}
//
//void FreedomCore::LoadLocalString()
//{
//    auto result = FreedomDatabase.Query("SELECT * FROM `_local_string`");
//
//    if (!result)
//        return;
//
//    do
//    {
//        Field* fields = result->Fetch();
//        auto key = fields[0].GetString();
//        StringVector* data = &m_localStrings[key];
//
//        for (uint8 i = 0; i < MAX_LOCALES; ++i)
//            data->push_back(fields[i + 1].GetString());
//
//    } while (result->NextRow());
//    
//    sLog->outString("读取FreedomCore数据库本地化文本完成,读取到%u条数据.", m_localStrings.bucket_count());
//}
//
//void FreedomCore::Initialize()
//{
//    LoadSetting();
//    LoadLocalString();
//}
