#include <iostream>
#include <string>

/*
	복사 생성자(Copy Constructor)
	- 같은 클래스의 기존 객체를 바탕으로 새 객체를 만들 때 호출됩니다.
	- 형태: 클래스이름(const 클래스이름& other)
	- Player copy = original;과 Player copy(original);에서 호출됩니다.

	참조(&)를 쓰지 않으면 복사 생성자를 호출하려고 객체를 복사해야 하므로 문제가 생깁니다.
	const를 붙이면 원본을 바꾸지 않겠다는 뜻을 나타냅니다.
*/

class Player
{
private:
	std::string mName;
	int mHp;

public:
	Player(const std::string& name, int hp)
		: mName(name), mHp(hp)
	{
		std::cout << "매개변수 생성자: " << mName << '\n';
	}

	// original의 멤버 값을 이용해 새로운 Player 객체를 만듭니다.
	Player(const Player& original)
		: mName(original.mName), mHp(original.mHp)
	{
		std::cout << "복사 생성자: " << original.mName << "을(를) 복사했습니다.\n";
	}

	void SetName(const std::string& name)
	{
		mName = name;
	}

	void PrintInfo() const
	{
		std::cout << mName << " / HP: " << mHp << '\n';
	}
};

int main()
{
	Player original("원본 기사", 150);

	Player copied = original; // 복사 생성자 호출
	Player copiedAgain(original); // 복사 생성자 호출

	copied.SetName("복사된 기사");

	std::cout << "\n[원본]\n";
	original.PrintInfo();
	std::cout << "[복사본]\n";
	copied.PrintInfo();
	std::cout << "[두 번째 복사본]\n";
	copiedAgain.PrintInfo();

	return 0;
}
