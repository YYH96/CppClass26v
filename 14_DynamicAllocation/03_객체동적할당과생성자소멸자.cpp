#include <iostream>
#include <string>

/*
	클래스 객체를 new로 만들면 생성자가 호출되고,
	delete로 해제하면 소멸자가 호출됩니다.

	화살표 연산자(->)
	- 객체 포인터로 멤버 변수나 멤버 함수에 접근할 때 사용합니다.
	- pointer->member는 (*pointer).member와 같은 뜻입니다.
	- . 연산자는 실제 객체에, -> 연산자는 객체를 가리키는 포인터에 사용합니다.
*/

class Monster
{
private:
	std::string mName;
	int mHp;

public:
	Monster(const std::string& name, int hp)
		: mName(name), mHp(hp)
	{
		std::cout << mName << " 생성 / HP: " << mHp << '\n';
	}

	~Monster()
	{
		std::cout << mName << " 소멸\n";
	}

	void TakeDamage(int damage)
	{
		mHp -= damage;
		if (mHp < 0)
		{
			mHp = 0;
		}
	}

	void PrintInfo() const
	{
		std::cout << mName << " / HP: " << mHp << '\n';
	}
};

int main()
{
	Monster* monster = new Monster("동적 슬라임", 50);

	// monster는 Monster 객체 자체가 아니라 Monster 객체의 주소를 담는 포인터입니다.
	// 따라서 . 대신 -> 연산자로 멤버 함수에 접근합니다.
	monster->TakeDamage(20);
	monster->PrintInfo();

	// 위의 두 줄은 아래처럼 작성한 것과 같은 뜻입니다.
	(*monster).TakeDamage(10);
	(*monster).PrintInfo();
	// *monster.PrintInfo(); // 오류: . 연산자가 *보다 먼저 해석되므로 반드시 괄호가 필요합니다.

	delete monster; // Monster 소멸자가 호출된 뒤 메모리가 해제됩니다.
	monster = nullptr;

	return 0;
}
