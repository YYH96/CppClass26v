#include <iostream>

/*
    함수 포인터

    함수도 코드가 있는 주소를 가진다. 함수 포인터에는 호출할 함수의 주소를 저장할 수 있다.

    문법: 반환형 (*포인터이름)(매개변수 목록);
    예시: int (*operation)(int, int);

    함수 포인터에는 반환형과 매개변수 목록이 같은 함수만 저장할 수 있다.
*/

int Add(int left, int right);                                    // 두 수의 합을 반환
int Subtract(int left, int right);                               // 두 수의 차를 반환
int Subtractd(double left, double right);                               // 두 수의 차를 반환

int Calculate(int left, int right, int (*FuncName)(int, int)); // 전달받은 함수로 계산
void PrintReady();                                               // 반환값 없이 준비 메시지를 출력
void PrintNumber(int number);                                    // 반환값 없이 정수 하나를 출력
void PrintTwoNumbers(int first, int second);                     // 반환값 없이 정수 두 개를 출력
int GetLuckyNumber();                                            // 매개변수 없이 정수 하나를 반환

int main()
{
    int (*operation)(int, int) = Add; // Add 함수의 주소를 저장한다.

    std::cout << "10 + 3 = " << operation(10, 3) << '\n';

    operation = Subtract; // 같은 모양의 다른 함수로 바꿀 수 있다.
    std::cout << "10 - 3 = " << operation(10, 3) << '\n';

	//operation = Subtractd; // 오류 : Subtractd 함수는 매개변수 타입이 다르므로 같은 모양의 함수가 아니다.

    // 함수 이름을 전달하면 함수 포인터 매개변수로 전달된다.
    std::cout << "20 + 5 = " << Calculate(20, 5, Add) << '\n';
    std::cout << "20 - 5 = " << Calculate(20, 5, Subtract) << '\n';

    std::cout << "\n===== 다양한 함수 포인터 형태 =====\n";

    // 반환형 void, 매개변수 0개
    void (*readyFunction)() = PrintReady;
    readyFunction();

    // 반환형 void, 매개변수 1개
    void (*oneParameterFunction)(int) = PrintNumber;
    oneParameterFunction(7);

    // 반환형 void, 매개변수 2개
    void (*twoParameterFunction)(int, int) = PrintTwoNumbers;
    twoParameterFunction(3, 9);

    // 반환형 int, 매개변수 0개
    int (*noParameterFunction)() = GetLuckyNumber;
    int luckyNumber = noParameterFunction();
    std::cout << "매개변수 없는 함수의 반환값: " << luckyNumber << '\n';

    return 0;
}

int Add(int left, int right)
{
    return left + right;
}

int Subtract(int left, int right)
{
    return left - right;
}

int Calculate(int left, int right, int (*FuncName)(int, int))
{
    return FuncName(left, right);
}

void PrintReady()
{
    std::cout << "준비 완료!\n";
}

void PrintNumber(int number)
{
    std::cout << "정수 하나: " << number << '\n';
}

void PrintTwoNumbers(int first, int second)
{
    std::cout << "정수 두 개: " << first << ", " << second << '\n';
}

int GetLuckyNumber()
{
    return 7;
}
