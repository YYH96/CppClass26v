/*
    vector

    - vector는 크기를 실행 중에 늘리거나 줄일 수 있는 가변 배열입니다.
    - 같은 자료형의 값을 순서대로 저장합니다.
    - 사용하려면 #include <vector>가 필요합니다.
    - vector는 STL(Standard Template Library)의 컨테이너입니다.
*/

#include <iostream>
#include <vector>

int main()
{
    // 비어 있는 int 가변 배열을 만든다.
    std::vector<int> scores;

    // push_back: 맨 뒤에 원소를 추가한다.
    scores.push_back(80);
    scores.push_back(95);
    scores.push_back(70);

    // size: 현재 원소의 개수, empty: 비어 있는지 확인한다.
    std::cout << "점수 개수: " << scores.size() << '\n';
    std::cout << "비어 있는가: " << scores.empty() << "\n\n";

    // 배열처럼 []로 접근할 수 있다. 인덱스는 0부터 시작한다.
    scores[0] = 85;
    std::cout << "첫 번째 점수([]): " << scores[0] << '\n';

    // at도 인덱스로 접근한다.
    // []와 달리 범위를 벗어난 인덱스를 넣으면 오류를 알려준다.
    std::cout << "두 번째 점수(at): " << scores.at(1) << '\n';

    // front, back: 첫 번째와 마지막 원소를 가져온다.
    // 비어 있는 vector에서는 front/back을 호출하면 안 된다.
    std::cout << "첫 번째 점수: " << scores.front() << '\n';
    std::cout << "마지막 점수: " << scores.back() << "\n\n";

    // insert: begin() 위치 앞에 값을 삽입한다.
    // begin()은 첫 번째 원소의 위치를 뜻한다.
    scores.insert(scores.begin(), 100);

    // erase: 지정한 위치의 원소를 제거한다.
    // begin() + 1은 두 번째 원소의 위치다.
    scores.erase(scores.begin() + 1);

    std::cout << "insert와 erase 후: ";
    for (int score : scores)
    {
        std::cout << score << ' ';
    }
    std::cout << "\n\n";

    // pop_back: 맨 뒤 원소 하나를 제거한다.
    // 비어 있는 vector에는 pop_back을 호출하면 안 된다.
    scores.pop_back();

    std::cout << "pop_back 후 개수: " << scores.size() << '\n';

    // reserve: 앞으로 넣을 원소를 위해 메모리 공간을 미리 확보한다.
    // 원소 개수(size)는 바뀌지 않는다.
    scores.reserve(10);
    std::cout << "reserve 후 원소 개수: " << scores.size() << '\n';

    // clear: 모든 원소를 제거한다.
    scores.clear();
    std::cout << "clear 후 비어 있는가: " << scores.empty() << '\n';

    // 선언과 동시에 초기화할 수도 있다.
    std::vector<int> levels = { 1, 2, 3 };
    levels.emplace_back(4); // 맨 뒤에 원소를 생성하며 추가한다.

    std::cout << "레벨: ";
    for (int level : levels)
    {
        std::cout << level << ' ';
    }
    std::cout << '\n';

    return 0;
}
