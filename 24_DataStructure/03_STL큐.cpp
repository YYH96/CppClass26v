/*
    STL 큐(Queue)

    선입선출 FIFO(First In, First Out)
    먼저 넣은 데이터가 가장 먼저 나온다.
*/

#include <iostream>
#include <queue>
#include <string>

int main()
{
    std::queue<std::string> waitingPlayers;

    // push: 큐의 뒤에 데이터를 넣는다.
    waitingPlayers.push("전사");
    waitingPlayers.push("마법사");
    waitingPlayers.push("궁수");

    std::cout << "현재 대기 인원: " << waitingPlayers.size() << '\n';
    std::cout << "다음 차례: " << waitingPlayers.front() << '\n';
    std::cout << "마지막 대기자: " << waitingPlayers.back() << '\n';

    // pop: 맨 앞 데이터를 제거한다. pop은 제거한 값을 반환하지 않는다.
    waitingPlayers.pop();
    std::cout << "처리 후 다음 차례: " << waitingPlayers.front() << '\n';

    std::cout << "\n대기열 처리 순서\n";

    // front, back, pop은 빈 큐에서 호출하면 안 된다.
    while (!waitingPlayers.empty())
    {
        std::cout << waitingPlayers.front() << "의 차례입니다.\n";
        waitingPlayers.pop();
    }

    std::cout << "비었는가? " << waitingPlayers.empty() << '\n';

    return 0;
}
