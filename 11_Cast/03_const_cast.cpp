#include <iostream>

/*
    const_cast

    const_cast는 포인터나 참조에서 const 또는 volatile 속성만 추가하거나 제거한다.
    숫자형을 다른 숫자형으로 바꾸는 용도가 아니다.

    !기억 - 원래 const로 선언한 객체를 const_cast로 const를 제거한 뒤 수정하면
             정의되지 않은 동작이므로 절대로 수정하면 안 된다.
*/

int main()
{
    int number = 10;                  // 원본은 const가 아닌 일반 변수
    const int* pReadOnly = &number;   // 읽기 전용 포인터로 바라본다.

    // pReadOnly는 const int*라서 *pReadOnly = 20;은 할 수 없다.
    // 원본 number가 const가 아니므로 const_cast로 const를 제거해 수정할 수 있다.
    int* pWritable = const_cast<int*>(pReadOnly);
    *pWritable = 20;

    std::cout << "number의 변경된 값: " << number << '\n';

    const int originalConstNumber = 30;
    const int* pOriginalConst = &originalConstNumber;
    int* pWrong = const_cast<int*>(pOriginalConst);

    // *pWrong = 40; // 위험: 원래 const 객체를 수정하면 정의되지 않은 동작
    std::cout << "원래 const인 값: " << *pWrong << '\n';

    return 0;
}
