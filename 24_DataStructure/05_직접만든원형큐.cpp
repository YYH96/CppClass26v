/*
    직접 구현한 원형 큐

    배열의 끝에 도착하면 처음 인덱스로 돌아간다.
    일반 큐에서 pop 후 앞쪽에 생기는 빈 공간을 재사용할 수 있다.
*/

#include <cassert>
#include <iostream>

template<typename T>
class MyCircularQueue
{
private:
    T* mValues = nullptr;
    int mFront = 0;
    int mBack = 0;
    int mSize = 0;
    int mCapacity = 0;

public:
    MyCircularQueue() = default;

    ~MyCircularQueue()
    {
        delete[] mValues;
    }

    MyCircularQueue(const MyCircularQueue&) = delete;
    MyCircularQueue& operator=(const MyCircularQueue&) = delete;

    void Push(const T& value)
    {
        if (mSize == mCapacity)
        {
            ReAllocate();
        }

        mValues[mBack] = value;
        mBack = (mBack + 1) % mCapacity;
        ++mSize;
    }

    void Pop()
    {
        assert(!Empty());
        mFront = (mFront + 1) % mCapacity;
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
        const int backIndex = (mBack - 1 + mCapacity) % mCapacity;
        return mValues[backIndex];
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

        // 원형으로 흩어진 데이터를 논리적인 순서대로 0번부터 복사한다.
        for (int index = 0; index < mSize; ++index)
        {
            newValues[index] = mValues[(mFront + index) % mCapacity];
        }

        delete[] mValues;
        mValues = newValues;
        mCapacity = newCapacity;
        mFront = 0;
        mBack = mSize;
    }
};

int main()
{
    MyCircularQueue<int> numbers;

    numbers.Push(10);
    numbers.Push(20);
    numbers.Push(30);
    numbers.Pop();
    numbers.Pop();
    numbers.Push(40);
    numbers.Push(50);
    numbers.Push(60);

    std::cout << "맨 앞 데이터: " << numbers.Front() << '\n';
    std::cout << "맨 뒤 데이터: " << numbers.Back() << '\n';

    while (!numbers.Empty())
    {
        std::cout << numbers.Front() << '\n';
        numbers.Pop();
    }

    return 0;
}
