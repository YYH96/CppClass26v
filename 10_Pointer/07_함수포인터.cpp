#include <iostream>

/*
    함수 포인터

    함수도 코드가 있는 주소를 가진다. 함수 포인터에는 호출할 함수의 주소를 저장할 수 있다.

    문법: 반환형 (*포인터이름)(매개변수 목록);
    예시: int (*operation)(int, int);

    함수 포인터에는 반환형과 매개변수 목록이 같은 함수만 저장할 수 있다.
*/

#pragma region 기본 함수 포인터 선언

int Add(int left, int right);                                    // 두 수의 합을 반환
int Subtract(int left, int right);                               // 두 수의 차를 반환
int Subtractd(double left, double right);                               // 두 수의 차를 반환

int Calculate(int left, int right, int (*FuncName)(int, int)); // 전달받은 함수로 계산
void PrintReady();                                               // 반환값 없이 준비 메시지를 출력
void PrintNumber(int number);                                    // 반환값 없이 정수 하나를 출력
void PrintTwoNumbers(int first, int second);                     // 반환값 없이 정수 두 개를 출력
int GetLuckyNumber();                                            // 매개변수 없이 정수 하나를 반환

#pragma endregion

#pragma region 버블 정렬 함수 포인터 선언

bool AscendingOrder(int left, int right);                        // 오름차순일 때 교환해야 하면 true
bool DescendingOrder(int left, int right);                       // 내림차순일 때 교환해야 하면 true
void BubbleSort(int values[], int count, bool (*shouldSwap)(int, int));
void PrintArray(const int values[], int count);

#pragma endregion

int main()
{
#pragma region 기본 함수 포인터

    int (*operation)(int, int) = Add; // Add 함수의 주소를 저장한다.

    std::cout << "10 + 3 = " << operation(10, 3) << '\n';

    operation = Subtract; // 같은 모양의 다른 함수로 바꿀 수 있다.
    std::cout << "10 - 3 = " << operation(10, 3) << '\n';

	//operation = Subtractd; // 오류 : Subtractd 함수는 매개변수 타입이 다르므로 같은 모양의 함수가 아니다.

    // 함수 이름을 전달하면 함수 포인터 매개변수로 전달된다.
    std::cout << "20 + 5 = " << Calculate(20, 5, Add) << '\n';
    std::cout << "20 - 5 = " << Calculate(20, 5, Subtract) << '\n';

#pragma endregion

#pragma region 다양한 함수 포인터 형태

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

#pragma endregion

#pragma region 버블 정렬 비교 함수 포인터

    std::cout << "\n===== 함수 포인터로 정렬 기준 바꾸기 =====\n";

    int ascendingNumbers[] = { 30, 10, 40, 20, 50 };
    int descendingNumbers[] = { 30, 10, 40, 20, 50 };

    // BubbleSort의 세 번째 매개변수에 어떤 비교 함수를 넘기는지에 따라 정렬 방향이 바뀐다.
    BubbleSort(ascendingNumbers, 5, AscendingOrder);
    std::cout << "오름차순: ";
    PrintArray(ascendingNumbers, 5);

    BubbleSort(descendingNumbers, 5, DescendingOrder);
    std::cout << "내림차순: ";
    PrintArray(descendingNumbers, 5);

#pragma endregion

    return 0;
}

#pragma region 기본 함수 포인터 구현

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

#pragma endregion

#pragma region 버블 정렬 구현

// 오름차순 정렬을 위한 비교 함수
bool AscendingOrder(int left, int right)
{
    // 왼쪽 값이 더 크면 두 값을 교환해 작은 값이 앞으로 오게 한다.
    return left > right;
}

// 내림차순 정렬을 위한 비교 함수
bool DescendingOrder(int left, int right)
{
    // 왼쪽 값이 더 작으면 두 값을 교환해 큰 값이 앞으로 오게 한다.
    return left < right;
}

void BubbleSort(int values[], int count, bool (*shouldSwap)(int, int))
{
    for (int lastIndex = count - 1; lastIndex > 0; --lastIndex)
    {
        for (int index = 0; index < lastIndex; ++index)
        {
            if (shouldSwap(values[index], values[index + 1]))
            {
                const int temp = values[index];
                values[index] = values[index + 1];
                values[index + 1] = temp;
            }
        }
    }
}

void PrintArray(const int values[], int count)
{
    for (int index = 0; index < count; ++index)
    {
        std::cout << values[index] << ' ';
    }

    std::cout << '\n';
}

#pragma endregion
