#include <iostream>

/*
    배열과 포인터

    배열 이름은 대부분의 식에서 첫 번째 요소의 주소로 변환된다.
    따라서 arr[i]와 *(arr + i)는 같은 요소를 가리킨다.

    단, 배열 자체와 포인터는 같은 것이 아니다.
    - 배열은 여러 요소를 실제로 저장하는 공간이다.
    - 포인터는 주소 하나를 저장하는 변수다.
*/

int main()
{
    int scores[5] = { 70, 80, 90, 100, 95 };
    int* pScore = scores; // scores는 여기서 첫 번째 요소 scores[0]의 주소로 변환된다.

    std::cout << "scores[1]: " << scores[1] << '\n';
    std::cout << "*(pScore + 1): " << *(pScore + 1) << "\n\n";

    // 포인터에 1을 더하면 1바이트가 아니라, 가리키는 자료형 한 칸만큼 이동한다.
    // int*에 1을 더하면 다음 int 요소로 이동한다.
    for (int* p = scores; p < scores + 5; ++p)
    {
        std::cout << "값: " << *p << ", 주소: " << p << '\n';
    }

    std::cout << '\n';
	std::cout << "scores의 크기: " << sizeof(scores) << "바이트\n"; // 20바이트 (int 4바이트 * 5개)
	std::cout << "pScore의 크기: " << sizeof(pScore) << "바이트\n"; // 8바이트 (64비트 시스템에서 포인터는 8바이트)

    // 배열 범위를 벗어난 포인터 연산이나 역참조는 하면 안 된다.
    // std::cout << *(pScore + 5); // 위험: scores[5]는 존재하지 않는다.

    return 0;
}
