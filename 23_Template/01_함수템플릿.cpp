/*
    함수 템플릿

    자료형만 다르고 로직이 같은 함수를 하나의 설계도로 작성한다.
    컴파일러는 실제 호출된 자료형에 맞춰 필요한 함수를 컴파일 시간에 만든다.
*/

#include <iostream>
#include <string>

// typename T의 T는 '아직 정해지지 않은 자료형'을 뜻한다.
// class T라고 적어도 템플릿에서는 같은 의미로 사용할 수 있다.
template<typename T>
T Add(const T& left, const T& right)
{
    return left + right;
}

// 두 값 중 큰 값을 반환하는 함수 템플릿이다.
// T 자료형에는 비교 연산자(>)가 정의되어 있어야 한다.
template<typename T>
const T& GetMax(const T& left, const T& right)
{
    return (left > right) ? left : right;
}

// 템플릿 인자는 여러 개 선언할 수 있다.
// T와 U가 서로 다른 자료형이어도 덧셈 결과 자료형을 auto가 알아서 결정한다.
template<typename T, typename U>
auto AddDifferent(const T& left, const U& right)
{
    return left + right;
}

int main()
{
    // 1. 자료형 추론
    // 전달한 인자를 보고 컴파일러가 T를 int, double, string으로 판단한다.
    std::cout << "int 덧셈: " << Add(10, 20) << '\n';
    std::cout << "double 덧셈: " << Add(1.5, 2.25) << '\n';
    std::cout << "string 덧셈: " << Add(std::string("안녕 "), std::string("템플릿")) << '\n';

    // 2. 자료형 직접 지정
    // int와 double을 함께 전달하면 T를 하나로 추론할 수 없다.
    // Add(10, 2.5);                  // 오류: T의 자료형을 결정할 수 없음
    std::cout << "자료형 직접 지정: " << Add<double>(10, 2.5) << '\n';

    std::cout << "큰 값: " << GetMax(30, 15) << '\n';
    std::cout << "사전 순서가 뒤인 문자열: " << GetMax(std::string("Apple"), std::string("Banana")) << '\n';

    // 3. 템플릿 인자 여러 개
    // T는 int, U는 double로 각각 추론되고, 덧셈 결과는 double이다.
    const auto result = AddDifferent(10, 2.5);
    std::cout << "서로 다른 자료형 덧셈: " << result << '\n';

    return 0;
}
