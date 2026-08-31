#include <iostream>
#include <string>

/*
    std::string 주요 멤버 함수

    insert, erase, replace, substr, find를 한 번에 확인한다.
    find가 실패하면 std::string::npos를 반환한다.
*/

int main()
{
    std::string message = "Hello World";
    std::cout << "처음: " << message << '\n';

    message.insert(5, ",");
    std::cout << "insert: " << message << '\n';

    message.erase(5, 1);
    std::cout << "erase: " << message << '\n';

    message.replace(6, 5, "C++");
    std::cout << "replace: " << message << '\n';

    std::string firstWord = message.substr(0, 5);
    std::cout << "substr(0, 5): " << firstWord << '\n';

    std::size_t position = message.find("C++");
    if (position != std::string::npos)
    {
        std::cout << "C++를 찾은 위치: " << position << '\n';
    }

    position = message.find("Java");
    if (position == std::string::npos)
    {
        std::cout << "Java는 문자열에 없습니다.\n";
    }

    return 0;
}
