#include <iostream>

/*
    재귀 함수 실습 - 팩토리얼

    n! = n * (n - 1) * ... * 1
    0!은 1이다.

    long long으로 계산할 때 20!까지는 표현할 수 있지만,
    21!부터는 자료형 범위를 넘어 오버플로우가 발생할 수 있다.
    이 예제는 0 이상의 정수만 전달한다고 가정한다.
*/

// 일반 재귀 팩토리얼
long long FactorialRecursive(int number)
{
    // 종료 조건: 0!과 1!은 모두 1이다.
    if (number <= 1)
    {
        return 1;
    }

    // 재귀 호출의 결과를 받은 뒤 number를 곱한다.
    return number * FactorialRecursive(number - 1);
}

// 꼬리 재귀 팩토리얼
long long FactorialTailRecursive(int number, long long accumulated)
{
    // 종료 조건: 지금까지 누적한 곱을 반환한다.
    if (number <= 1)
    {
        return accumulated;
    }

    // number를 먼저 누적값에 곱한 뒤, 재귀 호출이 마지막 작업으로 끝난다.
    return FactorialTailRecursive(number - 1, accumulated * number);
}

int main()
{
    int number = 5;

    std::cout << number << "!\n";
    std::cout << "일반 재귀: " << FactorialRecursive(number) << '\n';

    // 꼬리 재귀의 accumulated는 곱셈의 시작값인 1로 전달한다.
    std::cout << "꼬리 재귀: " << FactorialTailRecursive(number, 1) << "\n\n";

    /*
        FactorialRecursive(5)
        = 5 * FactorialRecursive(4)
        = 5 * 4 * FactorialRecursive(3) ...

        FactorialTailRecursive(5, 1)
        -> FactorialTailRecursive(4, 5)
        -> FactorialTailRecursive(3, 20) ...
        -> 120 반환
    */

    return 0;
}
