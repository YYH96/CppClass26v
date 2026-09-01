#pragma once

#include <filesystem>
#include <string>

// 파일에 저장할 플레이어와 진행도 데이터다.
// string을 포함하므로 바이너리로 통째로 저장하지 않고 텍스트 항목별로 저장한다.
struct SaveData
{
    std::string playerName;
    int jobValue = 0;
    int hp = 0;
    int maxHP = 0;
    int attack = 0;
    int gold = 0;
    int level = 0;
    int exp = 0;
    int stageLevel = 0;
    int maxGoldReward = 0;
};

namespace SaveSystem
{
    std::filesystem::path GetSaveFilePath();
    bool HasSaveData();
    bool SaveGame(const SaveData& saveData);
    bool LoadGame(SaveData& outSaveData);
}

