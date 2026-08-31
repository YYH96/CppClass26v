#include <iostream>

/*
	함수 매개변수 비교
	- 값 전달      : 복사본을 받으므로 원본은 변하지 않습니다.
	- 포인터 전달  : 주소를 받아 *pointer로 원본을 바꿉니다. nullptr 검사가 필요할 수 있습니다.
	- 참조 전달    : 원본의 별칭을 받아 변수처럼 원본을 바꿉니다. 반드시 유효한 대상이 있어야 합니다.
*/

void Add100ByValue(int value)
{
	value += 100;
	std::cout << "함수 안 값 전달 value: " << value << '\n';
}

void Add100ByPointer(int* value)
{
	if (value == nullptr)
	{
		return;
	}

	*value += 100;
}

void Add100ByReference(int& value)
{
	value += 100;
}

int main()
{
	int score = 10;

	std::cout << "초기 score: " << score << "\n\n";

	Add100ByValue(score);
	std::cout << "값 전달 뒤 score: " << score << "  // 원본이 변하지 않음\n\n";

	Add100ByPointer(&score);
	std::cout << "포인터 전달 뒤 score: " << score << "  // 원본이 변함\n\n";

	Add100ByReference(score);
	std::cout << "참조 전달 뒤 score: " << score << "  // 원본이 변함\n";

	return 0;
}
