/*
    STL map과 unordered_map

    둘 다 key와 value를 한 쌍으로 저장하며 key는 중복될 수 없다.

    std::map           : key를 정렬된 순서로 관리한다. 삽입·탐색·삭제는 O(log N)이다.
    std::unordered_map : 해시(Hash)로 저장한다. 순서를 보장하지 않으며 평균 O(1)에 찾는다.

    정렬 순서가 필요하면 map, 빠른 이름·ID 조회가 주목적이면 unordered_map을 고려한다.
*/

#include <iostream>
#include <map>
#include <string>
#include <unordered_map>

#pragma region 출력 함수

void PrintMap(const std::map<std::string, int>& inventory)
{
    // map은 key 순서대로 순회한다.
    for (std::map<std::string, int>::const_iterator iterator = inventory.begin(); iterator != inventory.end(); ++iterator)
    {
        // iterator->first는 key, iterator->second는 value다.
        std::cout << iterator->first << ": " << iterator->second << "개\n";
    }
}

void PrintUnorderedMap(const std::unordered_map<std::string, int>& inventory)
{
    // unordered_map의 출력 순서는 해시 상태에 따라 달라진다. key 순서가 아니다.
    for (std::unordered_map<std::string, int>::const_iterator iterator = inventory.begin(); iterator != inventory.end(); ++iterator)
    {
        std::cout << iterator->first << ": " << iterator->second << "개\n";
    }
}

#pragma endregion

int main()
{
#pragma region std_map_정렬된_key

    std::map<std::string, int> sortedInventory;

    // operator[]로 key에 대응하는 value를 저장하거나 바꾼다.
    sortedInventory["검"] = 1;
    sortedInventory["회복 물약"] = 3;
    sortedInventory["열쇠"] = 2;
    sortedInventory["회복 물약"] += 2;

    std::cout << "[std::map - key 오름차순 출력]\n";
    PrintMap(sortedInventory);

    // find는 key를 찾는다. 찾지 못하면 end를 반환한다.
    std::map<std::string, int>::iterator key = sortedInventory.find("열쇠");

    if (key != sortedInventory.end())
    {
        std::cout << "열쇠 개수: " << key->second << "\n\n";
    }

    sortedInventory.erase("검");

#pragma endregion

#pragma region std_unordered_map_해시

    std::unordered_map<std::string, int> fastInventory;

    // 사용 방법은 map과 거의 같지만, 저장·순회 순서가 key 순서가 아니다.
    fastInventory["검"] = 1;
    fastInventory["회복 물약"] = 3;
    fastInventory["열쇠"] = 2;
    fastInventory["회복 물약"] += 2;

    std::cout << "[std::unordered_map - 출력 순서는 보장되지 않음]\n";
    PrintUnorderedMap(fastInventory);

    std::unordered_map<std::string, int>::iterator fastKey = fastInventory.find("열쇠");

    if (fastKey != fastInventory.end())
    {
        std::cout << "열쇠 개수: " << fastKey->second << '\n';
    }

    fastInventory.erase("검");

#pragma endregion

    // 없는 key에 operator[]를 사용하면 value가 기본값으로 새로 만들어진다.
    // 읽기만 할 때는 map과 unordered_map 모두 find를 먼저 사용하는 편이 안전하다.

    return 0;
}
