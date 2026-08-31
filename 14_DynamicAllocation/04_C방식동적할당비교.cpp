#include <cstdlib> // std::malloc, std::calloc, std::realloc, std::free
#include <iostream>

/*
	C 방식 동적 할당
	- malloc : 초기화하지 않은 바이트 메모리 확보
	- calloc : 개수 * 요소 크기만큼 확보하고 모든 비트를 0으로 설정
	- realloc: 기존 블록의 크기를 변경. 반환 주소가 바뀔 수 있습니다.
	- free   : C 방식 메모리 해제

	C++의 new/delete와 섞어 사용하면 안 됩니다.
	- new / delete, new[] / delete[]
	- malloc, calloc, realloc / free
*/

int main()
{
	const int firstCount = 3;
	int* values = static_cast<int*>(std::calloc(firstCount, sizeof(int)));

	if (values == nullptr)
	{
		std::cout << "메모리 할당에 실패했습니다.\n";
		return 0;
	}

	std::cout << "calloc 초기값: ";
	for (int i = 0; i < firstCount; ++i)
	{
		std::cout << values[i] << ' '; // 0 0 0
	}
	std::cout << '\n';

	values[0] = 10;
	values[1] = 20;
	values[2] = 30;

	const int expandedCount = 5;
	// realloc이 실패하면 nullptr을 반환하지만, 기존 values는 여전히 유효합니다.
	// 그래서 반환값을 곧바로 values에 넣지 않고 임시 포인터로 확인합니다.
	int* resizedValues = static_cast<int*>(std::realloc(values, expandedCount * sizeof(int)));
	if (resizedValues == nullptr)
	{
		std::cout << "배열 크기 변경에 실패했습니다.\n";
		std::free(values);
		return 0;
	}

	values = resizedValues;
	values[3] = 40; // realloc으로 새로 늘어난 부분은 직접 값을 넣습니다.
	values[4] = 50;

	std::cout << "realloc 후: ";
	for (int i = 0; i < expandedCount; ++i)
	{
		std::cout << values[i] << ' ';
	}
	std::cout << '\n';

	std::free(values); // calloc/realloc으로 확보한 메모리는 free로 해제
	values = nullptr;

	return 0;
}
