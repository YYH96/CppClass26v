/*
    텍스트 파일 저장과 불러오기

    파일 안에 다음 순서로 한 줄씩 저장한다.
    1. 이름
    2. 직업
    3. 보유 골드

    저장할 때 정한 순서와 구분 규칙은 읽을 때도 같아야 한다.
*/

#include <fstream>
#include <iostream>
#include <string>

struct PlayerInfo
{
    std::string name;
    std::string job;
    int gold;
};

int main()
{
    const char* fileName = "PlayerData.txt";
    PlayerInfo savedPlayer{ "영호", "성기사", 1000 };

    // ofstream: 파일에 데이터를 출력(저장)하는 스트림이다.
    // 기본 모드는 기존 파일 내용을 비우고 처음부터 다시 쓴다.
    std::ofstream outputFile(fileName);

    if (!outputFile.is_open())
    {
        std::cout << "저장 파일을 열지 못했습니다.\n";
        return 1;
    }

    outputFile << savedPlayer.name << '\n';
    outputFile << savedPlayer.job << '\n';
    outputFile << savedPlayer.gold << '\n';
    outputFile.close(); // close를 생략해도 소멸 시 닫히지만, 수업에서는 시점을 명확히 보여 준다.

    // 저장한 값이 없어졌다고 가정하고 빈 구조체로 만든다.
    PlayerInfo loadedPlayer{};

    // ifstream: 파일에서 데이터를 입력(읽기)하는 스트림이다.
    std::ifstream inputFile(fileName);

    if (!inputFile.is_open())
    {
        std::cout << "불러올 파일을 열지 못했습니다.\n";
        return 1;
    }

    // 문자열은 공백도 읽을 수 있는 getline으로 읽는다.
    std::getline(inputFile, loadedPlayer.name);
    std::getline(inputFile, loadedPlayer.job);
    inputFile >> loadedPlayer.gold;
    inputFile.close();

    std::cout << "불러온 플레이어\n";
    std::cout << "이름: " << loadedPlayer.name << '\n';
    std::cout << "직업: " << loadedPlayer.job << '\n';
    std::cout << "골드: " << loadedPlayer.gold << '\n';

    return 0;
}

