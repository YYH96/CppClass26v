#include <iostream>

/*
    재귀 함수 실습 - 피보나치 수열

    0번째 항은 0, 1번째 항은 1이다.
    2번째 항부터는 바로 앞의 두 항을 더한다.

    Fibonacci(n) = Fibonacci(n - 1) + Fibonacci(n - 2)
*/

long long Fibonacci(int index)
{
    // 종료 조건: 0번째와 1번째 항은 이미 알고 있다.
    if (index <= 1)
    {
        return index;
    }

    // 앞의 두 항을 구하기 위해 재귀 호출을 두 번 수행한다.
    return Fibonacci(index - 1) + Fibonacci(index - 2);
}

int main()
{
    int lastIndex = 10;

    std::cout << "피보나치 수열 (0번째 ~ " << lastIndex << "번째)\n";
    for (int index = 0; index <= lastIndex; ++index)
    {
        std::cout << Fibonacci(index) << ' ';
    }
    std::cout << "\n\n";

    /*
        Fibonacci(5)
        = Fibonacci(4) + Fibonacci(3)
        = (Fibonacci(3) + Fibonacci(2)) + (Fibonacci(2) + Fibonacci(1))

        같은 Fibonacci(3), Fibonacci(2)를 여러 번 다시 계산한다.
        따라서 이 단순 재귀 방식은 index가 커질수록 호출 횟수가 매우 많이 늘어난다.
        큰 피보나치 수열은 반복문, 배열, 메모이제이션 등을 이용하는 방식이 더 적합하다.

        long long은 Fibonacci(92)까지 표현할 수 있고, 그 이후에는 오버플로우가 발생할 수 있다.
    */

    return 0;
}
