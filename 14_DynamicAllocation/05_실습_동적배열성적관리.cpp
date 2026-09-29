/*
	동적 배열 실습: 입력한 학생 수만큼 성적을 저장하고 평균을 구합니다.

	확인할 점
	1. 학생 수를 입력받아 new[]로 동적 배열을 만듭니다.
	2. 반복문으로 각 점수를 입력받습니다.
	3. 합계와 평균을 계산합니다.
	4. 모든 경로에서 delete[]로 배열을 해제합니다.
*/
#include <iostream>
#include <string>

class Student
{
public:
    std::string Name;
    int Kor = 0;
    int Eng = 0;
    int Math = 0;

    void Input()
    {
        std::cout << "이름: ";
        std::cin >> Name;

        std::cout << "국어 영어 수학 점수: ";
        std::cin >> Kor >> Eng >> Math;
    }

    static void PrintAverage(const Student students[], int count)
    {
        if (count <= 0)
            return;

        double korTotal = 0;
        double engTotal = 0;
        double mathTotal = 0;

        for (int i = 0; i < count; ++i)
        {
            korTotal += students[i].Kor;
            engTotal += students[i].Eng;
            mathTotal += students[i].Math;
        }

        double total = korTotal + engTotal + mathTotal;

        std::cout << "\n국어 평균: " << korTotal / count
            << " / 영어 평균: " << engTotal / count
            << " / 수학 평균: " << mathTotal / count
            << " / 합계 평균: " << total / count
            << '\n';
    }
};

int main()
{
    int count = 0;

    std::cout << "학생 수: ";
    std::cin >> count;

    if (count <= 0)
        return 0;

    Student* students = new Student[count];

    for (int i = 0; i < count; ++i)
    {
        std::cout << "\n" << i + 1 << "번 학생\n";
        students[i].Input();
    }

    Student::PrintAverage(students, count);

    delete[] students;
    students = nullptr;

    return 0;
}