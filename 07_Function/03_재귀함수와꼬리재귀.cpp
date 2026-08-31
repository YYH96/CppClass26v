#include <iostream>

/*
    재귀 함수(Recursive Function)란?
    함수가 자신의 내부에서 자기 자신을 다시 호출하는 함수다.

    재귀 함수에는 반드시 종료 조건(Base Case)이 필요하다.
    종료 조건이 없으면 함수 호출이 끝나지 않아 호출 스택이 넘치는
    스택 오버플로우(Stack Overflow)가 발생할 수 있다.

    이 예제는 1부터 n까지의 합을 두 방식으로 구한다.
    - 일반 재귀: 재귀 호출이 끝난 뒤에 현재 값을 더한다.
    - 꼬리 재귀: 재귀 호출이 함수의 마지막 작업이다.
*/

// 일반 재귀
int SumRecursive(int number)
{
    // 종료 조건: number가 0 이하이면 더할 값이 없으므로 0을 반환한다.
    if (number <= 0)
    {
        return 0;
    }

    // SumRecursive(number - 1)이 끝난 뒤에 number를 더해야 한다.
    // 따라서 각 함수 호출은 자신의 number 값을 기억한 채 기다린다.
    return number + SumRecursive(number - 1);
}

// 꼬리 재귀
int SumTailRecursive(int number, int accumulated)
{
    // 종료 조건: 지금까지 누적한 값을 바로 반환한다.
    if (number <= 0)
    {
        return accumulated;
    }

    // 현재 값을 accumulated에 먼저 반영한다.
    // 재귀 호출이 이 함수에서 하는 마지막 작업이므로 꼬리 재귀다.
    return SumTailRecursive(number - 1, accumulated + number);
}

int main()
{
    int number = 5;

    std::cout << "1부터 " << number << "까지의 합\n\n";

    std::cout << "일반 재귀 결과: " << SumRecursive(number) << '\n';
    std::cout << "꼬리 재귀 결과: " << SumTailRecursive(number, 0) << "\n\n";

    /*
        일반 재귀 호출 흐름: SumRecursive(3)

        3 + SumRecursive(2)
          2 + SumRecursive(1)
            1 + SumRecursive(0)
            0 반환
          1 + 0 반환
        2 + 1 반환
        3 + 3 반환 -> 6

        꼬리 재귀 호출 흐름: SumTailRecursive(3, 0)

        SumTailRecursive(3, 0)
        -> SumTailRecursive(2, 3)
        -> SumTailRecursive(1, 5)
        -> SumTailRecursive(0, 6)
        -> 6 반환
    */

    /*
        일반 재귀와 꼬리 재귀의 차이

        일반 재귀: 재귀 호출 뒤에 더할 작업이 남아 있다.
        꼬리 재귀: 재귀 호출이 마지막 작업이며, 누적값을 매개변수로 전달한다.

        일부 컴파일러는 꼬리 재귀를 반복문처럼 최적화할 수 있다.
        하지만 C++ 언어가 이 최적화를 보장하지는 않는다.
        큰 횟수의 반복 작업에는 재귀보다 반복문이 더 안전한 경우가 많다.
    */

    return 0;
}
