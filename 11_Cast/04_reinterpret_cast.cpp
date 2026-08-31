#include <cstdint>  // std::uintptr_t
#include <iostream>

/*
    reinterpret_cast

    포인터나 비트 수준의 표현을 다른 방식으로 해석할 때 사용하는 저수준 캐스트다.
    자료형 안전성을 확인하지 않으므로 일반적인 값 변환에는 사용하지 않는다.

    운영체제, 그래픽스, 네트워크, 하드웨어처럼 주소 자체를 다뤄야 하는 경우에 제한적으로 사용한다.
*/

int main()
{
    int number = 100;
    int* pNumber = &number;

    // 포인터 주소를 정수형 주소값으로 표현한다.
    std::uintptr_t address = reinterpret_cast<std::uintptr_t>(pNumber);
    std::cout << "number의 주소값: 0x" << std::hex << address << std::dec << '\n';

    // 같은 주소값을 다시 int*로 되돌린다.
    int* pRestored = reinterpret_cast<int*>(address);
    std::cout << "되돌린 포인터가 읽는 값: " << *pRestored << '\n';

    /*
        아래처럼 int 주소를 float*로 해석하는 것은 문법상 가능할 수 있어도 안전하지 않다.
        자료형이 다르면 메모리의 비트를 해석하는 방법도 달라진다.

        float* pWrongType = reinterpret_cast<float*>(pNumber);
        std::cout << *pWrongType; // 위험: 잘못된 방식으로 메모리를 읽음
    */

    return 0;
}
