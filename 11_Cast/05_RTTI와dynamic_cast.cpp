#include <iostream>
#include <typeinfo> // typeid

/*
    RTTI(Run-Time Type Information)

    실행 중에 객체의 실제 자료형을 확인하는 기능이다.

    - typeid: 객체의 타입 정보를 확인
    - dynamic_cast: 기반 클래스 포인터를 실제 파생 클래스 포인터로 안전하게 변환

    dynamic_cast를 사용하려면 기반 클래스에 virtual 함수가 하나 이상 있어야 한다.
    여기서는 virtual 소멸자를 사용한다. 상속과 virtual의 자세한 내용은 클래스 수업에서 다룬다.

    class는 기본 접근 지정자가 private이므로, 외부에서 사용할 멤버 앞에는 public:을 적는다.
*/

class Character
{
public:
    virtual ~Character() = default; // RTTI를 위한 다형적 기반 클래스
};

class Player : public Character
{
public:
    int level = 10;
};

class Monster : public Character
{
public:
    int hp = 100;
};

void PrintCharacterInfo(Character* character); // 실제 타입을 확인해 정보를 출력

int main()
{
    Player player;
    Monster monster;

    Character* characters[2] = { &player, &monster };

    for (Character* character : characters)
    {
        PrintCharacterInfo(character);
    }

    return 0;
}

void PrintCharacterInfo(Character* character)
{
    // typeid(*character)는 포인터 변수의 타입이 아니라 실제 객체의 타입 정보를 얻는다.
    // name()의 출력 형태는 컴파일러마다 다를 수 있다.
    std::cout << "실제 타입 정보: " << typeid(*character).name() << '\n';

    // Player가 아닌 객체를 Player*로 바꾸려 하면 nullptr을 반환한다.
    Player* pPlayer = dynamic_cast<Player*>(character);
    if (pPlayer != nullptr)
    {
        std::cout << "플레이어 레벨: " << pPlayer->level << "\n\n";
        return;
    }

    Monster* pMonster = dynamic_cast<Monster*>(character);
    if (pMonster != nullptr)
    {
        std::cout << "몬스터 체력: " << pMonster->hp << "\n\n";
    }
}
