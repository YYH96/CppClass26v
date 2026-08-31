#include <iostream>

/*
    포인터란?

    포인터는 다른 변수 또는 객체의 "메모리 주소"를 저장하는 변수다.
    int*라고 쓰면 "int가 저장된 주소를 가리키며, 그 주소의 데이터를 int로 해석한다"는 뜻이다.

    &변수  : 변수의 주소를 구하는 주소 연산자
    *포인터: 포인터가 가리키는 주소의 값에 접근하는 역참조 연산자

    !기억 - 포인터가 저장하는 것은 주소값이고, 포인터의 자료형은
             그 주소에서 몇 바이트를 어떤 자료형으로 해석할지 알려 준다.
*/

int main()
{
    int number = 42;             // 일반 변수: 값 42를 저장한다.
    int* pNumber = &number;      // 포인터 변수: number의 주소를 저장한다.

    std::cout << "number의 값: " << number << '\n';
    std::cout << "number의 주소: " << &number << '\n';
    std::cout << "pNumber에 저장된 주소: " << pNumber << '\n';
    std::cout << "*pNumber로 읽은 값: " << *pNumber << "\n\n";

    // pNumber가 가리키는 곳에 100을 저장한다.
    // 결국 number가 저장된 메모리의 값이 바뀐다.
    *pNumber = 100;
    std::cout << "*pNumber = 100 후 number의 값: " << number << "\n\n";

    // 아직 가리킬 대상이 없을 때는 nullptr로 초기화한다.
    // nullptr은 "아무것도 가리키지 않는다"는 C++의 포인터 전용 값이다.
    int* pEmpty = nullptr;
    if (pEmpty == nullptr)
    {
        std::cout << "pEmpty는 아직 아무것도 가리키지 않습니다.\n";
    }

    // 포인터의 크기는 가리키는 자료형과 관계없이 주소 크기다.
    // 일반적으로 x64 프로그램은 8바이트, x86 프로그램은 4바이트다.
    std::cout << "int* 포인터의 크기: " << sizeof(pNumber) << "바이트\n";

    // int* pBad;     // 초기화하지 않은 포인터: 어디를 가리키는지 알 수 없다.
    // *pBad = 10;    // 위험: 정의되지 않은 동작
    // *pEmpty = 10;  // 위험: nullptr은 역참조하면 안 된다.

    return 0;
}
