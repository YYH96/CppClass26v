#include <iostream>
#include <string>

/*
	클래스 실습: 학생 성적 관리
	
	목표
	1. 이름, 나이, 학번, 국어/영어/수학 점수는 private 멤버 변수로 둡니다.
	2. public 멤버 함수로 학생 정보와 성적을 입력받습니다.
	3. 합계와 평균을 계산하여 출력합니다.

	실습을 확장한다면
	- 점수 범위(0~100)를 검사해 보세요.
	- 여러 Student 객체를 만들어 성적을 비교해 보세요.
*/

class Student
{
private:
	std::string mName;
	int mAge;
	int mStudentId;
	int mKorean;
	int mEnglish;
	int mMath;

public:
	void InputBasicInfo()
	{
		std::cout << "이름, 나이, 학번을 입력하세요: ";
		std::cin >> mName >> mAge >> mStudentId;
	}

	void InputScores()
	{
		std::cout << "국어, 영어, 수학 점수를 입력하세요: ";
		std::cin >> mKorean >> mEnglish >> mMath;
	}

	int GetTotal() const
	{
		return mKorean + mEnglish + mMath;
	}

	float GetAverage() const
	{
		return GetTotal() / 3.0f; // 3.0f를 사용해 실수 나눗셈을 합니다.
	}

	void PrintInfo() const
	{
		std::cout << "\n[학생 정보]\n";
		std::cout << "이름: " << mName << '\n';
		std::cout << "나이: " << mAge << '\n';
		std::cout << "학번: " << mStudentId << '\n';
		std::cout << "국어: " << mKorean << ", 영어: " << mEnglish << ", 수학: " << mMath << '\n';
		std::cout << "합계: " << GetTotal() << ", 평균: " << GetAverage() << '\n';
	}
};

int main()
{
	Student student;

	student.InputBasicInfo();
	student.InputScores();
	student.PrintInfo();

	return 0;
}
