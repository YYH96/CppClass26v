#include <iostream>

/*
	동적 배열 실습: 입력한 학생 수만큼 성적을 저장하고 평균을 구합니다.

	확인할 점
	1. 학생 수를 입력받아 new[]로 동적 배열을 만듭니다.
	2. 반복문으로 각 점수를 입력받습니다.
	3. 합계와 평균을 계산합니다.
	4. 모든 경로에서 delete[]로 배열을 해제합니다.
*/

int main()
{
	int studentCount = 0;
	std::cout << "학생 수를 입력하세요: ";
	std::cin >> studentCount;

	if (studentCount <= 0)
	{
		std::cout << "학생 수는 1 이상이어야 합니다.\n";
		return 0;
	}

	int* scores = new int[studentCount]{};
	int total = 0;

	for (int i = 0; i < studentCount; ++i)
	{
		std::cout << i + 1 << "번 학생의 점수: ";
		std::cin >> scores[i];
		total += scores[i];
	}

	const float average = static_cast<float>(total) / studentCount;

	std::cout << "\n[성적 결과]\n";
	for (int i = 0; i < studentCount; ++i)
	{
		std::cout << i + 1 << "번 학생: " << scores[i] << "점\n";
	}
	std::cout << "합계: " << total << "점\n";
	std::cout << "평균: " << average << "점\n";

	delete[] scores;
	scores = nullptr;

	return 0;
}
