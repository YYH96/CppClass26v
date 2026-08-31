#include <iostream>

/*
    함수 오버로딩(Function Overloading)이란?
    같은 이름의 함수를 여러 개 만들되, 매개변수 목록을 다르게 작성하는 기능이다.

    컴파일러는 호출할 때 전달한 인수의 개수, 자료형, 순서를 보고 알맞은 함수를 선택한다.

    오버로딩 조건
    - 매개변수의 개수, 자료형, 순서 중 하나 이상이 달라야 한다.
    - 반환형만 다르게 하는 것은 오버로딩이 아니다.
      int Add(int, int);       // 가능
      double Add(int, int);    // 오류: 반환형만 다르다.
*/

#include <iostream>

// int 자료형용 사칙연산 함수
int Add(int left, int right);
int Subtract(int left, int right);
int Multiply(int left, int right);
int Divide(int left, int right);

// double 자료형용 사칙연산 함수
double Add(double left, double right);
double Subtract(double left, double right);
double Multiply(double left, double right);
double Divide(double left, double right);

int main()
{
    int intLeft = 20;
    int intRight = 3;
    double doubleLeft = 20.0;
    double doubleRight = 3.0;

    // 인수가 int이므로 int 버전 함수가 호출된다.
    std::cout << "[int]\n";
    std::cout << "Add: " << Add(intLeft, intRight) << '\n';
    std::cout << "Subtract: " << Subtract(intLeft, intRight) << '\n';
    std::cout << "Multiply: " << Multiply(intLeft, intRight) << '\n';

    // 정수 나눗셈에서 right가 0이면 정의되지 않은 동작이다.
    // 호출하기 전에 0인지 반드시 확인한다.
    if (intRight != 0)
    {
        std::cout << "Divide: " << Divide(intLeft, intRight)
            << " (정수 나눗셈: 소수점 이하는 버려짐)\n\n";
    }

    // 인수가 double이므로 double 버전 함수가 호출된다.
    std::cout << "[double]\n";
    std::cout << "Add: " << Add(doubleLeft, doubleRight) << '\n';
    std::cout << "Subtract: " << Subtract(doubleLeft, doubleRight) << '\n';
    std::cout << "Multiply: " << Multiply(doubleLeft, doubleRight) << '\n';

    // 실수도 0으로 나누기 전에 검사한다.
    // 0.0처럼 정확히 표현 가능한 값을 직접 비교하는 예시다.
    if (doubleRight != 0.0)
    {
        std::cout << "Divide: " << Divide(doubleLeft, doubleRight)
            << " (실수 나눗셈: 소수점 결과 유지)\n";
    }

    /*
        Add(10, 20)      -> Add(int, int)
        Add(10.0, 20.0)  -> Add(double, double)

        Add(10, 20.0)은 int와 double 버전 모두 형 변환이 필요할 수 있어
        모호한 호출 오류가 발생할 수 있다. 이런 경우 자료형을 맞춰 호출한다.
    */
    return 0;
}

// int 버전 정의
int Add(int left, int right)
{
    return left + right;
}

int Subtract(int left, int right)
{
    return left - right;
}

int Multiply(int left, int right)
{
    return left * right;
}

int Divide(int left, int right)
{
    // 이 함수는 right가 0이 아니라는 조건에서만 호출해야 한다.
    return left / right;
}

// double 버전 정의
double Add(double left, double right)
{
    return left + right;
}

double Subtract(double left, double right)
{
    return left - right;
}

double Multiply(double left, double right)
{
    return left * right;
}

double Divide(double left, double right)
{
    // 이 함수도 right가 0.0이 아닌 조건에서만 호출해야 한다.
    return left / right;
}
