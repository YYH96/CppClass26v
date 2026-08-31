#include <iostream>
#include <string>

/*
	상속(Inheritance)
	- 기반 클래스의 공통 데이터와 기능을 파생 클래스가 물려받는 기능입니다.
	- class Warrior : public Character처럼 작성합니다.

	기반 클래스의 멤버 접근
	- public    : 자식 클래스와 외부 코드 모두 접근할 수 있습니다.
	- protected : 자식 클래스에서는 접근할 수 있지만 외부 코드에서는 접근할 수 없습니다.
	- private   : 기반 클래스 내부에서만 접근할 수 있습니다.
*/

class Character
{
public:
	std::string mName; // 예시를 위한 public 멤버: 외부에서도 접근할 수 있습니다.

protected:
	int mLevel; // 자식 클래스가 사용할 공통 데이터

private:
	int mSecretCode; // 자식 클래스도 직접 접근할 수 없는 데이터

public:
	Character()
		: mName("이름 없음"), mLevel(1), mSecretCode(777)
	{
	}

	void PrintSecretCode() const
	{
		// private 데이터는 Character의 멤버 함수 안에서만 사용할 수 있습니다.
		std::cout << "비밀 코드: " << mSecretCode << '\n';
	}
};

class Warrior : public Character
{
public:
	void SetWarriorInfo(const std::string& name, int level)
	{
		mName = name;   // public 멤버이므로 접근 가능
		mLevel = level; // protected 멤버이므로 자식 클래스 안에서 접근 가능

		// mSecretCode = 100; // 오류: private 멤버는 자식 클래스에서 직접 접근할 수 없습니다.
	}

	void PrintInfo() const
	{
		std::cout << "직업: 전사\n";
		std::cout << "이름: " << mName << '\n';
		std::cout << "레벨: " << mLevel << '\n';
	}
};

int main()
{
	Warrior warrior;
	warrior.SetWarriorInfo("용감한 전사", 10);

	warrior.mName = "이름 변경 가능"; // public 멤버는 외부 코드에서도 접근 가능합니다.
	warrior.PrintInfo();
	warrior.PrintSecretCode(); // public 멤버 함수로 private 데이터를 안전하게 조회합니다.

	// warrior.mLevel = 20;      // 오류: protected 멤버는 외부에서 접근할 수 없습니다.
	// warrior.mSecretCode = 0;  // 오류: private 멤버는 외부에서 접근할 수 없습니다.

	return 0;
}
