#include <cstdint>
#include <iostream>
#include <limits>

/*
    변수와 기본 자료형

    변수는 값을 저장하도록 이름을 붙인 메모리 공간이다.
    자료형은 컴퓨터 메모리에 저장된 데이터를 해석하는 단위다.
    즉, 자료형은 그 공간에 저장할 값의 종류, 크기, 표현 범위를 정한다.
    아래 크기는 Windows + MSVC x64 환경에서 sizeof로 직접 확인한다.
*/
int main()
{
    // 선언: 타입과 이름을 정한다.  초기화: 선언과 동시에 첫 값을 저장한다.
    int minCount;
    int maxCount = 10;

    // 대입: 이미 선언한 변수의 값을 변경한다.
    minCount = 1;
    maxCount = 100;
    std::cout << "minCount: " << minCount << ", maxCount: " << maxCount << "\n\n";

    // bool: true 또는 false를 저장한다.
    bool isGameOver = false;

    // char: 문자 한 개를 저장한다. 문자 리터럴에는 작은따옴표를 사용한다.
    char grade = 'A';

    // 정수형: unsigned는 음수를 저장하지 않는 대신 양수 범위가 넓다.
    short shortValue = -32000;
    int score = 100;
    unsigned int gold = 300U;
    long long population = 8'000'000'000LL;

    // 실수형: float는 보통 4바이트, double은 보통 8바이트다.
    float speed = 12.5F;
    double pi = 3.141592653589793;

    std::cout << "bool: " << isGameOver << ", size: " << sizeof(bool) << " byte\n";
    std::cout << "char: " << grade << ", size: " << sizeof(char) << " byte\n";
    std::cout << "short: " << shortValue << ", size: " << sizeof(short) << " byte\n";
    std::cout << "int: " << score << ", size: " << sizeof(int) << " byte\n";
    std::cout << "unsigned int: " << gold << ", size: " << sizeof(unsigned int) << " byte\n";
    std::cout << "long long: " << population << ", size: " << sizeof(long long) << " byte\n";
    std::cout << "float: " << speed << ", size: " << sizeof(float) << " byte\n";
    std::cout << "double: " << pi << ", size: " << sizeof(double) << " byte\n\n";

    // <cstdint>의 int32_t처럼 크기가 명확한 자료형도 사용할 수 있다.
    std::int32_t networkId = 42;
    std::cout << "int32_t: " << networkId << ", size: " << sizeof(networkId) << " byte\n";
    std::cout << "int range: " << std::numeric_limits<int>::min()
              << " ~ " << std::numeric_limits<int>::max() << "\n";

    return 0;
}
