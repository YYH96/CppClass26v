#include <iostream>

/*
	가상 함수(virtual function), 오버라이딩(overriding), 다형성(polymorphism)
	- 자식 클래스가 부모의 virtual 함수를 같은 형태로 다시 구현하는 것을 오버라이딩(재정의)이라고 합니다.
	- virtual 함수가 오버라이딩되어 있으면, 부모 포인터로 호출해도 실제 객체의 함수가 호출됩니다.
	- 자식 클래스에서는 override를 붙여 오버라이딩 실수를 컴파일러가 찾아내게 합니다.

	vtable / vfptr
	- MSVC를 포함한 많은 컴파일러는 virtual 함수 호출을 위해 vtable과 vfptr을 사용합니다.
	- virtual 함수가 하나라도 있으면 일반적으로 객체 안에 vfptr이 생깁니다.
	- 단, vtable/vfptr은 C++ 표준이 강제하는 구현이 아닙니다.

	가상 소멸자
	- 기반 클래스 포인터로 파생 객체를 delete할 수 있다면 기반 클래스 소멸자는 virtual이어야 합니다.
	- 그러면 실제 객체의 자식 소멸자부터 부모 소멸자까지 정상 순서로 호출됩니다.

	생성자와 가상 함수
	- 부모 생성자 실행 중에는 자식 부분이 아직 준비되지 않았습니다.
	- 생성자 또는 소멸자 안에서 가상 함수를 호출하면, 더 파생된 함수가 아닌 현재 클래스의 함수가 호출됩니다.
*/

class NoVirtualFunction
{
};

class Character
{
public:
	Character()
	{
		std::cout << "Character 생성자\n";
		PrintType(); // Warrior 부분은 아직 생성 전이므로 Character::PrintType()이 호출됩니다.
	}

	virtual ~Character()
	{
		std::cout << "Character 소멸자\n";
		PrintType(); // Warrior 부분은 이미 소멸했으므로 Character::PrintType()이 호출됩니다.
	}

	virtual void Attack() const
	{
		std::cout << "캐릭터의 기본 공격\n";
	}

	virtual void PrintType() const
	{
		std::cout << "Character 타입\n";
	}
};

class Warrior : public Character
{
private:
	int mSwordDamage;

public:
	Warrior()
		: mSwordDamage(50)
	{
		std::cout << "Warrior 생성자\n";
		PrintType(); // 이제 Warrior 부분까지 생성되었으므로 Warrior::PrintType()이 호출됩니다.
	}

	~Warrior() override
	{
		std::cout << "Warrior 소멸자\n";
	}

	// Character::Attack()을 Warrior만의 공격 방식으로 오버라이딩합니다.
	void Attack() const override
	{
		std::cout << "전사가 검으로 공격합니다. 공격력: " << mSwordDamage << '\n';
	}

	void PrintType() const override
	{
		std::cout << "Warrior 타입\n";
	}
};

class Wizard : public Character
{
public:
	// Character::Attack()을 Wizard만의 공격 방식으로 오버라이딩합니다.
	void Attack() const override
	{
		std::cout << "마법사가 화염구를 발사합니다.\n";
	}

	void PrintType() const override
	{
		std::cout << "Wizard 타입\n";
	}
};

int main()
{
	std::cout << "가상 함수가 없는 빈 클래스 크기: " << sizeof(NoVirtualFunction) << " byte\n";
	std::cout << "가상 함수가 있는 Character 크기: " << sizeof(Character) << " byte\n";
	// 크기는 컴파일러와 플랫폼에 따라 다릅니다.
	// MSVC x64에서는 Character에 vfptr이 있어 보통 8 byte가 관찰됩니다.

	std::cout << "\n[지역 객체 생성]\n";
	Warrior warrior;
	Wizard wizard;

	// 배열의 원소 타입은 Character*지만, 각 원소가 가리키는 실제 객체는 서로 다릅니다.
	Character* party[2] = { &warrior, &wizard };

	for (Character* character : party)
	{
		// 실제 객체에 맞춰 오버라이딩된 Warrior/Wizard의 Attack이 호출됩니다.
		character->Attack();
	}

	std::cout << "\n[부모 포인터로 자식 객체 삭제]\n";
	Character* dynamicWarrior = new Warrior();
	delete dynamicWarrior; // virtual 소멸자: Warrior -> Character 순서로 호출됩니다.

	return 0;
}
