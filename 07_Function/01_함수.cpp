#include <iostream>

/*
    함수(Function)란?
    특정 작업을 수행하는 코드 묶음이다.
    같은 작업을 여러 번 해야 할 때 코드를 복사하지 않고 함수로 만들어 호출한다.

    함수의 구성
    반환형 함수이름(매개변수)
    {
        실행할 코드
        return 반환값; // 반환형이 void가 아닐 때
    }
*/

/*
    함수 프로토타입(선언)이 필요한 이유

    C++ 컴파일러는 소스 코드를 위에서 아래 방향으로 읽는다.
    main()에서 Add(10, 20)를 만났을 때 Add 함수의 정의가 아직 아래에 있다면,
    컴파일러는 Add라는 함수가 존재하는지, 어떤 자료형을 받고 무엇을 반환하는지 알 수 없다.

    프로토타입은 함수의 이름, 반환형, 매개변수 자료형을 미리 알려 준다.
    그래서 컴파일러가 함수 호출의 인수 개수·자료형을 검사할 수 있다.

    함수 정의를 main()보다 위에 작성한다면 프로토타입은 필요 없다.
    하지만 보통 main()을 먼저 읽기 좋게 두고 함수 구현을 아래에 작성하므로 프로토타입을 사용한다.
*/
void PrintTitle();
int Add(int left, int right);
double CalculateAverage(int first, int second, int third);
bool IsEven(int number);

/*
    프로토타입이 없으면 어떻게 될까?

    int main()
    {
        Add(10, 20); // 오류: 이 시점에 컴파일러는 Add를 아직 모른다.
    }

    int Add(int left, int right)
    {
        return left + right;
    }

    C++은 함수를 자동으로 미리 선언해 주지 않는다.
    위 코드에서는 main() 앞에 int Add(int, int); 선언을 추가하거나,
    Add 함수의 전체 정의를 main() 위로 옮겨야 한다.
*/

int main()
{
    PrintTitle(); // 반환값이 없는(void) 함수 호출

    int result = Add(10, 20); // 인수(argument) 10, 20을 매개변수 left, right에 전달한다.
    std::cout << "10 + 20 = " << result << '\n';

    double average = CalculateAverage(80, 90, 100);
    std::cout << "평균: " << average << '\n';

    int number = 7;
    if (IsEven(number))
    {
        std::cout << number << "은 짝수입니다.\n";
    }
    else
    {
        std::cout << number << "은 홀수입니다.\n";
    }

    return 0;
}

// 함수 정의(구현)
// 프로토타입의 반환형, 함수 이름, 매개변수 자료형은 정의와 반드시 같아야 한다.
void PrintTitle()
{
    std::cout << "===== 함수와 프로토타입 =====\n";
}

int Add(int left, int right)
{
    return left + right;
}

double CalculateAverage(int first, int second, int third)
{
    // int끼리 나누면 소수점이 버려진다.
    // 3.0을 사용하면 실수 나눗셈이 되어 소수점 결과를 얻는다.
    return (first + second + third) / 3.0;
}

bool IsEven(int number)
{
    // 2로 나눈 나머지가 0이면 짝수다.
    return number % 2 == 0;
}
