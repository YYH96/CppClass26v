/*
    바이너리 파일 저장과 불러오기

    텍스트 파일은 숫자 1000을 문자 '1', '0', '0', '0'으로 저장한다.
    바이너리 파일은 int의 메모리 바이트 그대로 저장한다.

    주의: std::string을 포함한 구조체 전체를 write로 저장하면 안 된다.
    string은 문자 데이터가 아닌 내부 포인터 등의 정보를 가지고 있기 때문이다.
    따라서 문자열은 [문자열 길이][문자 데이터] 순서로 따로 저장한다.
*/

#include <cstdint>
#include <fstream>
#include <iostream>
#include <string>

struct PlayerInfo
{
    std::string name;
    std::string job;
    int gold;
};

bool WriteString(std::ofstream& outputFile, const std::string& text)
{
    // 파일 형식에서 길이를 uint32_t(4바이트)로 정했다.
    const std::uint32_t length = static_cast<std::uint32_t>(text.size());

    outputFile.write(reinterpret_cast<const char*>(&length), sizeof(length));
    outputFile.write(text.data(), length);

    return static_cast<bool>(outputFile);
}

bool ReadString(std::ifstream& inputFile, std::string& text)
{
    std::uint32_t length = 0;
    inputFile.read(reinterpret_cast<char*>(&length), sizeof(length));

    if (!inputFile)
    {
        return false;
    }

    // length만큼 실제 문자 공간을 만든 뒤, 파일의 바이트를 그대로 읽는다.
    text.resize(length);
    inputFile.read(text.data(), length);

    return static_cast<bool>(inputFile);
}

int main()
{
    const char* fileName = "PlayerData.bin";
    PlayerInfo savedPlayer{ "영호", "별 수호자", 1500 };

    // ios::binary를 지정해야 Windows의 텍스트 줄바꿈 변환 없이 바이트 그대로 저장한다.
    std::ofstream outputFile(fileName, std::ios::binary);

    if (!outputFile.is_open())
    {
        std::cout << "바이너리 저장 파일을 열지 못했습니다.\n";
        return 1;
    }

    bool writeSuccess = WriteString(outputFile, savedPlayer.name)
        && WriteString(outputFile, savedPlayer.job);
    outputFile.write(reinterpret_cast<const char*>(&savedPlayer.gold), sizeof(savedPlayer.gold));
    writeSuccess = writeSuccess && static_cast<bool>(outputFile);
    outputFile.close();

    if (!writeSuccess)
    {
        std::cout << "바이너리 저장에 실패했습니다.\n";
        return 1;
    }

    PlayerInfo loadedPlayer{};
    std::ifstream inputFile(fileName, std::ios::binary);

    if (!inputFile.is_open())
    {
        std::cout << "바이너리 불러오기 파일을 열지 못했습니다.\n";
        return 1;
    }

    bool readSuccess = ReadString(inputFile, loadedPlayer.name)
        && ReadString(inputFile, loadedPlayer.job);
    inputFile.read(reinterpret_cast<char*>(&loadedPlayer.gold), sizeof(loadedPlayer.gold));
    readSuccess = readSuccess && static_cast<bool>(inputFile);
    inputFile.close();

    if (!readSuccess)
    {
        std::cout << "바이너리 불러오기에 실패했습니다.\n";
        return 1;
    }

    std::cout << "바이너리에서 불러온 플레이어\n";
    std::cout << "이름: " << loadedPlayer.name << '\n';
    std::cout << "직업: " << loadedPlayer.job << '\n';
    std::cout << "골드: " << loadedPlayer.gold << '\n';

    return 0;
}
