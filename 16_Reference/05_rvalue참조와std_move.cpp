#include <iostream>
#include <utility> // std::move

/*
	rvalue 참조(Type&&)
	- 임시 값(rvalue)에 연결할 수 있는 참조입니다.
	- 이동 생성자·이동 대입 연산자가 자원을 넘겨받을 때 주로 사용합니다.

	std::move(value)는 값을 실제로 옮기지 않습니다.
	이동 가능한 형태로 바꾸어 rvalue 참조 또는 이동 생성자가 선택될 수 있게 합니다.
*/

void IdentifyValue(int& value)
{
	std::cout << value << "은(는) lvalue로 전달되었습니다.\n";
}

void IdentifyValue(int&& value)
{
	std::cout << value << "은(는) rvalue로 전달되었습니다.\n";
}

int main()
{
	int score = 100;

	IdentifyValue(score);            // 이름이 있는 변수: lvalue
	IdentifyValue(200);              // 리터럴: rvalue
	IdentifyValue(score + 50);       // 계산 결과: rvalue
	IdentifyValue(std::move(score)); // std::move로 rvalue 형태로 전달

	int&& temporaryReference = 300;
	// temporaryReference는 이름이 있으므로, 이 표현식 자체는 lvalue입니다.
	IdentifyValue(temporaryReference);

	return 0;
}
