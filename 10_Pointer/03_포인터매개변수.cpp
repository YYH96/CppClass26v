#include <iostream>

/*
    포인터를 함수 매개변수로 사용하기

    함수에 변수의 주소를 전달하면, 함수는 원본 변수에 접근할 수 있다.
    호출할 때는 &변수, 함수 안에서는 *포인터로 원본 값에 접근한다.

    배열을 함수에 전달할 때도 배열 이름은 첫 번째 요소의 주소로 변환된다.
    포인터만으로는 배열의 크기를 알 수 없으므로 크기도 함께 전달해야 한다.
*/

void Add100ByValue(int number);                   // 값으로 받은 정수에 100을 더함, 원본은 변하지 않음
void Add100(int* number);                          // 주소로 받은 정수에 100을 더함, 원본이 변함
void SetArray(int* values, int count, int value); // 배열의 모든 요소를 value로 변경
void PrintArray(const int values[], int count);   // 배열을 읽어서 출력, 값은 변경하지 않음

int main()
{
    int number = 0;
    std::cout << "함수 호출 전: " << number << '\n';

    // number의 값 0이 Add100ByValue의 매개변수로 복사된다.
    // 함수 안에서 복사본을 바꿔도 main의 number는 바뀌지 않는다.
    Add100ByValue(number);
    std::cout << "값 전달 Add100ByValue 호출 후: " << number << '\n';

    // &number로 주소를 전달하면 함수가 원본 number가 있는 위치에 접근한다.
    Add100(&number); // number의 주소를 전달한다.
    std::cout << "포인터 전달 Add100 호출 후: " << number << "\n\n";

    const int arraySize = 5;
    int numbers[arraySize] = { 0, 0, 0, 0, 0 };

    std::cout << "배열 변경 전: ";
    PrintArray(numbers, arraySize);

    SetArray(numbers, arraySize, 10);
    std::cout << "배열 변경 후: ";
    PrintArray(numbers, arraySize);

    return 0;
}

void Add100ByValue(int number)
{
    number += 100;
    std::cout << "Add100ByValue 함수 안의 복사본: " << number << '\n';
}

void Add100(int* number)
{
    // nullptr인지 먼저 확인하면 잘못된 주소를 역참조하는 일을 줄일 수 있다.
    if (number != nullptr)
    {
        *number += 100;
    }
}

void SetArray(int* values, int count, int value)
{
    for (int i = 0; i < count; ++i)
    {
        // *(values + i)는 values[i]와 같은 의미다.
        *(values + i) = value;
    }
}

// 함수 매개변수의 const int values[]는 const int* values와 같은 의미다.
// [] 표기를 쓰면 "배열을 받는다"는 의도가 더 잘 보인다.
void PrintArray(const int values[], int count)
{
    for (int i = 0; i < count; ++i)
    {
        std::cout << values[i] << ' ';
    }
    std::cout << '\n';
}
