/*
    이차원 배열과 배열 포인터 - 07번의 일차원 배열 전달 다음 단계

    [1. 이차원 배열은 행 배열들을 원소로 가진 배열]
    int numbers[2][3]은 int 3개짜리 행 배열이 2개 있는 배열이다.
    행(row)은 가로 한 줄, 열(column)은 세로 한 줄이다.
    numbers[행][열] 순서로 접근하며 인덱스는 각각 0부터 시작한다.

                  열 0   열 1   열 2
        행 0        10     20     30
        행 1        40     50     60

    numbers[1][2]는 두 번째 행, 세 번째 열의 60이다.
    유효한 행 인덱스는 0~1, 열 인덱스는 0~2이다.
    메모리에는 10, 20, 30, 40, 50, 60 순서로 연속해서 저장된다.
    연속되어 있어도 numbers[0][3]처럼 한 행의 열 범위를 넘겨 접근하면 안 된다.

    [2. 이차원 배열을 포인터로 보관하기]
    int (*pRows)[3] = numbers;
    pRows는 'int 3개짜리 배열 한 개'를 가리키는 배열 포인터이다.
    이때 numbers는 첫 번째 행을 가리키는 포인터로 변환된다.
    pRows에는 &numbers[0]이 저장되며, 배열 전체를 복사하지 않는다.

    pRows + 1       : 다음 행의 주소. int 3개만큼 이동한다.
    *(pRows + 1)    : 두 번째 행 배열.
    *(pRows + 1) + 2: 두 번째 행의 세 번째 int 원소 주소.
    *(*(pRows + 1) + 2): 그 원소의 값 60. pRows[1][2]와 같다.

    int* pElement = &numbers[0][0];은 첫 행의 첫 int를 가리킨다.
    pElement + 1은 int 1개만큼, pRows + 1은 int 3개만큼 이동한다.
    포인터가 가리키는 타입에 따라 한 번 더할 때 이동하는 크기가 다르다.

    [3. 배열 포인터와 포인터 배열 구분]
    int (*pRows)[3] : 배열 포인터. int 3개짜리 행을 가리키는 포인터 변수 한 개.
    int* rowPointers[2] : 포인터 배열. int* 포인터 변수 2개를 저장한 배열.
    괄호 유무가 의미를 바꾼다. 두 선언은 서로 다른 자료형이다.
    int**는 int* 변수를 가리키는 타입이므로 numbers를 바로 받을 수 없다.
    아래 코드에서 별도의 포인터 배열을 만들고 int**로 받는 경우와 비교한다.

    [4. 함수에 전달하기]
    void PrintMatrix(int pRows[][3], int rowCount);
    void PrintMatrix(int (*pRows)[3], int rowCount);
    위 두 선언은 함수 매개변수에서 같은 타입을 뜻한다.
    열 개수 3은 한 행의 크기와 다음 행의 주소를 계산하는 데 필요하다.
    행 개수는 포인터에 포함되지 않으므로 rowCount로 따로 전달한다.
    이 예제의 함수는 열 개수가 3인 배열 전용이다. [2][4] 배열은 전달할 수 없다.
    const는 필수가 아니다. 여기서는 기본 문법에 집중하도록 const 없이 받는다.
    읽기 전용으로 제한하고 싶을 때 const int arr[][3]을 사용할 수 있다.
*/

#include <iostream>

// 기본 예제는 읽기 쉬운 [][3] 표기로 선언하고 정의한다. const는 필수가 아니다.
void PrintMatrix(int pRows[][3], int rowCount);
void PrintRowSums(int pRows[][3], int rowCount);
void PrintColumnSums(int pRows[][3], int rowCount);
void AddToMatrix(int pRows[][3], int rowCount, int amount);

// 아래는 전달 문법을 비교하는 예제이다. 타입이 같은 표기는 이름을 다르게 붙였다.
void PrintWithSizes(int arr[2][3], int rowCount); // 첫 크기 2는 실제 행 수를 강제하지 않는다.
void PrintWithArrayPointer(int (*arr)[3], int rowCount); // [][3]과 같은 타입
void PrintWithDoublePointer(int** arr, int rowCount, int columnCount);
void PrintWithPointerArray(int* arr[], int rowCount, int columnCount); // int**와 같은 타입

int main()
{
    // 작은 중괄호 하나가 한 행이다. 두 행 모두 열 개수는 3이다.
    int numbers[2][3] = {
        { 10, 20, 30 },
        { 40, 50, 60 }
    };
    // main에서는 실제 배열이므로 전체 크기를 한 행의 크기로 나누어 행 수를 구한다.
    int rowCount = static_cast<int>(sizeof(numbers) / sizeof(numbers[0]));

    std::cout << "[1] 행과 열로 출력\n";
    PrintMatrix(numbers, rowCount);
    std::cout << "numbers[1][2]: " << numbers[1][2] << '\n'; // 60

    // int*가 아니라 int 3개짜리 배열을 가리키는 포인터에 보관한다.
    int (*pRows)[3] = numbers;
    int* pElement = &numbers[0][0];
    std::cout << "\n[2] 포인터가 이동하는 단위 비교\n";
    std::cout << "첫 행 주소: " << pRows << '\n';
    std::cout << "&numbers[0]: " << &numbers[0] << '\n';
    std::cout << "다음 행 주소: " << pRows + 1 << '\n';
    std::cout << "첫 int 주소: " << pElement << '\n';
    std::cout << "다음 int 주소: " << pElement + 1 << '\n';
    std::cout << "한 행 크기: " << sizeof(*pRows) << "바이트\n";
    std::cout << "한 int 크기: " << sizeof(*pElement) << "바이트\n";
    std::cout << "포인터 변수 크기: " << sizeof(pRows) << "바이트\n";
    // 주소의 시작 위치가 같아도 가리키는 타입과 이동 단위는 다르다.
    std::cout << "pRows[1][2]: " << pRows[1][2] << '\n';
    std::cout << "*(*(pRows + 1) + 2): " << *(*(pRows + 1) + 2) << '\n';

    // 포인터는 배열과 달리 다른 행을 가리키도록 바꿀 수 있다.
    int (*pSecondRow)[3] = pRows + 1;
    std::cout << "두 번째 행의 첫 값: " << (*pSecondRow)[0] << '\n'; // 40
    // pSecondRow는 이미 마지막 행을 가리킨다. pSecondRow[1][0]은 범위 밖이다.

    std::cout << "\n[3] 행 합계와 열 합계\n";
    PrintRowSums(pRows, rowCount);    // 60, 150
    PrintColumnSums(pRows, rowCount); // 50, 70, 90

    std::cout << "\n[4] 포인터로 원본 수정\n";
    pRows[1][2] = 99; // 별도 복사본이 아니라 main의 numbers[1][2]를 수정한다.
    std::cout << "numbers[1][2]: " << numbers[1][2] << '\n'; // 99
    AddToMatrix(pRows, rowCount, 1); // 함수에서도 원본의 모든 원소에 1을 더한다.
    PrintMatrix(numbers, rowCount); // 첫 행 11 21 31 / 둘째 행 41 51 100

    std::cout << "\n[5] 포인터 배열과 int** 비교\n";
    // 별도 배열 두 칸에 각 행의 첫 int 주소를 저장한다. int 원소는 복사하지 않는다.
    int* rowPointers[2] = { numbers[0], numbers[1] };
    int** ppRows = rowPointers; // 첫 int* 원소를 가리키므로 이번에는 int**가 맞다.
    std::cout << "ppRows[1][2]: " << ppRows[1][2] << '\n'; // 100
    // ppRows + 1은 다음 int* 저장 칸으로 이동한다. 원본의 다음 행으로 직접 이동하지 않는다.
    // ppRows[1]에 저장된 int*를 읽은 뒤, 그 포인터로 세 번째 int에 접근한다.
    // int** wrong = numbers; // 컴파일 오류: int (*)[3]을 int**에 대입할 수 없다.
    // 강제 형변환으로 해결하려 해도 int 데이터가 int* 저장 칸으로 바뀌지는 않는다.

    std::cout << "\n[6] 같은 이차원 배열을 세 가지 매개변수 표기로 전달\n";
    // 다음 세 함수 모두 첫 행의 주소를 받는다. 호출할 때 강제 형변환은 필요 없다.
    std::cout << "int arr[][3]\n";
    PrintMatrix(numbers, rowCount);
    std::cout << "int arr[2][3]\n";
    PrintWithSizes(numbers, rowCount);
    std::cout << "int (*arr)[3]\n";
    PrintWithArrayPointer(numbers, rowCount);

    // 매개변수의 첫 크기 [2]는 행 개수를 제한하지 않는다. 열 3개가 맞으면 전달된다.
    int threeRows[3][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
    std::cout << "[2][3] 매개변수에 3행 배열 전달 (rowCount는 3)\n";
    PrintWithSizes(threeRows, 3);

    std::cout << "\n[7] 행 주소 배열을 두 가지 매개변수 표기로 전달\n";
    // rowPointers는 위에서 만든 int* 배열이다. 각 칸에 원본 행의 주소가 들어 있다.
    // int**와 int* arr[]는 같은 매개변수 타입이며 열 수는 따로 전달한다.
    std::cout << "int** arr\n";
    PrintWithDoublePointer(rowPointers, rowCount, 3);
    std::cout << "int* arr[]\n";
    PrintWithPointerArray(rowPointers, rowCount, 3);
    // PrintWithDoublePointer(numbers, 2, 3); // 오류: 일반 이차원 배열을 바로 줄 수 없다.

    // 반드시 하나의 이차원 배열에서 행 주소를 가져올 필요는 없다.
    // 별개의 일차원 배열 두 개를 포인터 배열로 묶어서 전달할 수도 있다.
    int firstRow[4] = { 1, 2, 3, 4 };
    int secondRow[4] = { 5, 6, 7, 8 };
    int* separateRows[2] = { firstRow, secondRow };
    std::cout << "별개의 4칸 배열 두 개를 int** 함수로 전달\n";
    PrintWithDoublePointer(separateRows, 2, 4);
    // 각 행에는 columnCount개 이상 원소가 있어야 한다. 여기서는 두 행 모두 4칸이다.

    return 0;
}

// [출력] int pRows[][3]은 선언의 int (*pRows)[3]과 같은 매개변수이다.
void PrintMatrix(int pRows[][3], int rowCount)
{
    std::cout << "       열 0  열 1  열 2\n";
    for (int row = 0; row < rowCount; ++row)
    {
        std::cout << "행 " << row << " : ";
        for (int column = 0; column < 3; ++column)
        {
            std::cout << pRows[row][column] << "    ";
        }
        std::cout << '\n'; // 한 행을 모두 출력한 후 줄바꿈
    }
}

// [행 합계] 바깥 반복문은 행, 안쪽 반복문은 열. 한 행마다 합계를 0으로 다시 시작한다.
void PrintRowSums(int pRows[][3], int rowCount)
{
    for (int row = 0; row < rowCount; ++row)
    {
        int sum = 0;
        for (int column = 0; column < 3; ++column)
        {
            sum += pRows[row][column];
        }
        std::cout << row << "번 행 합계: " << sum << '\n';
    }
}

// [열 합계] 바깥 반복문은 열, 안쪽 반복문은 행. 같은 열을 위에서 아래로 더한다.
void PrintColumnSums(int pRows[][3], int rowCount)
{
    for (int column = 0; column < 3; ++column)
    {
        int sum = 0;
        for (int row = 0; row < rowCount; ++row)
        {
            sum += pRows[row][column];
        }
        std::cout << column << "번 열 합계: " << sum << '\n';
    }
}

// [수정] const 없이 받아 주소를 통해 원본 이차원 배열의 값을 변경한다.
void AddToMatrix(int pRows[][3], int rowCount, int amount)
{
    for (int row = 0; row < rowCount; ++row)
    {
        for (int column = 0; column < 3; ++column)
        {
            pRows[row][column] += amount;
        }
    }
}

// [크기를 모두 적는 표기] int arr[2][3]도 매개변수에서는 int (*arr)[3]으로 처리된다.
// 첫 크기 2가 자동으로 검사되는 것은 아니다. 실제 행 수는 rowCount를 사용한다.
void PrintWithSizes(int arr[2][3], int rowCount)
{
    // 같은 타입을 받는 기존 함수에 그대로 전달할 수 있다.
    PrintMatrix(arr, rowCount);
}

// [배열 포인터 표기] int arr[][3]과 완전히 같은 매개변수 타입이다.
// 이 표기만 바꿔 같은 함수 이름으로 두 구현을 만들면 오버로딩이 아니라 재정의 오류이다.
void PrintWithArrayPointer(int (*arr)[3], int rowCount)
{
    PrintMatrix(arr, rowCount);
}

// [이중 포인터 표기] arr[row]에서 그 행의 int* 주소를 먼저 읽는다.
// 그 뒤 [column]으로 실제 int 원소에 접근한다. 열 수가 타입에 없으므로 따로 받는다.
void PrintWithDoublePointer(int** arr, int rowCount, int columnCount)
{
    for (int row = 0; row < rowCount; ++row)
    {
        for (int column = 0; column < columnCount; ++column)
        {
            std::cout << arr[row][column] << ' ';
        }
        std::cout << '\n';
    }
}

// [포인터 배열 표기] 매개변수 int* arr[]는 int** arr로 처리된다.
// 지역 변수 int* rowPointers[2]는 실제 배열이지만, 함수에서는 첫 포인터 칸의 주소를 받는다.
void PrintWithPointerArray(int* arr[], int rowCount, int columnCount)
{
    PrintWithDoublePointer(arr, rowCount, columnCount);
}
