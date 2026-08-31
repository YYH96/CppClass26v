#include <cmath>
#include <iostream>

// 논리 연산자의 실제 평가 순서를 출력으로 확인하기 위한 함수
bool CheckCondition(const char* name, bool result)
{
    std::cout << "  " << name << " 검사: " << result << "\n";
    return result;
}

/*
    기본 제공 연산자(Built-in Operators)

    연산자는 피연산자(값, 변수 등)에 특정 계산이나 비교를 수행하는 기호다.
    Visual Studio의 #pragma region을 사용해 수업 구역을 접을 수 있게 나눈다.
*/

int main()
{

#pragma region 산술_연산자
    // ================================================================
    // 1. 산술 연산자: +, -, *, /, %
    // ================================================================
    int left = 10;
    int right = 3;
    double realLeft = 10.0;
    double realRight = 3.0;
    std::cout << "[Arithmetic]\n";
    std::cout << "10 + 3 = " << left + right << "\n";
    std::cout << "10 - 3 = " << left - right << "\n";
    std::cout << "10 * 3 = " << left * right << "\n";

    // / : 정수끼리 나누면 소수점 아래가 버려진다. right는 반드시 0이 아니어야 한다.
    // 정수 0으로 나누기는 정의되지 않은 동작(프로그램 오류)이므로 절대 수행하지 않는다.
    std::cout << "10 / 3 = " << left / right << "  (정수 나눗셈)\n";

    // 실수끼리 나누면 소수점 아래 결과까지 계산한다.
    // 실수 0.0으로 나누면 보통 infinity 또는 NaN이 될 수 있지만, 결과에 의존하지 말고 미리 0인지 검사한다.
    std::cout << "10.0 / 3.0 = " << realLeft / realRight << "  (실수 나눗셈)\n";

    // % : 나머지 연산자는 정수형에만 사용할 수 있다. 실수(double, float)에는 사용할 수 없다.
    // % 역시 오른쪽 피연산자가 0이면 정의되지 않은 동작이다.
    std::cout << "10 % 3 = " << left % right << "  (나머지)\n\n";
#pragma endregion

#pragma region 대입_연산자
    // ================================================================
    // 2. 대입 연산자: =, +=, -=, *=, /=, %=
    // ================================================================
    int value = 10;
    value += 5;  // value = value + 5
    value -= 3;  // value = value - 3
    value *= 2;  // value = value * 2
    value /= 4;  // value = value / 4
    value %= 3;  // value = value % 3
    std::cout << "[Assignment]\nvalue = " << value << "\n\n";

    // =는 값을 대입하고, ==는 두 값이 같은지 비교한다. 조건문에서 혼동하지 않는다.
    // int a = b = 0;처럼 연속 대입은 오른쪽에서 왼쪽 순서로 처리된다.
    // 복합 대입(a += b)은 a = a + b보다 의도를 간결하게 표현할 때 사용한다.
#pragma endregion

#pragma region 증감_연산자
    // ================================================================
    // 3. 증감 연산자: ++, --
    // ================================================================
    int count = 5;
    std::cout << "[Increment / Decrement]\n";
    std::cout << "count++ returns: " << count++ << ", count: " << count << "\n";
    std::cout << "++count returns: " << ++count << ", count: " << count << "\n";
    std::cout << "count-- returns: " << count-- << ", count: " << count << "\n";
    std::cout << "--count returns: " << --count << ", count: " << count << "\n\n";

    // 한 표현식 안에서 같은 변수를 여러 번 증감하지 않는다.
    // 예: count = count++ + ++count;  // 읽기 어렵고 결과를 예측하기 어려운 코드
#pragma endregion

#pragma region 비교_연산자
    // ================================================================
    // 4. 비교 연산자: ==, !=, <, >, <=, >=
    // 결과는 bool(true 또는 false)이다.
    // ================================================================
    std::cout << std::boolalpha;
    std::cout << "[Comparison]\n";
    std::cout << "10 == 3: " << (left == right) << "\n";
    std::cout << "10 != 3: " << (left != right) << "\n";
    std::cout << "10 < 3: " << (left < right) << "\n";
    std::cout << "10 >= 3: " << (left >= right) << "\n\n";

    // 실수는 이진수로 정확히 표현되지 않는 값이 있어 == 비교가 기대와 다를 수 있다.
    double calculated = 0.1 + 0.2;
    double expected = 0.3;
    double epsilon = 0.0000001; // 허용할 오차 범위

    std::cout << "0.1 + 0.2 == 0.3: " << (calculated == expected) << "\n";
    std::cout << "abs((0.1 + 0.2) - 0.3) < epsilon: "
              << (std::abs(calculated - expected) < epsilon) << "\n\n";
#pragma endregion

#pragma region 논리_연산자
    // ================================================================
    // 5. 논리 연산자: &&(AND), ||(OR), !(NOT)
    // &&와 ||는 필요 없는 오른쪽 식을 평가하지 않는 단락 평가를 한다.
    // ================================================================
    bool hasTicket = true;
    bool isAdult = false;
    std::cout << "[Logical]\n";
    std::cout << "hasTicket && isAdult: " << (hasTicket && isAdult) << "\n";
    std::cout << "hasTicket || isAdult: " << (hasTicket || isAdult) << "\n";
    std::cout << "!hasTicket: " << !hasTicket << "\n\n";

    /*
        !기억 - 논리 연산자는 오른쪽부터 읽거나 실행하지 않는다.

        &&와 ||는 왼쪽 피연산자부터 오른쪽 피연산자 순서로 평가한다.
        a && b && c는 (a && b) && c로 묶이며, a -> b -> c 순서로 검사한다.
        a || b || c도 a -> b -> c 순서로 검사한다.

        &&는 왼쪽이 false면, ||는 왼쪽이 true면 오른쪽을 실행하지 않는다.
        이를 단락 평가(Short-circuit Evaluation)라고 한다.
        따라서 포인터 검사 뒤에만 역참조한다: pointer != nullptr && *pointer > 0
    */
    std::cout << "[Short-circuit evaluation order]\n";
    bool andResult = CheckCondition("왼쪽 false", false)
        && CheckCondition("오른쪽 true", true); // 오른쪽 함수는 호출되지 않는다.
    std::cout << "AND result: " << andResult << "\n";

    bool orResult = CheckCondition("왼쪽 true", true)
        || CheckCondition("오른쪽 false", false); // 오른쪽 함수는 호출되지 않는다.
    std::cout << "OR result: " << orResult << "\n\n";

    /*
        결합성(association)과 평가 순서(evaluation order)는 구분해야 한다.
        a = b = c는 대입 연산자가 오른쪽 결합이어서 a = (b = c)로 묶인다.
        하지만 논리 연산자의 피연산자 평가 순서는 위처럼 왼쪽에서 오른쪽이다.

        Visual Studio에서 확인하는 방법
        1. 상단 구성에서 Debug / x64를 선택한다.
        2. CheckCondition 함수의 첫 줄에 중단점(F9)을 설정한다.
        3. F5로 디버그 실행 후 F10(한 단계씩 실행)을 누른다.
        4. 왼쪽 조건만 중단되고 오른쪽 조건에는 도달하지 않는 것을 확인한다.
        Debug 구성은 보통 최적화 사용 안 함(/Od)으로 설정해 단계 실행을 보기 좋게 한다.
        설정 위치: 프로젝트 속성 > C/C++ > 최적화 > 최적화 > 사용 안 함(/Od)
    */

    // &와 |는 비트 연산자이므로 &&, ||와 혼동하지 않는다.
#pragma endregion

#pragma region 비트_연산자
    // ================================================================
    // 6. 비트 연산자: &, |, ^, ~, <<, >>
    // 정수의 각 비트를 대상으로 연산한다.
    // ================================================================
    unsigned int bitA = 0b0101; // 5
    unsigned int bitB = 0b0011; // 3
    std::cout << "[Bitwise]\n";
    std::cout << "0101 & 0011: " << (bitA & bitB) << "\n";
    std::cout << "0101 | 0011: " << (bitA | bitB) << "\n";
    std::cout << "0101 ^ 0011: " << (bitA ^ bitB) << "\n";
    std::cout << "0101 << 1: " << (bitA << 1) << "\n";
    std::cout << "0101 >> 1: " << (bitA >> 1) << "\n\n";

    // 비트 연산과 시프트는 부호 없는 정수(unsigned)로 다루는 편이 안전하고 의도가 명확하다.
    // 시프트 횟수는 0 이상이며 자료형 비트 수보다 작아야 한다.
    // 예: unsigned int x = 1; x << 32;  // 32비트 unsigned int에서는 잘못된 시프트
#pragma endregion

#pragma region 기타_연산자
    // ================================================================
    // 7. 기타: 조건 연산자(?:), sizeof
    // ================================================================
    int maxValue = (left > right) ? left : right;
    std::cout << "[Other]\n";
    std::cout << "larger value: " << maxValue << "\n";
    std::cout << "sizeof(double): " << sizeof(double) << " byte\n";

    // ?:는 조건에 따라 둘 중 하나의 식만 실행한다.
    // sizeof는 자료형 또는 변수의 바이트 크기를 구한다.
    // sizeof("Hello")는 문자열 끝 문자 '\0'까지 포함하므로 6이다.
#pragma endregion

    return 0;
}
