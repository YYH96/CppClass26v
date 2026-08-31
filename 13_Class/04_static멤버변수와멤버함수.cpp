#include <iostream>
#include <string>

/*
	static 멤버 변수
	- 객체마다 하나씩 생기는 일반 멤버 변수와 달리, 클래스 전체가 하나만 공유합니다.
	- 생성한 몬스터의 총 수처럼 모든 객체가 함께 보는 값에 사용합니다.

	static 멤버 함수
	- 객체 없이 클래스 이름으로 호출할 수 있습니다.
	- 특정 객체의 일반 멤버 변수(mName 등)는 직접 사용할 수 없습니다.
	- static 멤버 변수처럼 클래스 전체가 공유하는 값은 사용할 수 있습니다.
*/

class Monster
{
private:
	std::string mName;
	static int sCreatedCount; // 모든 Monster 객체가 공유하는 변수

public:
	Monster(const std::string& name)
		: mName(name)
	{
		++sCreatedCount;
		std::cout << mName << " 생성\n";
	}

	~Monster()
	{
		--sCreatedCount;
		std::cout << mName << " 소멸\n";
	}

	static int GetCreatedCount()
	{
		return sCreatedCount;
		// return mName; // 오류: 어떤 객체의 mName인지 알 수 없습니다.
	}
};

// static 멤버 변수의 실제 저장 공간은 클래스 밖에서 한 번 정의합니다.
int Monster::sCreatedCount = 0;

int main()
{
	std::cout << "현재 몬스터 수: " << Monster::GetCreatedCount() << '\n';

	Monster slime("슬라임");
	Monster goblin("고블린");

	// 객체 이름 대신 클래스 이름으로 호출합니다.
	std::cout << "현재 몬스터 수: " << Monster::GetCreatedCount() << '\n';

	return 0; // main 종료 후 slime, goblin이 소멸하며 카운트도 감소합니다.
}
