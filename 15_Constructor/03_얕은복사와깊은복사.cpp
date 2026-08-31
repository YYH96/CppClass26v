#include <iostream>

/*
	얕은 복사(Shallow Copy)
	- 포인터가 가리키는 실제 데이터가 아니라 포인터 주소만 복사합니다.
	- 두 포인터가 같은 힙 메모리를 가리키므로, 하나를 수정하면 다른 쪽에서도 값이 바뀝니다.
	- 두 객체가 같은 주소를 delete하면 이중 해제가 발생할 수 있습니다.

	깊은 복사(Deep Copy)
	- 새 메모리를 확보하고 실제 값까지 복사합니다.
	- 원본과 복사본이 각각 독립적인 메모리를 소유합니다.
*/

class SkillDamage
{
private:
	int* mDamage;

public:
	SkillDamage(int damage)
		: mDamage(new int(damage))
	{
		std::cout << "생성: " << mDamage << "에 " << *mDamage << " 저장\n";
	}

	// 깊은 복사: 포인터 주소를 그대로 복사하지 않고, 새로운 int를 만들어 값을 복사합니다.
	SkillDamage(const SkillDamage& other)
		: mDamage(new int(*other.mDamage))
	{
		std::cout << "깊은 복사: " << other.mDamage << "의 값을 " << mDamage << "에 새로 복사\n";
	}

	~SkillDamage()
	{
		delete mDamage;
		mDamage = nullptr;
	}

	void SetDamage(int damage)
	{
		*mDamage = damage;
	}

	void PrintInfo(const char* label) const
	{
		std::cout << label << " / 주소: " << mDamage << ", 피해량: " << *mDamage << '\n';
	}
};

int main()
{
	std::cout << "[얕은 복사: 포인터 주소만 복사]\n";
	int* originalAddress = new int(10);
	int* shallowCopyAddress = originalAddress; // 두 포인터가 같은 주소를 가리킵니다.

	*shallowCopyAddress = 20;
	std::cout << "원본 포인터 주소: " << originalAddress << ", 값: " << *originalAddress << '\n';
	std::cout << "복사 포인터 주소: " << shallowCopyAddress << ", 값: " << *shallowCopyAddress << '\n';

	delete originalAddress; // 실제 힙 메모리는 한 번만 해제합니다.
	originalAddress = nullptr;
	shallowCopyAddress = nullptr; // 이 포인터는 소유자가 아니므로 delete하지 않습니다.

	std::cout << "\n[깊은 복사: 클래스의 복사 생성자]\n";
	SkillDamage originalSkill(50);
	SkillDamage copiedSkill = originalSkill; // 깊은 복사 생성자 호출

	copiedSkill.SetDamage(90);
	originalSkill.PrintInfo("원본 스킬");
	copiedSkill.PrintInfo("복사 스킬");

	/*
		만약 아래처럼 포인터 주소만 복사했다면 얕은 복사가 됩니다.

		SkillDamage(const SkillDamage& other)
			: mDamage(other.mDamage) // 잘못된 복사 생성자
		{
		}

		originalSkill과 copiedSkill의 소멸자가 같은 주소를 delete하여 이중 해제가 발생합니다.
	*/

	return 0; // originalSkill과 copiedSkill은 서로 다른 주소를 각각 한 번씩 해제합니다.
}
