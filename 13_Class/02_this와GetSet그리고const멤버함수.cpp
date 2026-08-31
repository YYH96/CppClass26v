#include <iostream>
#include <string>

/*
	Get/Set 함수
	- private 멤버 변수에 값을 넣거나 가져가는 public 함수입니다.
	- 값이 바뀌는 통로를 함수로 제한하면 유효성 검사를 한 장소에서 할 수 있습니다.

	this 포인터
	- 멤버 함수 안에서 현재 객체 자신을 가리키는 숨겨진 포인터입니다.
	- 매개변수 name과 멤버 변수 mName처럼 이름이 다르면 this는 생략해도 됩니다.

	const 멤버 함수
	- 함수 선언의 끝에 const를 붙이면 객체의 멤버 값을 바꾸지 않겠다는 약속입니다.
	- 정보를 출력하거나 값을 조회하는 함수에 사용합니다.
*/

class Item
{
private:
	std::string mName;
	int mPrice;

public:
	void SetName(const std::string& name)
	{
		this->mName = name; // this는 현재 Item 객체를 가리킵니다.
	}

	void SetPrice(int price)
	{
		if (price < 0)
		{
			std::cout << "가격은 0 이상이어야 합니다.\n";
			return;
		}

		mPrice = price;
	}

	const std::string& GetName() const
	{
		return mName;
	}

	int GetPrice() const
	{
		return mPrice;
	}

	void PrintInfo() const
	{
		std::cout << "아이템: " << mName << ", 가격: " << mPrice << "G";
		std::cout << " / 이 객체의 주소(this): " << this << '\n';
		// mPrice = 0; // 오류: const 멤버 함수에서는 일반 멤버 값을 변경할 수 없습니다.
	}
};

int main()
{
	// Item이라는 같은 설계도로 만들었지만, 아래 두 객체는 서로 다른 객체입니다.
	// 따라서 각 객체는 자기만의 mName, mPrice 값을 따로 가집니다.
	Item healthPotion;
	Item manaPotion;

	healthPotion.SetName("회복 물약");
	healthPotion.SetPrice(300);

	manaPotion.SetName("마나 물약");
	manaPotion.SetPrice(500);

	std::cout << "[두 Item 객체의 정보]\n";
	healthPotion.PrintInfo();
	manaPotion.PrintInfo();

	std::cout << healthPotion.GetName() << "의 가격은 " << healthPotion.GetPrice() << "G입니다.\n";
	std::cout << manaPotion.GetName() << "의 가격은 " << manaPotion.GetPrice() << "G입니다.\n";

	healthPotion.SetPrice(-50); // setter 안의 검증으로 잘못된 값의 저장을 막습니다.
	healthPotion.PrintInfo(); // 회복 물약 가격은 기존 300G가 유지됩니다.
	manaPotion.PrintInfo();   // 마나 물약 객체에는 영향을 주지 않습니다.

	return 0;
}
