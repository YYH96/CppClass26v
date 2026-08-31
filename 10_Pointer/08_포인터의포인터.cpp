#include <iostream>

/*
    포인터의 포인터

    int*는 int의 주소를 저장한다.
    int**는 int* 포인터 변수의 주소를 저장한다.

    **pPointerToPointer처럼 *를 두 번 사용하면 원본 int 값까지 접근할 수 있다.
*/

int main()
{
    int number = 10;
    int* pNumber = &number;    // number의 주소를 저장
    int** ppNumber = &pNumber; // pNumber의 주소를 저장

    std::cout << "number: " << number << '\n';
    std::cout << "*pNumber: " << *pNumber << '\n';
    std::cout << "**ppNumber: " << **ppNumber << "\n\n";

    **ppNumber = 50; // 포인터의 포인터를 거쳐 원본 number의 값을 바꾼다.
    std::cout << "**ppNumber = 50 후 number: " << number << '\n';

    return 0;
}
