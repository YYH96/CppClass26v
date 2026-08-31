#include <iostream>

/*
    조건문(Conditional Statement)

    조건문의 조건식이 true이면 해당 코드 블록을 실행하고,
    false이면 다음 조건 또는 else 블록으로 분기한다.
*/
int main()
{
#pragma region if_문
    int temperature = 28;

    if (temperature >= 25)
    {
        std::cout << "날씨가 덥습니다.\n";
    }
#pragma endregion

#pragma region if_else_문
    int number = 7;

    if (number % 2 == 0)
    {
        std::cout << number << "은(는) 짝수입니다.\n";
    }
    else
    {
        std::cout << number << "은(는) 홀수입니다.\n";
    }
#pragma endregion

#pragma region else_if_문
    int score = 83;

    // 위 조건부터 순서대로 검사하며, 처음 true가 된 블록 하나만 실행한다.
    if (score >= 90)
    {
        std::cout << "등급: A\n";
    }
    else if (score >= 80)
    {
        std::cout << "등급: B\n";
    }
    else if (score >= 70)
    {
        std::cout << "등급: C\n";
    }
    else
    {
        std::cout << "등급: D\n";
    }
#pragma endregion

    /*
        !기억
        - 조건식에는 비교 연산자(==, >= 등)와 논리 연산자(&&, || 등)를 사용한다.
        - if (score = 100)은 비교가 아니라 대입이므로 if (score == 100)처럼 작성한다.
        - 한 줄만 실행하더라도 중괄호를 작성하면 조건문 수정 시 실수를 줄일 수 있다.
    */
    return 0;
}
