#include <iostream>
#include <iomanip> // std::fixed, std::setprecision

/*
    기본 자료형 변환과 C 스타일 형변환

    암시적 형변환: 컴파일러가 자동으로 변환한다.
    명시적 형변환: 프로그래머가 변환 의도를 직접 적는다.

    변환은 값의 형태를 바꾸는 작업이다.
    목적지 자료형에 값을 모두 담을 수 있는지 확인해야 한다.
*/

int main()
{
    int score = 95;
    double average = score; // int -> double: 암시적 형변환

    std::cout << "score(int): " << score << '\n';

    // std::cout은 double 95.0을 기본 설정에서 95처럼 출력할 수 있다.
    // fixed와 setprecision(1)을 쓰면 소수점 아래 한 자리까지 항상 표시한다.
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "average(double): " << average << "\n\n";

    // 출력 조작자는 이후 std::cout에도 계속 적용된다.
    // defaultfloat은 fixed 설정을 해제하고, setprecision(6)은 기본 정밀도로 되돌린다.
    std::cout << std::defaultfloat << std::setprecision(6);

    double ratio = 3.9;
    int count = ratio; // double -> int: 소수점 아래가 버려진다.

    std::cout << "ratio(double): " << ratio << '\n';
    std::cout << "count(int): " << count << "\n\n";



    char grade = 'A';
    int gradeCode = grade; // char -> int: 문자 코드값으로 변환
    std::cout << "grade: " << grade << ", 문자 코드: " << gradeCode << '\n';

    int life = 0;
    bool isDead = life == 0; // 비교식 결과는 bool이다.
    std::cout << std::boolalpha;
    std::cout << "isDead: " << isDead << '\n';

    std::cout << "\n===== C 스타일 형변환 =====\n";

    // 문법: (바꿀자료형)값
    // 짧게 쓸 수 있지만, C++에서는 static_cast가 의도를 더 명확하게 보여 권장된다.
    double damageRate = 12.8;
    int damage = (int)damageRate; // 소수점 아래가 버려져 12가 된다.

    int successfulAttack = 3;
    int totalAttack = 4;
    double successRate = (double)successfulAttack / totalAttack;

    std::cout << "damageRate(double): " << damageRate << '\n';
    std::cout << "damage(int): " << damage << '\n';
    std::cout << "C 스타일로 계산한 성공률(double): " << successRate * 100.0 << "%\n";

    /*
        C 스타일 캐스트는 상황에 따라 static_cast, const_cast, reinterpret_cast와
        비슷한 변환을 모두 시도할 수 있다. 그래서 위험한 변환도 짧게 보일 수 있다.

        double ratio = 0.5;
        int* pNumber = (int*)&ratio; // 자료형 해석을 강제로 바꾸는 위험한 코드
    */

    return 0;
}
