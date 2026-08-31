#include <iostream>

/*
    const int* 와 int* const

    const가 *의 왼쪽에 있으면 가리키는 값을 바꾸지 못한다.
    const가 *의 오른쪽에 있으면 포인터가 저장한 주소를 바꾸지 못한다.

    선언을 오른쪽에서 왼쪽으로 읽어 보면 의미를 이해하기 쉽다.
*/

int main()
{
    int first = 10;
    int second = 20;

    // 포인터 상수(pointer to const): 가리키는 값은 변경 불가, 주소 변경은 가능
    const int* pReadOnly = &first;
    // *pReadOnly = 100; // 오류: pReadOnly를 통해서는 first 값을 바꿀 수 없다.
    pReadOnly = &second;
    std::cout << "pReadOnly가 읽는 값: " << *pReadOnly << '\n';

    // 상수 포인터(const pointer): 주소 변경은 불가, 가리키는 값은 변경 가능
    int* const pFixedAddress = &first;
    *pFixedAddress = 100;
    // pFixedAddress = &second; // 오류: 포인터가 가리키는 주소를 바꿀 수 없다.
    std::cout << "first의 변경된 값: " << first << '\n';

    // 값과 주소를 모두 바꿀 수 없는 포인터
    const int* const pCompletelyReadOnly = &second;
    std::cout << "pCompletelyReadOnly가 읽는 값: " << *pCompletelyReadOnly << '\n';
    // *pCompletelyReadOnly = 30; // 오류: 값 변경 불가
    // pCompletelyReadOnly = &first; // 오류: 주소 변경 불가

    return 0;
}
