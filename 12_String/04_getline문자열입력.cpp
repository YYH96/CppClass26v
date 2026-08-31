#include <iostream>
#include <string>

/*
    getline으로 공백을 포함한 문자열 입력받기

    std::cin >> word는 공백 전까지만 읽는다.
    std::getline은 엔터를 누를 때까지 한 줄 전체를 읽는다.

    cin을 사용한 직후 getline을 쓸 때는 남은 엔터를 처리해야 한다.
    아래에서 엔터를 처리하지 않은 문제를 먼저 보여 준다.
*/

int main()
{
    std::cout << "===== 엔터를 처리하지 않은 경우 =====\n";

    int firstLevel = 0;
    std::cout << "레벨을 입력하세요: ";
    std::cin >> firstLevel;

    // >> 연산자는 숫자까지만 읽고, 엔터('\n')는 입력 버퍼에 남겨 둔다.
    // getline은 남아 있던 엔터를 바로 읽으므로 빈 문자열을 받는다.
    std::string failedMessage;
    std::getline(std::cin, failedMessage);

    std::cout << "엔터를 처리하지 않은 getline 결과: [" << failedMessage << "]\n";
    if (failedMessage.empty())
    {
        std::cout << "빈 문자열입니다. 숫자 입력 뒤에 남은 엔터를 getline이 읽었기 때문입니다.\n";
    }

    /*
        ===== 방법 1: std::cin.ignore() =====

        숫자 입력 뒤에 엔터 하나만 남아 있는 일반적인 경우에 사용할 수 있다.

        int level = 0;
        std::cin >> level;
        std::cin.ignore(); // 남은 엔터 문자 하나를 버림

        std::string introduction;
        std::getline(std::cin, introduction);
    */

    std::cout << "\n===== 방법 2: std::ws와 getline =====\n";

    int level = 0;
    std::cout << "레벨을 다시 입력하세요: ";
    std::cin >> level;

    std::string introduction;
    std::cout << "자기소개를 입력하세요: ";

    // std::ws가 cin 뒤에 남아 있는 공백과 줄바꿈을 먼저 처리한다.
    std::getline(std::cin >> std::ws, introduction);

    std::cout << "레벨 " << level << "의 소개: " << introduction << '\n';

    /*
        ===== 방법 3: 처음부터 getline만 사용 =====

        공백이 포함된 문자열만 받을 때는 cin >> 없이 getline만 사용하면
        엔터가 남는 문제를 만들지 않는다.

        std::string fullMessage;
        std::getline(std::cin, fullMessage);
    */

    return 0;
}
