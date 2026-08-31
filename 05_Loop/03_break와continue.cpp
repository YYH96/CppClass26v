#include <iostream>

/*
    반복문 제어

    break: 현재 반복문을 즉시 종료한다.
    continue: 현재 반복의 남은 코드를 건너뛰고 다음 반복으로 이동한다.
*/
int main()
{
#pragma region continue_문
    std::cout << "홀수만 출력: ";
    for (int number = 1; number <= 10; ++number)
    {
        if (number % 2 == 0)
        {
            continue; // 짝수면 아래 출력 코드를 건너뛴다.
        }

        std::cout << number << " ";
    }
    std::cout << "\n\n";
#pragma endregion

#pragma region break_문
    std::cout << "7을 찾을 때까지 출력: ";
    for (int number = 1; number <= 10; ++number)
    {
        if (number == 7)
        {
            std::cout << "찾음";
            break; // for문을 즉시 종료한다.
        }

        std::cout << number << " ";
    }
    std::cout << "\n";
#pragma endregion

    /*
        !기억
        - break는 가장 안쪽 반복문 또는 switch 문 하나만 종료한다.
        - continue 뒤의 코드는 이번 반복에서 실행되지 않는다.
        - while문에서 continue를 사용할 때는 증감식이 건너뛰어 무한 반복이 되지 않는지 확인한다.
    */
    return 0;
}
