#include <iostream>

/*
	파생 객체 생성과 소멸 순서

	생성: 기반 클래스 -> 파생 클래스
	소멸: 파생 클래스 -> 기반 클래스

	파생 클래스는 기반 클래스 부분을 포함합니다.
	따라서 기반 부분을 먼저 준비하고, 제거할 때는 파생 부분을 먼저 정리합니다.
*/

class Character
{
public:
	Character()
	{
		std::cout << "1. Character 생성자 호출\n";
	}

	~Character()
	{
		std::cout << "4. Character 소멸자 호출\n";
	}
};

class Warrior : public Character
{
public:
	Warrior()
	{
		std::cout << "2. Warrior 생성자 호출\n";
	}

	~Warrior()
	{
		std::cout << "3. Warrior 소멸자 호출\n";
	}
};

int main()
{
	std::cout << "Warrior 객체 생성\n";

	{
		Warrior warrior;
		std::cout << "객체 사용 중\n";
	} // 블록을 벗어나면 Warrior -> Character 순서로 소멸합니다.

	std::cout << "main 함수 종료\n";
	return 0;
}
