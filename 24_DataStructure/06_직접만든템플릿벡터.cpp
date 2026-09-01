/*
    직접 구현한 템플릿 벡터

    STL vector 예제는 18번 프로젝트에서 다뤘다.
    여기서는 어떤 자료형이든 저장할 수 있는 가변 배열을 직접 구현한다.
*/

#include <cassert>
#include <iostream>
#include <string>

template<typename T>
class MyVector
{
private:
    T* mValues = nullptr;
    int mSize = 0;
    int mCapacity = 0;

public:
    MyVector() = default;

    ~MyVector()
    {
        delete[] mValues;
    }

    MyVector(const MyVector&) = delete;

    // 대입 연산자는 다른 벡터의 배열을 새로 만들어 깊은 복사한다.
    MyVector& operator=(const MyVector& other)
    {
        if (this == &other)
        {
            return *this;
        }

        T* newValues = nullptr;

        if (other.mCapacity > 0)
        {
            newValues = new T[other.mCapacity];

            for (int index = 0; index < other.mSize; ++index)
            {
                newValues[index] = other.mValues[index];
            }
        }

        delete[] mValues;
        mValues = newValues;
        mSize = other.mSize;
        mCapacity = other.mCapacity;

        return *this;
    }

    void PushBack(const T& value)
    {
        if (mSize == mCapacity)
        {
            const int newCapacity = (mCapacity == 0) ? 1 : mCapacity * 2;
            ReAllocate(newCapacity);
        }

        mValues[mSize] = value;
        ++mSize;
    }

    void PopBack()
    {
        assert(!Empty());
        --mSize;
    }

    // size는 바꾸지 않고, 필요한 공간만 미리 확보한다.
    void Reserve(int newCapacity)
    {
        if (newCapacity > mCapacity)
        {
            ReAllocate(newCapacity);
        }
    }

    // 원소 개수를 바꾼다. 크기를 늘리면 새 원소는 T{}로 초기화한다.
    void Resize(int newSize)
    {
        assert(newSize >= 0);

        if (newSize > mCapacity)
        {
            ReAllocate(newSize);
        }

        for (int index = mSize; index < newSize; ++index)
        {
            mValues[index] = T{};
        }

        mSize = newSize;
    }

    T& operator[](int index)
    {
        assert(index >= 0 && index < mSize);
        return mValues[index];
    }

    const T& operator[](int index) const
    {
        assert(index >= 0 && index < mSize);
        return mValues[index];
    }

    int Size() const
    {
        return mSize;
    }

    int Capacity() const
    {
        return mCapacity;
    }

    bool Empty() const
    {
        return mSize == 0;
    }

private:
    void ReAllocate(int newCapacity)
    {
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

template<typename T>
void PrintVector(const MyVector<T>& values)
{
    std::cout << "값: ";

    for (int index = 0; index < values.Size(); ++index)
    {
        std::cout << values[index] << ' ';
    }

    std::cout << "size: " << values.Size() << ", capacity: " << values.Capacity() << '\n';
}

int main()
{
    MyVector<std::string> inventory;

    inventory.PushBack("검");
    inventory.PushBack("방패");
    inventory.PushBack("회복 물약");
    PrintVector(inventory);

    inventory[1] = "강철 방패";
    PrintVector(inventory);

    inventory.PopBack();
    inventory.Resize(4);
    inventory[2] = "회복 물약";
    inventory[3] = "열쇠";
    PrintVector(inventory);

    inventory.Reserve(10);
    PrintVector(inventory);

    // 대입 연산자는 내부 배열까지 복사한다.
    MyVector<std::string> backupInventory;
    backupInventory = inventory;
    backupInventory[0] = "전설의 검";

    std::cout << "원본 인벤토리\n";
    PrintVector(inventory);
    std::cout << "복사본 인벤토리\n";
    PrintVector(backupInventory);

    return 0;
}
