/*
    STL 스택(Stack)

    후입선출 LIFO(Last In, First Out)
    마지막에 넣은 데이터가 가장 먼저 나온다.
*/

#include <iostream>
#include <stack>

int main()
{
    std::stack<int> numbers;

    // push: 스택의 맨 위에 데이터를 넣는다.
    numbers.push(10);
    numbers.push(20);
    numbers.push(30);

    std::cout << "현재 크기: " << numbers.size() << '\n';
    std::cout << "맨 위 데이터: " << numbers.top() << '\n';

    // top은 값을 확인만 한다. 데이터를 제거하지 않는다.
    std::cout << "top을 다시 호출해도: " << numbers.top() << '\n';

    // pop: 맨 위 데이터를 제거한다. pop은 제거한 값을 반환하지 않는다.
    numbers.pop();
    std::cout << "pop 후 맨 위 데이터: " << numbers.top() << '\n';

    std::cout << "\n스택에서 꺼내는 순서\n";

    // top과 pop은 빈 스택에서 호출하면 안 된다.
    while (!numbers.empty())
    {
        std::cout << numbers.top() << '\n';
        numbers.pop();
    }

    std::cout << "비었는가? " << numbers.empty() << '\n';

    // std::stack에는 clear 함수가 없다.
    // 모두 비울 때는 empty가 될 때까지 pop을 반복한다.

    return 0;
}
