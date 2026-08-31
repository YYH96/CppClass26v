#include <iostream>

/*
    중첩 조건문과 삼항 연산자

    중첩 조건문은 조건문 안에 조건문을 작성하는 방식이다.
    삼항 연산자는 간단한 값 선택에 사용하는 조건 연산자(?:)다.
*/
int main()
{
#pragma region 중첩_조건문
    int number = -8;

    if (number >= 0)
    {
        if (number % 2 == 0)
        {
            std::cout << "0 또는 양수인 짝수입니다.\n";
        }
        else
        {
            std::cout << "양수인 홀수입니다.\n";
        }
    }
    else
    {
        std::cout << "음수입니다.\n";
    }
#pragma endregion

#pragma region 삼항_연산자
    int health = 30;

    // 조건 ? true일 때 값 : false일 때 값
    const char* state = (health > 0) ? "생존" : "게임 오버";
    std::cout << "상태: " << state << "\n";
#pragma endregion

    /*
        !기억
        - 삼항 연산자는 짧고 단순한 값 선택에 사용한다.
        - 여러 문장을 실행하거나 조건이 복잡하면 if-else가 읽기 쉽다.
        - 중첩이 깊어지면 가독성이 떨어지므로, 조건을 함수나 논리 변수로 분리하는 것을 고려한다.
    */
    return 0;
}
