#include <iostream>
#include <string>

/*
	const 참조 매개변수
	- 객체 전체를 복사하지 않고 원본을 읽기 전용으로 전달합니다.
	- 큰 클래스 객체, std::string, 배열 등을 출력·조회할 때 자주 사용합니다.
	- 함수 안에서 const 참조의 멤버 값을 바꾸면 컴파일 오류가 납니다.
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
	}

	Player(const Player& other)
		: mName(other.mName), mHp(other.mHp)
	{
		std::cout << "Player 복사 생성자 호출\n";
	}

	const std::string& GetName() const
	{
		return mName;
	}

	int GetHp() const
	{
		return mHp;
	}
};

void PrintByValue(Player player)
{
	std::cout << "값 전달: " << player.GetName() << " / HP: " << player.GetHp() << '\n';
}

void PrintByConstReference(const Player& player)
{
	std::cout << "const 참조: " << player.GetName() << " / HP: " << player.GetHp() << '\n';
	// player.mHp = 0; // 오류: const 참조로 받은 객체는 함수 안에서 변경할 수 없습니다.
}

int main()
{
	Player knight("기사", 150);

	std::cout << "[값 전달]\n";
	PrintByValue(knight); // 매개변수 player를 만들기 위해 복사 생성자가 호출됩니다.

	std::cout << "\n[const 참조 전달]\n";
	PrintByConstReference(knight); // 복사 생성자가 호출되지 않습니다.

	return 0;
}
