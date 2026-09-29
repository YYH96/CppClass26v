#include <iostream>

enum class Menu
{
    Exit = 0,
    Americano = 1,
    Latte = 2,
    Mocha = 3
};

class CoffeShop
{
private:
    int Money = 10000;

public:
    bool Run()
    {
        std::cout << "\n잔액: " << Money << "원\n";
        std::cout << "1. 아메리카노 2000원\n";
        std::cout << "2. 라떼 3000원\n";
        std::cout << "3. 모카 4000원\n";
        std::cout << "0. 종료\n";
        std::cout << "선택: ";

        int input = 0;
        if (!(std::cin >> input))
            return false;

        Menu menu = static_cast<Menu>(input);
        int price = 0;

        switch (menu)
        {
        case Menu::Exit:
            return false;

        case Menu::Americano:
            price = 2000;
            break;

        case Menu::Latte:
            price = 3000;
            break;

        case Menu::Mocha:
            price = 4000;
            break;

        default:
            std::cout << "잘못된 메뉴입니다.\n";
            return true;
        }

        if (Money < price)
        {
            std::cout << "잔액이 부족합니다.\n";
            return true;
        }

        Money -= price;
        std::cout << "커피가 나왔습니다!\n";

        return true;
    }
};

int main()
{
    CoffeShop Cafe;

    while (true)
    {
        if (!Cafe.Run())
        {
            break;
        }
    }

    return 0;
}