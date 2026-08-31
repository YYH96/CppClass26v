#include <iostream>

/*
    구조체 패딩(Structure Padding)

    구조체의 크기는 멤버 자료형 크기를 단순히 더한 값과 다를 수 있다.
    컴파일러는 CPU가 데이터를 효율적으로 읽도록 멤버 사이 또는 구조체 끝에
    패딩 바이트를 넣어 정렬(Alignment)을 맞춘다.

    멤버의 선언 순서를 바꾸면 패딩의 양과 sizeof 결과가 달라질 수 있다.
*/

struct Example
{
    char a; // 1바이트
    int b;  // 보통 4바이트 경계에 놓이도록 앞에 패딩이 추가될 수 있다.
    char c; // 구조체 전체 크기를 맞추기 위해 뒤에 패딩이 추가될 수 있다.
};  // 12

struct Example2
{
    char a;
    char c;
    int b;
}; // 8

struct Example3
{
    char a;
    char c;
    int b;
    char d;
}; // 12

int main()
{
    std::cout << "char 크기: " << sizeof(char) << "바이트\n";
    std::cout << "int 크기: " << sizeof(int) << "바이트\n\n";

    std::cout << "Example  크기: " << sizeof(Example) << "바이트\n";
    std::cout << "Example2 크기: " << sizeof(Example2) << "바이트\n";
    std::cout << "Example3 크기: " << sizeof(Example3) << "바이트\n";

    /*
        Visual Studio x64 환경에서는 보통 다음 결과를 확인할 수 있다.
        Example  : 12바이트
        Example2 : 8바이트
        Example3 : 12바이트

        하지만 sizeof 결과는 컴파일러, 플랫폼, 컴파일 옵션에 따라 달라질 수 있다.
        따라서 특정 바이트 수를 모든 환경에서 보장한다고 가정하면 안 된다.

        패딩을 줄이고 싶다면 일반적으로 크기가 큰 멤버를 먼저,
        크기가 작은 멤버를 나중에 배치하는 방법을 고려할 수 있다.
        단, 의미가 분명한 멤버 순서와 가독성도 함께 고려해야 한다.
    */

    return 0;
}
