#include <iostream>

/*
    배열(Array)이란?
    같은 자료형의 데이터 요소들을 연속된 메모리 공간에 저장하는 자료 구조이다.

    int 배열이라면 각 칸을 int로 해석하며, 배열 이름은 첫 번째 요소의 주소처럼 사용할 수 있다.
    배열의 인덱스는 반드시 0부터 시작한다. 크기가 10인 배열의 마지막 인덱스는 9이다.
*/
int main()
{
    // 1. 선언만 한 지역 배열의 값은 초기화되지 않는다.
    // int scores[10];
    // 초기화하기 전의 값을 읽으면 안 된다.

    // 2. { }로 초기화하면 모든 요소가 0으로 초기화된다.
    int scores[10] = {};

    for (int index = 0; index < 10; ++index)
    {
        scores[index] = (index + 1) * 10;
    }

    std::cout << "인덱스로 배열 요소 출력\n";
    for (int index = 0; index < 10; ++index)
    {
        std::cout << "scores[" << index << "] = " << scores[index] << '\n';
    }

    // 3. 범위 기반 for문: 배열의 모든 요소를 처음부터 끝까지 순회한다.
    // 값을 바꾸려면 int&처럼 참조(&)를 사용해야 한다.
    for (int& score : scores)
    {
        score += 1;
    }

    std::cout << "\n참조로 모든 요소에 1을 더한 결과\n";
    for (int score : scores)
    {
        std::cout << score << ' ';
    }
    std::cout << "\n\n";

    // 4. 선언과 동시에 초기화하면 컴파일러가 배열 크기를 계산할 수 있다.
    int numbers[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    // 아래 두 표현식은 같은 위치(두 번째 요소)에 접근한다.
    *(numbers + 1) = 20; // 포인터 연산으로 접근
    numbers[1] = 30;     // 서브스크립트([])로 접근: 내부적으로 *(numbers + 1)과 같은 의미

    std::cout << "numbers[1] = " << numbers[1] << '\n';

    int allZero[10] = { 0 };       // 첫 요소가 0, 나머지도 0으로 초기화
    int partlySet[10] = { 0, 1, 2 }; // 나머지 요소는 0으로 초기화

    std::cout << "allZero[9] = " << allZero[9] << '\n';
    std::cout << "partlySet[0], partlySet[1], partlySet[2], partlySet[9] = "
        << partlySet[0] << ", " << partlySet[1] << ", "
        << partlySet[2] << ", " << partlySet[9] << '\n';

    // int tooMany[5] = { 0, 1, 2, 3, 4, 5 }; // 오류: 배열 크기를 초과하는 초기값
    // scores[10] = 100; // 오류가 나지 않을 수도 있지만 범위를 벗어난 접근(정의되지 않은 동작)

    return 0;
}
