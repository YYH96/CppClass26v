#include <stdio.h>   // C 스타일 입출력: printf, puts
#include <iostream>

/*
    출력문(printf, cout)

    - <stdio.h>: C 스타일 입출력 함수의 선언을 제공하는 헤더
    - printf: C 스타일의 형식 지정 출력 함수
    - std::cout: C++ 스트림 기반 출력 객체
    - 이스케이프 시퀀스: 문자열 안에서 특수 동작을 표현하는 문자 조합
      \n(줄바꿈), \t(탭), \"(큰따옴표), \\(역슬래시)

    이 파일은 독립 실행 예제입니다.
    다른 예제의 main()과 충돌하므로, 동시에 빌드하지 않습니다.
*/
int main()
{
    // 1. 가장 간단한 출력
    printf("Hello, World!\n");

    // 2. 이스케이프 시퀀스
    printf("Hello\tC++\n");
    printf("첫 번째 줄\n두 번째 줄\n");
    printf("큰따옴표: \"C++\"\n");
    printf("경로: C:\\Users\\Student\n");
    printf("백스페이스: ABC\bD\n");

    puts("");

    /*
        3. printf의 서식 지정자(Format Specifier)

        printf는 "%"로 시작하는 서식 지정자 위치에 값을 순서대로 출력한다.
        %d, %i : 부호 있는 10진수 정수(int)
        %u     : 부호 없는 10진수 정수(unsigned int)
        %o     : 8진수 정수
        %x, %X : 16진수 정수(소문자/대문자)
        %f     : 실수(double, 기본 소수점 아래 6자리)
        %e     : 지수 표기법 실수
        %c     : 문자 한 개(char)
        %s     : C 스타일 문자열(const char*)
        %p     : 포인터 주소
    */
    int age = 25;
    const unsigned int score = 100U;
    const double pi = 3.141592;
    const char grade = 'A';
    const char* name = "Hong";

    printf("나이: %d살\n", age);
    printf("점수: %u점\n", score);
    printf("64를 8진수로 출력: %o\n", 64);
    printf("255를 16진수로 출력: %x / %X\n", 255, 255);
    printf("원주율: %f\n", pi);
    printf("원주율(지수 표기법): %e\n", pi);
    printf("등급: %c\n", grade);
    printf("이름: %s\n", name);

    // &age는 age 변수가 저장된 메모리 주소를 의미한다.
    printf("age의 주소: %p\n", static_cast<void*>(&age));

    puts("");

    // 4. C++ 스트림 출력
    // << 연산자는 값을 출력 스트림(std::cout)으로 보낸다.
    std::cout << "이름: " << name << ", 나이: " << age << "살\n";

    // \n은 줄바꿈 문자만 출력한다.
    // std::endl은 줄바꿈과 함께 출력 버퍼를 비운다(flush).
    std::cout << "\\n은 줄바꿈 문자만 출력합니다.\n";
    std::cout << "std::endl은 줄바꿈 후 출력 버퍼를 비웁니다." << std::endl;

    return 0;
}
