/*
    배열을 함수로 넘기기 - 함수와 포인터를 배운 뒤 보는 예제

    [1. 배열과 포인터는 같은 것이 아니다]
    int numbers[5]는 int 5개를 실제로 보관하는 배열이다.
    int* pNumbers는 int 하나를 가리킬 수 있는 주소를 저장하는 포인터 변수이다.
    int* pNumbers = numbers;에서 numbers는 첫 원소를 가리키는 포인터로 변환된다.
    따라서 pNumbers에는 &numbers[0]이 저장된다. 배열 5개를 복사하는 것이 아니다.

    [2. 배열을 함수에 전달하면]
    PrintArray(numbers, 5);처럼 호출하면 첫 원소의 주소가 전달된다.
    함수는 그 주소와 원소 개수를 이용해 원본 배열의 원소에 접근한다.
    함수의 포인터 매개변수에는 주소값이 복사된다. 원본 배열 전체가 복사되지는 않는다.

    함수 매개변수에서 다음 두 표기는 같은 타입을 나타낸다.
        void PrintArray(const int numbers[], int count);
        void PrintArray(const int* numbers, int count);
    int arr[]도 함수 매개변수로 사용할 수 있으며 int* arr로 처리된다.
    읽기만 한다면 const int arr[], 수정한다면 int arr[]로 쓴다.
    아래에서는 포인터 표기 함수와 [] 표기 함수를 각각 호출해 비교한다.
    두 표기는 같은 매개변수 타입이므로 이것만 바꿔 같은 이름으로 오버로딩할 수 없다.
    매개변수를 int numbers[5]로 써도 실제 타입은 int*이며 5칸인지 검사하지 않는다.

    [3. 배열 길이를 따로 전달하는 이유]
    포인터에는 배열의 길이 정보가 없다. 따라서 원소 개수 count도 함께 전달한다.
    main의 sizeof(numbers)는 배열 전체 크기이지만, 함수의 sizeof(pNumbers)는
    포인터 크기이다. 함수에서 sizeof로 원본 배열의 길이를 구하면 안 된다.
    호출할 때는 실제로 접근할 수 있는 원소 개수에 맞게 count를 전달해야 한다.

    [4. 인덱스와 포인터 연산]
    pNumbers[i]와 *(pNumbers + i)는 같은 원소에 접근한다.
    pNumbers + 1은 다음 int 원소로 이동한다. 주소는 sizeof(int)바이트만큼 증가한다.
    읽기 전용 함수는 const int*, 원본을 바꾸는 함수는 int*로 받는다.
    const int*는 이 포인터를 통해 원소를 바꾸지 못하게 한다는 뜻이다.
    배열을 전달했다고 해서 함수가 delete[]로 해제하면 안 된다.
    이 예제의 배열은 main의 지역 배열이며 동적 할당한 메모리가 아니다.
*/

#include <iostream>

// 함수 선언: 출력과 합계는 읽기만 하므로 const를 붙인다.
void PrintArray(const int* pNumbers, int count);
int SumArray(const int* pNumbers, int count);
void AddToArray(int* pNumbers, int count, int amount);
void PrintArrayWithBrackets(const int arr[], int count); // [] 표기의 읽기 전용 예제
void AddWithBrackets(int arr[], int count, int amount);  // [] 표기의 원본 수정 예제

int main()
{
    int numbers[5] = { 10, 20, 30, 40, 50 };

    // 여기서는 numbers가 실제 배열이므로 전체 크기 / 한 원소 크기로 개수를 구한다.
    // sizeof의 결과를 이 작은 배열의 반복문에서 사용할 int로 변환한다.
    int count = static_cast<int>(sizeof(numbers) / sizeof(numbers[0]));

    // 배열 이름이 첫 원소의 주소로 변환된다. 아래 포인터는 원본 배열을 가리킨다.
    int* pNumbers = numbers;
    std::cout << "원소 개수: " << count << '\n';
    std::cout << "배열 전체 크기: " << sizeof(numbers) << "바이트\n";
    std::cout << "포인터 변수 크기: " << sizeof(pNumbers) << "바이트\n";
    // 포인터 크기는 빌드 환경에 따라 다를 수 있다. 배열 길이를 뜻하지 않는다.
    std::cout << "첫 원소 주소: " << pNumbers << '\n';
    std::cout << "&numbers[0]: " << &numbers[0] << '\n';
    std::cout << "다음 원소 주소: " << pNumbers + 1 << '\n';
    std::cout << "pNumbers[2]: " << pNumbers[2] << '\n';       // 30
    std::cout << "*(pNumbers + 2): " << *(pNumbers + 2) << '\n'; // 역시 30

    // 배열 이름을 전달해도, 같은 첫 원소를 가리키는 포인터를 전달해도 된다.
    std::cout << "\n변경 전: ";
    PrintArray(numbers, count);
    std::cout << "합계: " << SumArray(pNumbers, count) << '\n'; // 150

    // 주소를 통해 각 원소에 5를 더한다. 함수 호출 후 main의 배열도 바뀐다.
    AddToArray(numbers, count, 5);
    std::cout << "변경 후: ";
    PrintArray(numbers, count); // 15 25 35 45 55
    std::cout << "main에서 numbers[0] 확인: " << numbers[0] << '\n'; // 15
    std::cout << "변경 후 합계: " << SumArray(numbers, count) << '\n'; // 175

    // 중간 원소의 주소도 전달할 수 있다. 남은 범위를 넘지 않는 개수를 전달한다.
    std::cout << "뒤쪽 세 원소: ";
    PrintArray(numbers + 2, count - 2); // 35 45 55

    // [] 표기로 받는 함수도 첫 원소의 주소와 길이를 전달하는 방법은 같다.
    std::cout << "\n[] 매개변수로 출력: ";
    PrintArrayWithBrackets(numbers, count); // 15 25 35 45 55
    AddWithBrackets(numbers, count, 10);    // main의 원본 원소에 각각 10을 더한다.
    std::cout << "[] 매개변수로 수정 후: ";
    PrintArrayWithBrackets(pNumbers, count); // 포인터로 호출해도 된다. 25 35 45 55 65
    std::cout << "main에서 원본 확인: " << numbers[0] << '\n'; // 25

    return 0;
}

// [출력] 포인터로 받았어도 []로 원소를 읽을 수 있다.
void PrintArray(const int* pNumbers, int count)
{
    for (int i = 0; i < count; ++i)
    {
        std::cout << pNumbers[i] << ' ';
        // pNumbers[i] = 0; // const이므로 이 포인터로 값을 바꾸면 컴파일 오류이다.
    }
    std::cout << '\n';
}

// [합계] 같은 원소 접근을 포인터 덧셈과 역참조로 표현한다.
int SumArray(const int* pNumbers, int count)
{
    int sum = 0;
    for (int i = 0; i < count; ++i)
    {
        sum += *(pNumbers + i); // pNumbers[i]와 같다.
    }
    return sum;
}

// [수정] 전달받은 주소를 통해 원본 원소를 바꾸므로 const를 붙이지 않는다.
void AddToArray(int* pNumbers, int count, int amount)
{
    for (int i = 0; i < count; ++i)
    {
        pNumbers[i] += amount;
    }
}

// [배열 표기로 출력] const int arr[]는 매개변수에서 const int* arr와 같다.
// 실제 배열 복사본을 받은 것이 아니므로 길이는 여전히 count로 따로 받는다.
void PrintArrayWithBrackets(const int arr[], int count)
{
    for (int i = 0; i < count; ++i)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';
}

// [배열 표기로 수정] int arr[]는 매개변수에서 int* arr와 같다.
// []를 썼어도 원본을 바꾼다. 함수 안의 sizeof(arr)는 배열 크기가 아닌 포인터 크기이다.
void AddWithBrackets(int arr[], int count, int amount)
{
    for (int i = 0; i < count; ++i)
    {
        arr[i] += amount;
    }
}
