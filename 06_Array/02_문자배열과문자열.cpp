#include <iostream>

/*
    C 스타일 문자열은 char 배열에 문자를 저장하고, 마지막에 널 문자('\0')를 둔다.
    '\0'은 문자열의 끝을 표시하는 문자이므로, "hello"는 5글자여도 6칸이 필요하다.
*/
int main()
{
    char hello[6] = { 'h', 'e', 'l', 'l', 'o', '\0' };
    char helloByLiteral[] = "hello"; // 큰따옴표 문자열에는 '\0'이 자동으로 포함된다.

    std::cout << "문자 배열 hello: " << hello << '\n';
    std::cout << "문자열 리터럴로 초기화: " << helloByLiteral << '\n';
    std::cout << "hello 배열의 칸 수: " << sizeof(hello) / sizeof(hello[0]) << '\n';

    // 아래 배열에는 널 문자가 없다. cout이 문자열로 출력하려고 하면
    // 배열 밖의 메모리까지 읽을 수 있으므로 출력하면 안 된다.
    char notAString[5] = { 'h', 'e', 'l', 'l', 'o' };
    std::cout << "널 문자 없는 문자 배열의 마지막 문자: " << notAString[4] << '\n';
    // std::cout << notAString; // 위험: 문자열의 끝을 알 수 없다.

    return 0;
}
