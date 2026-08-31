#include <iostream>

/*
    조건문 실습 2 - switch로 커피 주문하기

    04_CoffeeOrderPractice.cpp의 if-else 분기를 switch 문으로 바꾼 예제다.
    반복문을 아직 배우지 않았으므로 주문은 한 번만 받는다.
*/
int main()
{
    int menuNumber = 0;

    std::cout << "===== 카페 메뉴 =====\n";
    std::cout << "1. 아메리카노 - 2,500원\n";
    std::cout << "2. 카페라떼   - 3,500원\n";
    std::cout << "3. 레몬에이드 - 4,000원\n";
    std::cout << "메뉴 번호를 입력하세요: ";

    if (!(std::cin >> menuNumber))
    {
        std::cout << "잘못된 주문입니다.\n";
        return 0;
    }

    switch (menuNumber)
    {
    case 1:
        std::cout << "아메리카노를 주문했습니다. 결제 금액은 2,500원입니다.\n";
        break; // break가 없으면 다음 case도 계속 실행된다.

    case 2:
        std::cout << "카페라떼를 주문했습니다. 결제 금액은 3,500원입니다.\n";
        break;

    case 3:
        std::cout << "레몬에이드를 주문했습니다. 결제 금액은 4,000원입니다.\n";
        break;

    default: // 1, 2, 3 어느 case와도 일치하지 않을 때 실행한다.
        std::cout << "잘못된 주문입니다.\n";
        break;
    }

    return 0;
}
