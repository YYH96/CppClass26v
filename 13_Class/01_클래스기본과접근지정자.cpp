#include <iostream>
#include <string>

/*
	클래스(class)
	- 멤버 변수(데이터)와 멤버 함수(기능)를 함께 정의하는 사용자 정의 자료형입니다.
	- class로 실제 값을 만들면 객체(object)라고 합니다.

	접근 지정자
	- public : 외부 코드에서도 접근할 수 있습니다.
	- private : 클래스 내부에서만 접근할 수 있습니다.
	- class는 아무 접근 지정자도 적지 않으면 private가 기본입니다.
	- struct는 public이 기본이라는 차이가 있습니다.
*/

class Player
{
private:
	// 외부에서 player.mHp = -100;처럼 직접 바꾸지 못하게 보호합니다.
	std::string mName;
	int mHp;
	int mLevel;

public:
	// public 멤버 함수는 Player 객체를 사용하는 쪽에 제공하는 기능입니다.
	void Initialize(const std::string& name, int hp, int level)
	{
		mName = name;
		mHp = hp;
		mLevel = level;
	}

	void TakeDamage(int damage)
	{
		if (damage < 0)
		{
			std::cout << "음수 피해는 받을 수 없습니다.\n";
			return;
		}

		mHp -= damage;

		// private 데이터는 멤버 함수 안에서 규칙을 지키며 변경합니다.
		if (mHp < 0)
		{
			mHp = 0;
		}
	}

	void PrintInfo()
	{
		std::cout << "이름: " << mName << '\n';
		std::cout << "체력: " << mHp << '\n';
		std::cout << "레벨: " << mLevel << '\n';
	}
};

int main()
{
	Player player; // Player 클래스로 만든 객체
	player.Initialize("초보 용사", 100, 1);

	player.TakeDamage(35);
	player.PrintInfo();

	// player.mHp = 9999; // 오류: mHp는 private 멤버이므로 외부에서 접근할 수 없습니다.

	return 0;
}
