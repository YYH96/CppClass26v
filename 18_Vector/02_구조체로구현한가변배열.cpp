/*
    구조체로 직접 만드는 int 가변 배열

    std::vector<int>가 내부에서 하는 핵심 일을 아주 단순하게 구현한 예제입니다.

    - mValues   : 실제 int 값들이 저장되는 동적 배열
    - mSize     : 현재 저장한 원소 개수
    - mCapacity : 현재 확보해 둔 최대 공간

    실제 std::vector에는 복사/이동, 예외 처리, 반복자 등 훨씬 많은 기능이 있습니다.
    이 예제는 가변 배열의 동작 원리를 보는 것이 목적입니다.
*/

#include <iostream>

struct IntVector
{
    // 조사식에 numbers.mValues, numbers.mSize 를 입력하면 모든 원소를 볼 수 있다.
    // 이 프로젝트의 IntVector.natvis 파일을 적용하면 numbers만 펼쳐도 [0], [1]...이 보인다.
    int* mValues = nullptr;
    int mSize = 0;
    int mCapacity = 0;

    // 동적으로 할당한 배열은 사용이 끝나면 반드시 해제한다.
    ~IntVector()
    {
        delete[] mValues;
    }

    // 필요한 최소 공간보다 현재 공간이 작을 때만, 더 큰 배열을 만든다.
    void Reserve(int newCapacity)
    {
        if (newCapacity <= mCapacity)
        {
            return; // 이미 충분한 공간이 있다.
        }

        int* newValues = new int[newCapacity];

        // 기존 값을 새 배열로 복사한다.
        for (int i = 0; i < mSize; ++i)
        {
            newValues[i] = mValues[i];
        }

        delete[] mValues;
        mValues = newValues;
        mCapacity = newCapacity;
    }

    // 맨 뒤에 원소를 하나 추가한다.
    void PushBack(int value)
    {
        if (mSize == mCapacity)
        {
            // 공간이 없으면 1칸 또는 기존의 2배만큼 확보한다.
            const int newCapacity = (mCapacity == 0) ? 1 : mCapacity * 2;
            Reserve(newCapacity);
        }

        mValues[mSize] = value;
        ++mSize;
    }

    // 맨 뒤 원소 하나를 제거한다.
    void PopBack()
    {
        if (mSize == 0)
        {
            return; // 비어 있으면 제거할 원소가 없다.
        }

        --mSize;
        // int는 별도의 소멸 작업이 없으므로 mSize만 줄이면 된다.
    }

    // 원소 개수를 newSize로 바꾼다.
    void Resize(int newSize)
    {
        if (newSize < 0)
        {
            return;
        }

        if (newSize > mCapacity)
        {
            Reserve(newSize);
        }

        // 크기를 늘린 경우, 새로 생긴 원소를 0으로 초기화한다.
        for (int i = mSize; i < newSize; ++i)
        {
            mValues[i] = 0;
        }

        mSize = newSize;
    }

    // 모든 원소를 비운다. 이미 확보한 배열 공간은 다음 추가를 위해 유지한다.
    void Clear()
    {
        mSize = 0;
    }

    // operator[]: 배열처럼 IntVector에 임의 접근할 수 있게 한다.
    // 범위를 검사하지 않으므로 0 이상 mSize 미만의 인덱스만 넣어야 한다.
    int& operator[](int index)
    {
        return mValues[index];
    }
};

void PrintVector(const IntVector& values)
{
    std::cout << "값: ";

    for (int i = 0; i < values.mSize; ++i)
    {
        std::cout << values.mValues[i] << ' ';
    }

    std::cout << "(size: " << values.mSize
        << ", capacity: " << values.mCapacity << ")\n";
}

int main()
{
    IntVector numbers;

    // PushBack: 값 추가. 공간이 모자라면 내부 배열의 크기를 늘린다.
    numbers.PushBack(10);
    numbers.PushBack(20);
    numbers.PushBack(30);
    PrintVector(numbers);

    // operator[]: 배열처럼 원하는 위치의 값을 읽거나 바꾼다.
    numbers[1] = 200;
    std::cout << "numbers[1]: " << numbers[1] << '\n';
    PrintVector(numbers);

    // PopBack: 마지막 값 30을 제거한다.
    numbers.PopBack();
    PrintVector(numbers);

    // Resize: 원소 개수를 5개로 늘린다. 새로 생긴 원소는 0이다.
    numbers.Resize(5);
    PrintVector(numbers);

    // Reserve: 원소 개수는 그대로 두고, 미리 10칸의 공간을 확보한다.
    numbers.Reserve(10);
    PrintVector(numbers);

    numbers.Reserve(5);
    PrintVector(numbers);

    // Clear: 원소만 비우며 확보한 공간(capacity)은 유지한다.
    numbers.Clear();
    PrintVector(numbers);

    return 0;
}
