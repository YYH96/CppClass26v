#include <iostream>

/*
    for 문

    반복문이란 특정 조건이 참인 동안 코드 블록을 반복 실행하는 제어문이다.
    같은 작업을 여러 번 해야 할 때, 같은 코드를 복사해서 작성하지 않고 사용한다.
    예를 들어 1부터 5까지 출력하려면 출력문을 다섯 번 쓰는 대신 반복문을 사용한다.
    반복할 때마다 조건을 확인하고, 조건이 거짓(false)이 되는 순간 반복을 멈춘다.

    for (초기식; 조건식; 증감식)
    1. 초기식은 반복 시작 전 한 번 실행된다.
    2. 조건식이 true인 동안 본문을 실행한다.
    3. 본문이 끝나면 증감식을 실행하고 다시 조건을 검사한다.
*/
int main()
{
#pragma region 기본_for_문
    std::cout << "1부터 5까지 출력\n";
    for (int number = 1; number <= 5; ++number)
    {
        std::cout << number << " ";
    }
    std::cout << "\n\n";
#pragma endregion

#pragma region 역순_for_문
    std::cout << "5부터 1까지 출력\n";
    for (int number = 5; number >= 1; --number)
    {
        std::cout << number << " ";
    }
    std::cout << "\n\n";
#pragma endregion

#pragma region 범위_기반_for_문
    // 범위 기반 for문은 배열·컨테이너의 모든 원소를 차례대로 가져온다.
    int scores[] = { 90, 80, 100 };
    int total = 0;

    for (int score : scores)
    {
        total += score;
    }
    std::cout << "점수 합계: " << total << "\n";
#pragma endregion

    /*
        !기억
        - 조건식 또는 증감식을 잘못 작성하면 반복문이 끝나지 않는 무한 반복이 될 수 있다.
        - 반복 횟수가 정해져 있거나 인덱스를 사용할 때 for문이 적합하다.
    */
    return 0;
}
