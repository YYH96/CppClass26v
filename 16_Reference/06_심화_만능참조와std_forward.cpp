#include <iostream>
#include <type_traits> // std::is_lvalue_reference_v
#include <utility>     // std::forward

/*
	[심화] 만능 참조(전달 참조, Forwarding Reference)
	- 함수 템플릿에서 타입 추론을 받는 T&&는 lvalue와 rvalue를 모두 받을 수 있습니다.
	- 함수 안에서 이름이 있는 value는 lvalue가 됩니다.
	- std::forward<T>(value)는 받은 값의 원래 lvalue/rvalue 성질을 유지해 다음 함수로 전달합니다.

	템플릿 단원에서 다시 자세히 다룹니다.
*/

void PrintCategory(int& value)
{
	std::cout << value << " : lvalue\n";
}

void PrintCategory(int&& value)
{
	std::cout << value << " : rvalue\n";
}

template <typename T>
void ForwardAndPrint(T&& value)
{
	if constexpr (std::is_lvalue_reference_v<T>)
	{
		std::cout << "함수 템플릿이 lvalue를 받았습니다. ";
	}
	else
	{
		std::cout << "함수 템플릿이 rvalue를 받았습니다. ";
	}

	PrintCategory(std::forward<T>(value));
}

int main()
{
	int score = 100;

	ForwardAndPrint(score); // T는 int&로 추론됩니다.
	ForwardAndPrint(200);   // T는 int로 추론되고, 매개변수는 int&&가 됩니다.

	return 0;
}
