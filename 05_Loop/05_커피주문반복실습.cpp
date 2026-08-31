#include <iostream>
#include <limits>

/*
    반복문 실습 2 - 커피 주문하기

    메뉴를 한 번 고른 뒤 프로그램이 끝나는 것이 아니라,
    종료 메뉴를 선택할 때까지 주문을 계속 받을 수 있도록 while 반복문을 사용한다.
*/
int main()
{
    while (true)
    {
        std::cout << "\n===== 카페 메뉴 =====\n";
        std::cout << "1. 아메리카노 (3,000원)\n";
        std::cout << "2. 카페라테   (3,500원)\n";
        std::cout << "3. 카푸치노   (4,000원)\n";
        std::cout << "4. 에스프레소 (2,500원)\n";
        std::cout << "5. 주문 종료\n";
        std::cout << "메뉴 번호를 입력하세요: ";

        int menu = 0;
        if (!(std::cin >> menu))
        {
            // 숫자가 아닌 값을 입력하면 cin이 실패 상태가 된다.
            // 상태와 입력 버퍼를 비운 뒤, 다음 주문을 받는다.
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "숫자로 메뉴를 입력해주세요.\n";
            continue;
        }

        switch (menu)
        {
        case 1:
            std::cout << "아메리카노를 주문했습니다. (3,000원)\n";
            break;
        case 2:
            std::cout << "카페라테를 주문했습니다. (3,500원)\n";
            break;
        case 3:
            std::cout << "카푸치노를 주문했습니다. (4,000원)\n";
            break;
        case 4:
            std::cout << "에스프레소를 주문했습니다. (2,500원)\n";
            break;
        case 5:
            std::cout << "주문을 종료합니다. 이용해 주셔서 감사합니다.\n";
            return 0; // while 반복문까지 즉시 끝낸다.
        default:
            std::cout << "잘못된 메뉴 번호입니다. 다시 선택해주세요.\n";
            break;
        }
    }
}
