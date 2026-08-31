#include <iostream>
#include <utility> // std::move

/*
	이동 생성자(Move Constructor)
	- 형태: 클래스이름(클래스이름&& other) noexcept
	- 기존 객체가 소유한 힙 메모리의 소유권을 새 객체로 넘깁니다.
	- 큰 배열을 새로 할당하고 하나씩 복사하는 비용을 줄일 수 있습니다.

	std::move는 실제로 데이터를 옮기는 함수가 아닙니다.
	이동 생성자가 선택될 수 있도록 객체를 이동 가능한 형태로 바꾸는 역할입니다.
*/

class DynamicArray
{
private:
	int* mValues;
	int mSize;

public:
	DynamicArray(int size)
		: mValues(new int[size]{}), mSize(size)
	{
		for (int i = 0; i < mSize; ++i)
		{
			mValues[i] = (i + 1) * 10;
		}
		std::cout << "일반 생성자: " << mValues << "에 배열 생성\n";
	}

	DynamicArray(const DynamicArray& other)
		: mValues(new int[other.mSize]), mSize(other.mSize)
	{
		for (int i = 0; i < mSize; ++i)
		{
			mValues[i] = other.mValues[i];
		}
		std::cout << "복사 생성자: 새 배열 " << mValues << "를 만들어 값 복사\n";
	}

	DynamicArray(DynamicArray&& other) noexcept
		: mValues(other.mValues), mSize(other.mSize)
	{
		// 원본이 더 이상 같은 메모리를 소유하지 않도록 비운 상태로 만듭니다.
		other.mValues = nullptr;
		other.mSize = 0;
		std::cout << "이동 생성자: 기존 배열의 소유권을 받음\n";
	}

	~DynamicArray()
	{
		delete[] mValues; // nullptr도 delete[]할 수 있으므로 이동된 원본도 안전합니다.
	}

	void PrintInfo(const char* label) const
	{
		std::cout << label << " / 주소: " << mValues << ", 크기: " << mSize << ", 값: ";
		for (int i = 0; i < mSize; ++i)
		{
			std::cout << mValues[i] << ' ';
		}
		std::cout << '\n';
	}
};

int main()
{
	DynamicArray original(3);
	DynamicArray copied = original; // 복사 생성자: 새 배열을 만들어 값 복사
	DynamicArray moved = std::move(original); // 이동 생성자: original의 배열 주소를 넘겨받음

	std::cout << '\n';
	original.PrintInfo("이동 후 원본"); // 유효하지만 이 예제에서는 비어 있는 상태
	copied.PrintInfo("복사본");
	moved.PrintInfo("이동받은 객체");

	return 0;
}
