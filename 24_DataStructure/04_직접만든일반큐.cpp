/*
    직접 구현한 일반 큐

    pop할 때 front 인덱스가 계속 증가한다.
    앞쪽 빈 공간을 즉시 재사용하지 못하는 한계를 원형 큐와 비교한다.
*/

#include <cassert>
#include <iostream>

template<typename T>
class MyQueue
{
private:
    T* mValues = nullptr;
    int mFront = 0;
    int mSize = 0;
    int mCapacity = 0;

public :
	MyQueue() = default;
    ~MyQueue()
    {
        delete[] mValues;
    }

    MyQueue(const MyQueue&) = delete;
    MyQueue& operator=(const MyQueue&) = delete;

    void Push(const T& value)
    {
        if (mFront + mSize == mCapacity)
        {
            ReAllocate();
        }

        mValues[mFront + mSize] = value;
        ++mSize;
    }

    void Pop()
    {
        assert(!Empty());
        ++mFront;
        --mSize;
    }

    const T& Front() const
    {
        assert(!Empty());
        return mValues[mFront];
    }

    const T& Back() const
    {
        assert(!Empty());
        return mValues[mFront + mSize - 1];
    }

    int Size() const
    {
        return mSize;
    }

    bool Empty() const
    {
        return mSize == 0;
    }

private:
    void ReAllocate()
    {
        const int newCapacity = (mCapacity == 0) ? 2 : mCapacity * 2;
        T* newValues = new T[newCapacity];

        // 현재 큐에 남은 데이터만 앞쪽부터 다시 복사한다.
        for (int index = 0; index < mSize; ++index)
        {
            newValues[index] = mValues[mFront + index];
        }

        delete[] mValues;
        mValues = newValues;
        mCapacity = newCapacity;
        mFront = 0;
    }
};

int main()
{
    MyQueue<int> numbers;

    numbers.Push(10);
    numbers.Push(20);
    numbers.Push(30);
    numbers.Pop();
    numbers.Push(40);

    std::cout << "맨 앞 데이터: " << numbers.Front() << '\n';
    std::cout << "맨 뒤 데이터: " << numbers.Back() << '\n';

    while (!numbers.Empty())
    {
        std::cout << numbers.Front() << '\n';
        numbers.Pop();
    }

    return 0;
}
