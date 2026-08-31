#include <iostream>

/*
    while과 do-while 문

    while: 반복 전에 조건을 검사하므로 처음부터 false면 한 번도 실행하지 않는다.
    do-while: 본문을 먼저 실행하고 조건을 검사하므로 최소 한 번 실행한다.
*/
int main()
{
#pragma region while_문
    int count = 1;
    std::cout << "while: ";

    while (count <= 3)
    {
        std::cout << count << " ";
        ++count; // while문에서는 본문 안에서 다음 반복을 위한 값 변경이 필요하다.
    }
    std::cout << "\n\n";
#pragma endregion

#pragma region do_while_문
    int menu = 0;
    std::cout << "do-while: ";

    do
    {
        std::cout << "본문을 한 번 실행합니다.\n";
    } while (menu != 0); // menu가 0이므로 본문 실행 후 반복을 끝낸다.
#pragma endregion

    /*
        !기억
        - while의 조건을 처음부터 false로 만들면 본문은 실행되지 않는다.
        - do-while 끝에는 세미콜론(;)을 반드시 작성한다.
        - 입력을 최소 한 번 받아야 하는 메뉴나 재시도 기능에 do-while을 사용할 수 있다.
    */
    return 0;
}
