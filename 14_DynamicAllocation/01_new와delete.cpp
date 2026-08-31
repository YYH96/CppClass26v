#include <iostream>

/*
	new / delete
	- new는 힙에 메모리를 확보하고 값을 만들거나 객체의 생성자를 호출합니다.
	- delete는 객체의 소멸자를 호출하고 힙 메모리를 반환합니다.
	- new로 만든 값 하나는 delete 하나로 해제합니다.

	힙 메모리는 함수가 끝나도 자동으로 사라지지 않습니다.
	따라서 new를 사용한 코드에는 delete가 반드시 있어야 합니다.
*/

int main()
{
	int* number = new int(100); // 힙에 int 하나를 만들고 100으로 초기화

	std::cout << "값: " << *number << '\n';
	std::cout << "주소: " << number << '\n';

	*number = 250;
	std::cout << "변경한 값: " << *number << '\n';

	delete number; // new int와 짝이 되는 해제
	number = nullptr; // 해제된 주소를 남기지 않아 댕글링 포인터 실수를 줄입니다.

	// std::cout << *number; // 오류 위험: nullptr 또는 해제된 메모리를 역참조하면 안 됩니다.
	delete number; // delete nullptr은 아무 작업도 하지 않으므로 안전합니다.

	return 0;
}
