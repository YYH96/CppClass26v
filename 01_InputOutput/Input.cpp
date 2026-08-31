/*
    scanf는 문자열 입력 시 배열 크기를 알 수 없어 버퍼를 넘길 위험이 있다.
    그래서 MSVC는 scanf_s 사용을 권고하며 C4996 경고를 낸다.
    이 예제는 scanf 자체를 학습하기 위한 것이므로, 이 파일에서만 경고를 끈다.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>   // C 스타일 입출력: printf, scanf
#include <iostream>
#include <limits>
#include <string>

/*
    입력문(cin, getline, scanf)

    - std::cin >> 변수: 공백, 탭, 줄바꿈 전까지 입력받는다.
    - std::getline: 공백을 포함해 한 줄 전체를 입력받는다.
    - <stdio.h>: C 스타일 입출력 함수의 선언을 제공하는 헤더
    - scanf: 형식 지정자로 값을 입력받는 C 스타일 입력 함수다.
      문자열 입력은 버퍼 크기를 넘지 않도록 필드 폭을 지정해야 한다.
    - scanf_s: MSVC의 보안 강화 버전이다.
      %s, %c, %[처럼 버퍼에 데이터를 저장하는 서식에는
      버퍼 크기를 추가로 받아 실제 저장 공간을 검사한다.

    cin 다음에 getline을 사용한다면, cin이 남긴 줄바꿈 문자를
    std::cin.ignore()로 제거해야 한다.
*/
int main()
{
    int age = 0;
    std::string name;
    std::string introduction;

    // 1. std::cin은 공백 전까지 읽는다.
    std::cout << "나이를 입력하세요: ";
    std::cin >> age;

    std::cout << "이름을 입력하세요(공백 없음): ";
    std::cin >> name;

    std::cout << "입력 결과 - 이름: " << name << ", 나이: " << age << "살\n";

    // 2. getline은 공백을 포함하여 한 줄 전체를 읽는다.
    // 앞의 cin이 남긴 줄바꿈 문자를 먼저 제거해야 한다.
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "자기소개를 입력하세요: ";
    std::getline(std::cin, introduction);
    std::cout << "자기소개: " << introduction << "\n";

    // 3. scanf는 형식 지정자를 이용하는 C 스타일 입력 함수다.
    int first = 0;
    int second = 0;
    printf("두 정수를 입력하세요: ");
    if (scanf("%d %d", &first, &second) == 2)
    {
        printf("합계: %d\n", first + second);
    }
    else
    {
        printf("정수 두 개를 읽지 못했습니다.\n");
    }

    // scanf 예제
    // %19s는 최대 19글자만 읽는다.
    // 배열의 마지막 한 칸은 문자열 끝을 나타내는 '\0'을 위해 남겨 둔다.
    char nickname[20]{};
    printf("별명을 입력하세요(공백 없음): ");
    if (scanf("%19s", nickname) == 1)
    {
        printf("별명: %s\n", nickname);
    }

    /*
        scanf_s 예제

        scanf는 "%s"만 작성하면 입력 길이를 제한할 수 없어 위험하다.
        scanf_s는 배열과 함께 배열의 전체 크기를 받아서 저장 공간을 확인한다.
        입력 문자열이 버퍼에 들어갈 수 없으면 저장하지 않아 오버플로를 막는다.

        단, int처럼 이미 크기가 정해진 변수에는 버퍼 크기가 필요 없다.
        예: scanf_s("%d", &age);
    */
    char secureNickname[20]{};
    printf("안전한 별명을 입력하세요(공백 없음): ");
    if (scanf_s("%s", secureNickname, static_cast<unsigned>(sizeof(secureNickname))) == 1)
    {
        printf("안전한 별명: %s\n", secureNickname);
    }

    return 0;
}
