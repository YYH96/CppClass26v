#include <iostream>
#include <string>

/*
    자료형(Data Type)이란?

    자료형은 "컴퓨터 메모리에 저장된 데이터를 해석하는 단위"다.
    메모리는 0과 1의 비트만 저장한다. 자료형은 이 비트들을 정수, 실수,
    문자 등 어떤 종류의 값으로 읽을지와 그 크기·표현 범위를 결정한다.

    즉, 변수는 값을 저장할 이름 있는 메모리 공간이고,
    자료형은 그 메모리 공간을 읽고 해석하는 규칙이다.
*/
int main()
{
    // 입문 과정에서 자주 사용하는 기본 자료형
    int score = 100;                 // 정수
    double average = 97.5;           // 실수
    char grade = 'A';                // 문자 한 개
    bool isPassed = true;            // 참 또는 거짓
    std::string name = "Kim";       // 문자열

    std::cout << "score(int): " << score << "\n";
    std::cout << "average(double): " << average << "\n";
    std::cout << "grade(char): " << grade << "\n";
    std::cout << "isPassed(bool): " << isPassed << "\n";
    std::cout << "name(string): " << name << "\n\n";

    /*
        char는 문자 한 개를 저장하는 1바이트 자료형이다.
        영문과 숫자는 ASCII 문자 코드로 표현할 수 있다.
        아래 16진수 값은 각각 H, e, l, l, o, 공백, W, o, r, l, d를 뜻한다.
        마지막 0x00(\0)은 C 스타일 문자열의 끝을 표시한다.
    */
    char helloWorld[] = {
        0x48, 0x65, 0x6C, 0x6C, 0x6F, 0x20,
        0x57, 0x6F, 0x72, 0x6C, 0x64, 0x00
    };
    std::cout << "hex character codes: " << helloWorld << "\n\n";

    // sizeof로 각 자료형이 차지하는 메모리 크기를 확인한다.
    std::cout << "int size: " << sizeof(int) << " byte\n";
    std::cout << "double size: " << sizeof(double) << " byte\n";
    std::cout << "char size: " << sizeof(char) << " byte\n";
    std::cout << "bool size: " << sizeof(bool) << " byte\n";

    return 0;
}
