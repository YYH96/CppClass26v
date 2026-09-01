/*
    직접 구현한 템플릿 스택

    동적 배열과 size, capacity를 이용해 std::stack과 비슷한 기능을 만든다.
*/

#include <cassert>
#include <iostream>

template<typename T>
class MyStack
{
private:
    T* mValues = nullptr;
    int mSize = 0;
    int mCapacity = 0;

public:
    MyStack() = default;
    ~MyStack()
    {
        delete[] mValues;
    }

    MyStack(const MyStack&) = delete;
    MyStack& operator=(const MyStack&) = delete;

    void Push(const T& value)
    {
        if (mSize == mCapacity)
        {
            ReAllocate();
        }

        mValues[mSize] = value;
        ++mSize;
    }

    void Pop()
    {
        assert(!Empty());
        --mSize;
    }

    const T& Top() const
    {
        assert(!Empty());
        return mValues[mSize - 1];
    }

    int Size() const
    {
        return mSize;
    }

    bool Empty() const
    {
        return mSize == 0;
    }

    void Clear()
    {
        mSize = 0;
    }

private:
    void ReAllocate()
    {
        const int newCapacity = (mCapacity == 0) ? 1 : mCapacity * 2;
        T* newValues = new T[newCapacity];

        for (int index = 0; index < mSize; ++index)
        {
            newValues[index] = mValues[index];
        }

        delete[] mValues;
        mValues = newValues;
        mCapacity = newCapacity;
    }
};

int main()
{
    // numbers.mValues, [numbers.mSize] 조사식에서 모든 내부요소 보는 방법
    MyStack<int> numbers;

    numbers.Push(10);
    numbers.Push(20);
    numbers.Push(30);

    std::cout << "현재 크기: " << numbers.Size() << '\n';
    std::cout << "맨 위 데이터: " << numbers.Top() << '\n';

    numbers.Pop();
    std::cout << "pop 후 맨 위 데이터: " << numbers.Top() << '\n';

    numbers.Clear();
    std::cout << "clear 후 비었는가? " << numbers.Empty() << '\n';

    return 0;
}
