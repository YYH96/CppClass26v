#include <iostream>
#include <string>

/*
    std::string 기초

    std::string은 문자열 길이를 관리해 주는 C++ 표준 라이브러리 클래스다.
    +, += 연산자로 문자열을 결합할 수 있고, []로 특정 문자에 접근할 수 있다.
*/

int main()
{
    std::string playerName = "Alice";
    std::string job = "Warrior";

    std::string introduction = playerName + " is a " + job + ".";
    std::cout << introduction << '\n';

    playerName += "_Player";
    std::cout << "수정한 이름: " << playerName << '\n';

    std::cout << "문자열 길이: " << playerName.size() << '\n';
    std::cout << "첫 번째 문자: " << playerName[0] << '\n';

    if (playerName.empty() == false)
    {
        std::cout << "이름이 비어 있지 않습니다.\n";
    }

    // playerName[100] = 'X'; // 범위를 벗어난 인덱스 접근은 위험하다.

    return 0;
}
