#include <iostream>

/*
	순수 가상 함수와 추상 클래스
	- virtual 반환형 함수이름(...) = 0; 처럼 선언합니다.
	- 순수 가상 함수가 하나라도 있으면 추상 클래스가 됩니다.
	- 추상 클래스는 직접 객체를 만들 수 없습니다.
	- 자식 클래스에게 "반드시 이 기능을 구현하라"는 공통 규칙을 제공합니다.
*/

class Skill
{
public:
	virtual ~Skill() = default;

	// Skill 자체에는 구체적인 사용 방법이 없습니다.
	virtual void Use() const = 0;
};

class HealSkill : public Skill
{
public:
	void Use() const override
	{
		std::cout << "회복 스킬을 사용합니다. HP가 회복됩니다.\n";
	}
};

class FireballSkill : public Skill
{
public:
	void Use() const override
	{
		std::cout << "화염구 스킬을 사용합니다. 적에게 피해를 줍니다.\n";
	}
};

int main()
{
	// Skill skill; // 오류: Skill은 추상 클래스이므로 직접 객체를 만들 수 없습니다.

	HealSkill heal;
	FireballSkill fireball;
	Skill* skills[2] = { &heal, &fireball };

	for (Skill* skill : skills)
	{
		skill->Use();
	}

	return 0;
}
