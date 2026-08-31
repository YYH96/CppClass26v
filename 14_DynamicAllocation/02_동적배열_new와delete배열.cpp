#include <iostream>

/*
	실행 중 입력한 크기로 배열을 만들 때 동적 배열을 사용합니다.

	new int[count]{} : int count개를 만들고 모두 0으로 초기화합니다.
	delete[] values  : new[]로 만든 배열을 해제합니다.

	중요: new[]에는 delete[]를 사용합니다.
*/

int main()
{
	int count = 0;
	std::cout << "배열 크기를 입력하세요: ";
	std::cin >> count;

	if (count <= 0)
	{
		std::cout << "배열 크기는 1 이상이어야 합니다.\n";
		return 0;
	}

	int* values = new int[count]{}; // 입력받은 크기만큼 힙에 배열 생성

	for (int i = 0; i < count; ++i)
	{
		values[i] = (i + 1) * 10;
	}

	std::cout << "배열 값: ";
	for (int i = 0; i < count; ++i)
	{
		std::cout << values[i] << ' ';
	}
	std::cout << '\n';

	delete[] values; // 배열 전체를 해제
	values = nullptr;

	return 0;
}
