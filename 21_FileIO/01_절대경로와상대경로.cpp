/*
    파일 경로

    - 절대 경로: 드라이브부터 적는 전체 경로
    - 상대 경로: 현재 작업 폴더를 기준으로 적는 경로
    - 파일이 예상과 다른 곳에 저장되면 current_path()를 먼저 출력해 확인한다.
*/

#include <filesystem>
#include <fstream>
#include <iostream>

int main()
{
    // 실행 중인 프로그램의 현재 작업 폴더를 출력한다.
    const std::filesystem::path currentPath = std::filesystem::current_path();
    std::cout << "현재 작업 폴더: " << currentPath << "\n\n";

    // 절대 경로 예시: 실제로 파일을 열지는 않는다.
    // raw string을 쓰면 Windows 경로의 \를 두 번 쓰지 않아도 된다.
    const std::filesystem::path absolutePath = R"(C:\GameData\PlayerData.txt)";
    std::cout << "절대 경로 예시: " << absolutePath << '\n';

    // 상대 경로: 현재 작업 폴더 안의 PathExample.txt를 뜻한다.
    const std::filesystem::path relativePath = "PathExample.txt";
    const std::filesystem::path convertedAbsolutePath = std::filesystem::absolute(relativePath);

    std::cout << "상대 경로: " << relativePath << '\n';
    std::cout << "상대 경로가 실제로 가리키는 위치: " << convertedAbsolutePath << "\n\n";

    // 상대 경로로 텍스트 파일 하나를 만든다.
    std::ofstream outputFile(relativePath);

    if (!outputFile.is_open())
    {
        std::cout << "파일을 열지 못했습니다.\n";
        return 1;
    }

    outputFile << "상대 경로로 저장한 파일입니다.\n";
    outputFile.close();

    std::cout << "파일 저장 완료: " << convertedAbsolutePath << '\n';
    return 0;
}

