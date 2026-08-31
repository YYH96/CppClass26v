#include <iostream>

/*
    사용자 정의 자료형: 프로그래머가 기본 자료형을 조합해 의미와 구조를 정의한다.
    대표적으로 struct, class, enum, using이 있다.
*/

struct Player
{
    int id;
    int health;
    float speed;
};

enum class Team { Red, Blue };
using PlayerId = unsigned int;

int main()
{
    Player player{ 1, 100, 5.5F };
    PlayerId playerId = static_cast<PlayerId>(player.id);
    Team team = Team::Red;

    std::cout << "player id: " << playerId
              << ", health: " << player.health
              << ", speed: " << player.speed << "\n";
    std::cout << "Player size: " << sizeof(Player) << " byte\n";
    std::cout << "team: " << (team == Team::Red ? "Red" : "Blue") << "\n";

    return 0;
}
