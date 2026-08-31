#include <iostream>

/*
	포인터의 참조: Type*&
	- Type*는 Type 객체의 주소를 담는 포인터 변수입니다.
	- Type*&는 그 포인터 변수 자체의 참조입니다.
	- 함수 안에서 호출자 포인터에 새 주소를 대입하거나 nullptr을 대입할 수 있습니다.

	동적 할당한 객체를 함수에서 만들어 호출자에게 전달할 때 사용할 수 있습니다.
*/

class Potion
{
private:
	int mHealAmount;

public:
	Potion(int healAmount)
		: mHealAmount(healAmount)
	{
	}

	void PrintInfo() const
	{
		std::cout << "회복량: " << mHealAmount << '\n';
	}
};

void CreatePotion(Potion*& potion)
{
	potion = new Potion(50); // potion은 호출자 포인터의 별칭이므로 호출한 쪽에도 주소가 저장됩니다.
}

void DestroyPotion(Potion*& potion)
{
	delete potion;
	potion = nullptr; // 호출자 포인터도 nullptr로 바뀝니다.
}

int main()
{
	Potion* potion = nullptr;
	std::cout << "생성 전 주소: " << potion << '\n';

	CreatePotion(potion);
	std::cout << "생성 후 주소: " << potion << '\n';
	potion->PrintInfo();

	DestroyPotion(potion);
	std::cout << "해제 후 주소: " << potion << '\n';

	return 0;
}
