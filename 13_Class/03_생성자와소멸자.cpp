#include <iostream>
#include <string>

/*
	생성자(Constructor)
	- 객체가 생성될 때 자동으로 호출됩니다.
	- 클래스와 이름이 같고 반환형이 없습니다.
	- 초기값을 준비하는 데 사용합니다.
	- 매개변수 형태를 다르게 여러 개 만들 수 있습니다. (생성자 오버로딩)

	소멸자(Destructor)
	- 객체의 생명주기가 끝날 때 자동으로 호출됩니다.
	- ~클래스이름() 형태이며 반환형과 매개변수가 없습니다.
	- 한 클래스에는 소멸자를 하나만 만들 수 있습니다.
*/

class Monster
{
private:
	std::string mName;
	int mHp;

public:
	// 기본 생성자: Monster monster;처럼 만들 때 호출됩니다.
	Monster()
		: mName("슬라임"), mHp(30) // 멤버 초기화 목록
	{
		std::cout << "기본 생성자 호출: " << mName << " 생성\n";
	}

	// 매개변수 생성자: 원하는 초기값으로 객체를 만들 수 있습니다.
	Monster(const std::string& name, int hp)
		: mName(name), mHp(hp)
	{
		std::cout << "매개변수 생성자 호출: " << mName << " 생성\n";
	}

	~Monster()
	{
		std::cout << "소멸자 호출: " << mName << " 제거\n";
	}

	void PrintInfo() const
	{
		std::cout << mName << " / HP: " << mHp << '\n';
	}
};

int main()
{
	std::cout << "main 함수 시작\n";

	Monster defaultMonster;
	Monster boss("고블린 대장", 150);

	defaultMonster.PrintInfo();
	boss.PrintInfo();

	{
		Monster temporaryMonster("연습용 몬스터", 10);
		std::cout << "중괄호 블록 안\n";
	} // temporaryMonster는 블록을 벗어나며 여기서 먼저 소멸합니다.

	std::cout << "main 함수 종료 직전\n";
	return 0; // boss, defaultMonster는 생성의 반대 순서로 소멸합니다.
}
