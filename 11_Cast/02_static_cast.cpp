#include <iostream>

/*
    static_cast

    문법: static_cast<바꿀자료형>(값)

    숫자형과 열거형처럼 일반적인 명시적 변환에 사용한다.
    C 스타일 캐스트보다 어떤 변환을 하려는지 명확하게 보인다.
*/

enum class Job
{
    Warrior = 1,
    Archer = 2
};

int main()
{
    int successfulAttack = 3;
    int totalAttack = 4;

    // 먼저 double로 변환해야 정수 나눗셈이 아닌 실수 나눗셈이 된다.
    double successRate = static_cast<double>(successfulAttack) / totalAttack;
    std::cout << "성공률: " << successRate * 100.0 << "%\n";

    double damageRate = 12.8;
    int damage = static_cast<int>(damageRate); // 12, 소수점 아래는 버려진다.
    std::cout << "정수 피해량: " << damage << '\n';

    char grade = 'A';
    int gradeCode = static_cast<int>(grade);
    std::cout << "A의 문자 코드: " << gradeCode << '\n';

    Job job = Job::Archer;
    int jobNumber = static_cast<int>(job);
    std::cout << "직업 번호: " << jobNumber << '\n';

    return 0;
}
