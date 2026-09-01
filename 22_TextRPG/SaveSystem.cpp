#include "GameInfo.h"
#include "SaveSystem.h"

// SHGetKnownFolderPath는 Shell32.lib에 들어 있는 Windows API다.
#pragma comment(lib, "Shell32.lib")

namespace SaveSystem
{
    std::filesystem::path GetSaveFilePath()
    {
        // Windows가 관리하는 실제 '문서(내 문서)' 경로를 얻는다.
        // 사용자가 문서 폴더의 위치를 옮겼거나 Windows 표시 언어가 달라도 올바르게 동작한다.
        PWSTR documentsPath = nullptr;
        const HRESULT result = SHGetKnownFolderPath(
            FOLDERID_Documents,
            KF_FLAG_DEFAULT,
            nullptr,
            &documentsPath);

        if (SUCCEEDED(result) && documentsPath != nullptr)
        {
            const std::filesystem::path savePath = std::filesystem::path(documentsPath) / L"TextRPGSave.txt";

            // SHGetKnownFolderPath가 할당한 메모리는 반드시 해제해야 한다.
            CoTaskMemFree(documentsPath);
            return savePath;
        }

        // 문서 경로를 얻지 못한 특수 환경에서는 현재 작업 폴더에 저장한다.
        return std::filesystem::current_path() / "TextRPGSave.txt";
    }

    bool HasSaveData()
    {
        std::ifstream inputFile(GetSaveFilePath());

        if (!inputFile.is_open())
        {
            return false;
        }

        // 공백과 줄바꿈을 건너뛴 뒤 EOF라면 내용이 비어 있는 파일이다.
        inputFile >> std::ws;
        return inputFile.peek() != std::char_traits<char>::eof();
    }

    bool SaveGame(const SaveData& saveData)
    {
        const std::filesystem::path savePath = GetSaveFilePath();
        const std::filesystem::path saveDirectory = savePath.parent_path();

        // 폴더가 이미 있으면 그대로 사용하고, 없으면 새로 만든다.
        // Debug에서는 만들기에 실패한 경우 즉시 중단해 원인을 확인할 수 있다.
        const bool isDirectoryReady =
            std::filesystem::exists(saveDirectory)
            || std::filesystem::create_directories(saveDirectory);
        assert(isDirectoryReady);

        // Release 빌드에서는 assert가 제거되므로 실패를 반환으로도 처리한다.
        if (!isDirectoryReady)
        {
            return false;
        }

        // 기본 ofstream 모드는 기존 내용을 비우고 새 저장 데이터로 덮어쓴다.
        std::ofstream outputFile(savePath);

        if (!outputFile.is_open())
        {
            return false;
        }

        // 저장 순서와 LoadGame의 읽는 순서는 반드시 같아야 한다.
        outputFile << saveData.playerName << '\n';
        outputFile << saveData.jobValue << '\n';
        outputFile << saveData.hp << '\n';
        outputFile << saveData.maxHP << '\n';
        outputFile << saveData.attack << '\n';
        outputFile << saveData.gold << '\n';
        outputFile << saveData.level << '\n';
        outputFile << saveData.exp << '\n';
        outputFile << saveData.stageLevel << '\n';
        outputFile << saveData.maxGoldReward << '\n';

        return static_cast<bool>(outputFile);
    }

    bool LoadGame(SaveData& outSaveData)
    {
        if (!HasSaveData())
        {
            return false;
        }

        std::ifstream inputFile(GetSaveFilePath());

        if (!inputFile.is_open())
        {
            return false;
        }

        std::getline(inputFile, outSaveData.playerName);
        inputFile >> outSaveData.jobValue;
        inputFile >> outSaveData.hp;
        inputFile >> outSaveData.maxHP;
        inputFile >> outSaveData.attack;
        inputFile >> outSaveData.gold;
        inputFile >> outSaveData.level;
        inputFile >> outSaveData.exp;
        inputFile >> outSaveData.stageLevel;
        inputFile >> outSaveData.maxGoldReward;

        // 파일이 비었거나 중간에 손상된 경우에는 이어하기를 허용하지 않는다.
        if (!inputFile || outSaveData.playerName.empty()
            || outSaveData.jobValue < 1
            || outSaveData.jobValue > static_cast<int>(eJobClass::COUNT)
            || outSaveData.hp < 1 || outSaveData.maxHP < 1
            || outSaveData.attack < 1 || outSaveData.level < 1
            || outSaveData.stageLevel < 1 || outSaveData.maxGoldReward < 1)
        {
            return false;
        }

        return true;
    }
}
