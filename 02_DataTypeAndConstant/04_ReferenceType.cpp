#include <iostream>

/*
    레퍼런스 자료형: 기존 변수의 별칭(alias)이다.
    선언과 동시에 대상에 연결해야 하고, 이후 다른 대상을 참조하도록 바꿀 수 없다.
*/
int main()
{
    int health = 100;
    int& healthReference = health;

    healthReference -= 30; // 원본 health의 값이 변경된다.
    std::cout << "health: " << health << "\n";
    std::cout << "&health == &healthReference: " << (&health == &healthReference) << "\n";

    int nextHealth = 200;
    healthReference = nextHealth;
    // 위 문장은 참조 대상을 바꾸는 것이 아니라 health에 200을 대입한다.
    std::cout << "health after assignment: " << health << "\n";

    // const 레퍼런스는 복사 없이 읽기 전용으로 참조할 때 유용하다.
    const int& readOnlyHealth = health;
    std::cout << "readOnlyHealth: " << readOnlyHealth << "\n";
    // readOnlyHealth = 50; // 오류

    return 0;
}
