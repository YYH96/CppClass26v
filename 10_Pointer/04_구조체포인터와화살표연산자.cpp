#include <iostream>

/*
    구조체 포인터와 -> 연산자

    객체(변수) 자체의 멤버에는 . 연산자를 사용한다.
    객체를 가리키는 포인터의 멤버에는 -> 연산자를 사용한다.

    pPlayer->level은 (*pPlayer).level을 보기 좋게 줄여 쓴 표현이다.

    typedef와 using은 기존 자료형에 별칭(다른 이름)을 붙이는 문법이다.
    새로운 자료형을 만드는 것이 아니라, 같은 자료형을 읽기 좋게 표현하는 방법이다.
*/

struct Player
{
    int level;
    int gold;
};

// typedef 별칭이름 기존자료형; : 이전부터 사용하던 문법
typedef Player LegacyPlayer;

// using 별칭이름 = 기존자료형; : C++에서 권장하는 문법
using PlayerInfo = Player;
using PlayerPointer = Player*;

/*
    typedef와 struct를 함께 쓰는 C 스타일 예시

    Enemy  : 구조체 자료형의 별칭
    PEnemy : Enemy* 포인터 자료형의 별칭

    C++에서는 struct Enemy만으로도 Enemy를 자료형 이름으로 사용할 수 있다.
    다만 C 코드 또는 오래된 게임 코드에서는 아래처럼 typedef를 함께 사용하는 형태를 볼 수 있다.
*/
typedef struct Enemy
{
    int hp;
    int attack;
} Enemy, *PEnemy;

int main()
{
    // Player, LegacyPlayer, PlayerInfo는 모두 같은 Player 자료형을 가리킨다.
    PlayerInfo player = { 1, 500 };

    // PlayerPointer는 Player*의 별칭이다.
    PlayerPointer pPlayer = &player;

    player.level = 2;      // . : 객체 자체의 멤버에 접근
    pPlayer->gold += 300;  // -> : 포인터가 가리키는 객체의 멤버에 접근

    // 아래 두 문장은 같은 의미다.
    (*pPlayer).level += 1;
    pPlayer->level += 1;

    std::cout << "레벨: " << player.level << '\n';
    std::cout << "골드: " << player.gold << "G\n";

    std::cout << "\n===== typedef struct Enemy 예시 =====\n";
    Enemy enemy = { 100, 20 };
    PEnemy pEnemy = &enemy; // PEnemy는 Enemy*의 별칭이다.

    pEnemy->hp -= 30;
    std::cout << "적 체력: " << enemy.hp << '\n';
    std::cout << "적 공격력: " << pEnemy->attack << '\n';

    return 0;
}
