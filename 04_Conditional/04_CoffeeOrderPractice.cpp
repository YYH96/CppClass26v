#include <iostream>

/*
    조건문 실습 1 - 간단한 커피 주문하기

    반복문을 아직 배우지 않았으므로 주문은 한 번만 받는다.
    1~3 이외의 번호 또는 숫자가 아닌 값을 입력하면 잘못된 주문으로 종료한다.
*/
int main()
{
    int menuNumber = 0;

    std::cout << "===== 카페 메뉴 =====\n";
    std::cout << "1. 아메리카노 - 2,500원\n";
    std::cout << "2. 카페라떼   - 3,500원\n";
    std::cout << "3. 레몬에이드 - 4,000원\n";
    std::cout << "메뉴 번호를 입력하세요: ";

    // 숫자가 아닌 값을 입력하면 cin이 실패한다.
    if (!(std::cin >> menuNumber))
    {
        std::cout << "잘못된 주문입니다.\n";
        return 0;
    }

    if (menuNumber == 1)
    {
        std::cout << "아메리카노를 주문했습니다. 결제 금액은 2,500원입니다.\n";
    }
    else if (menuNumber == 2)
    {
        std::cout << "카페라떼를 주문했습니다. 결제 금액은 3,500원입니다.\n";
    }
    else if (menuNumber == 3)
    {
        std::cout << "레몬에이드를 주문했습니다. 결제 금액은 4,000원입니다.\n";
    }
    else
    {
        std::cout << "잘못된 주문입니다.\n";
    }

    return 0;
}
