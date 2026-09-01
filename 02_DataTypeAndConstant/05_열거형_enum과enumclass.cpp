#include <iostream>

/*
    열거형(enum)

    - 여러 정수 값에 의미 있는 이름을 붙여 하나의 종류로 묶는 사용자 정의 자료형이다.
    - 예: 방향, 직업, 게임 상태처럼 선택지의 수가 정해진 값에 잘 어울린다.

    일반 enum
    - 열거자 이름을 바로 사용한다. 예: WEAPON_SWORD
    - 열거자 이름이 바깥 이름 공간에 그대로 생겨 이름 충돌에 주의해야 한다.

    enum class
    - 열거자 앞에 자료형 이름을 붙여 사용한다. 예: eTeam::RED
    - 다른 enum과 이름이 겹칠 위험이 적고, int로 자동 변환되지 않아 더 안전하다.
*/

// 일반 enum: 값을 따로 지정하지 않으면 0부터 1씩 증가한다.
enum eWeaponType
{
    WEAPON_SWORD,  // 0
    WEAPON_BOW,    // 1
    WEAPON_STAFF   // 2
};

// enum class: RED, BLUE 같은 이름은 eTeam 안에 속한다.
enum class eTeam
{
    RED = 1,
    BLUE,
    NEUTRAL
};

int main()
{
    // 일반 enum은 열거자 이름을 바로 사용한다.
    eWeaponType weapon = WEAPON_BOW;

    std::cout << "선택한 무기: ";

    // enum 값은 switch의 조건으로 자주 사용한다.
    switch (weapon)
    {
    case WEAPON_SWORD:
        std::cout << "검\n";
        break;
    case WEAPON_BOW:
        std::cout << "활\n";
        break;
    case WEAPON_STAFF:
        std::cout << "지팡이\n";
        break;
    default:
        // 모든 열거자를 처리했다면 보통 실행되지 않는다.
        // 잘못된 값이 들어온 경우를 대비해 작성한다.
        std::cout << "알 수 없는 무기\n";
        break;
    }

    // enum class는 반드시 eTeam::처럼 범위를 붙여서 사용한다.
    eTeam team = eTeam::RED;

    if (team == eTeam::RED)
    {
        std::cout << "팀: 레드팀\n";
    }

    // enum class는 int로 자동 변환되지 않는다.
    // 정수 값이 정말 필요할 때만 static_cast를 사용한다.
    std::cout << "레드팀의 저장 정수값: " << static_cast<int>(team) << '\n';

    return 0;
}
