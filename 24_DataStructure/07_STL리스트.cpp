/*
    STL 리스트(List)

    std::list는 노드가 앞뒤로 연결된 이중 연결 리스트다.
    인덱스 접근 대신 반복자를 사용한다.
*/

#include <algorithm>
#include <iostream>
#include <list>
#include <string>

void PrintList(const std::list<std::string>& quests)
{
    // 반복자(iterator)는 컨테이너 안의 원소 위치를 가리키는 도구다.
    // begin은 첫 원소 위치, end는 마지막 원소의 다음 위치를 뜻한다.
    // const_iterator는 원소를 읽을 수 있지만 수정할 수 없다.
    for (std::list<std::string>::const_iterator iterator = quests.begin(); iterator != quests.end(); ++iterator)
    {
        // *iterator는 반복자가 가리키는 실제 원소를 뜻한다.
        // ++iterator는 다음 원소 위치로 이동한다.
        std::cout << *iterator << ' ';
    }

    std::cout << '\n';
}

int main()
{
    std::list<std::string> quests;

    quests.push_back("슬라임 처치");
    quests.push_back("고블린 처치");
    quests.push_front("마을장에게 대화");
    PrintList(quests);

    // list는 quests[1]처럼 인덱스로 접근할 수 없다.
    // 찾거나 삽입할 위치는 반복자로 표현한다.
    // list의 반복자는 양방향 반복자이므로 iterator + 1 같은 임의 접근은 할 수 없다.
    std::list<std::string>::iterator goblin = std::find(quests.begin(), quests.end(), "고블린 처치");

    if (goblin != quests.end())
    {
        quests.insert(goblin, "회복 물약 구매");
    }

    PrintList(quests);

    std::list<std::string>::iterator slime = std::find(quests.begin(), quests.end(), "슬라임 처치");

    if (slime != quests.end())
    {
        quests.erase(slime);
    }

    PrintList(quests);

    return 0;
}
