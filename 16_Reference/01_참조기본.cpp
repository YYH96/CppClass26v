#include <iostream>

/*
	참조(Reference)
	- 기존 변수의 또 다른 이름(별칭)입니다.
	- int& reference = value;처럼 선언과 동시에 연결해야 합니다.
	- 참조를 바꾸면 원본 변수도 바뀝니다.
	- 한 번 연결한 뒤 다른 변수를 참조하도록 바꿀 수는 없습니다.
	- 참조는 독립된 변수처럼 별도 메모리를 할당받는 개념이 아니라 원본의 별칭입니다.
	  sizeof(참조)는 원본 자료형의 크기로 보입니다.
	  단, 컴파일러가 내부적으로 주소를 이용해 구현할 수 있는지는 C++ 문법 밖의 구현 영역입니다.
*/

int main()
{
	int hp = 100;
	int& hpReference = hp; // hp 변수의 별칭

	std::cout << "초기 hp: " << hp << '\n';
	std::cout << "초기 hpReference: " << hpReference << '\n';
	std::cout << "&hp: " << &hp << '\n';
	std::cout << "&hpReference: " << &hpReference << "  // 원본과 같은 주소\n";
	std::cout << "sizeof(hp): " << sizeof(hp) << " byte\n";
	std::cout << "sizeof(hpReference): " << sizeof(hpReference)
		<< " byte  // 참조 자체의 크기가 아니라 원본 int 크기로 계산\n";

	hpReference -= 30;
	std::cout << "참조로 변경한 뒤 hp: " << hp << '\n';

	int mana = 50;
	hpReference = mana;
	// 위는 참조 대상을 mana로 바꾸는 코드가 아닙니다.
	// hpReference(= hp)에 mana의 값 50을 대입하는 코드입니다.
	std::cout << "대입 뒤 hp: " << hp << ", mana: " << mana << '\n';

	// int& emptyReference;       // 오류: 참조는 선언과 동시에 초기화해야 합니다.
	// int& temporaryReference = 10; // 오류: 일반 참조는 임시 rvalue에 연결할 수 없습니다.

	return 0;
}
