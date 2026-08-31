#include <iostream>
#include <string>

/*
	생성자(Constructor)
	- 객체가 생성될 때 자동으로 호출되어 멤버 변수의 초기 상태를 준비합니다.
	- 클래스 이름과 같고 반환형이 없습니다.
	- 매개변수 형태를 다르게 여러 개 만들 수 있습니다. (생성자 오버로딩)

	기본 생성자       : 매개변수가 없는 생성자
	매개변수 생성자   : 원하는 초기값을 받아 객체를 만드는 생성자
*/

class Player
{
private:
	std::string mName;
	int mHp;

public:
	// Player player;에서 자동 호출됩니다.
	Player()
		: mName("이름 없는 모험가"), mHp(100)
	{
		std::cout << "기본 생성자 호출\n";
	}

	// Player player("기사", 150);에서 자동 호출됩니다.
	Player(const std::string& name, int hp)
		: mName(name), mHp(hp)
	{
		std::cout << "매개변수 생성자 호출\n";
	}

	void PrintInfo() const
	{
		std::cout << mName << " / HP: " << mHp << '\n';
	}
};

int main()
{
	Player defaultPlayer;          // 기본 생성자 호출
	Player knight("기사", 150); // 매개변수 생성자 호출

	defaultPlayer.PrintInfo();
	knight.PrintInfo();

	return 0;
}
