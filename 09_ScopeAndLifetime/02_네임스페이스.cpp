#include <iostream>

/*
    네임스페이스(namespace)란?
    이름이 충돌하지 않도록 함수, 변수, 구조체 등을 이름 공간으로 묶는 기능이다.

    std::cout의 std도 C++ 표준 라이브러리의 네임스페이스다.
    :: 연산자는 네임스페이스 안에 있는 이름에 접근할 때 사용한다.
*/

namespace Morning
{
    void PrintGreeting()
    {
        std::cout << "좋은 아침입니다.\n";
    }

    int GetClassStartHour()
    {
        return 9;
    }
}

namespace Evening
{
    // Morning에도 같은 이름의 함수가 있어도, 서로 다른 네임스페이스에 있으므로 충돌하지 않는다.
    void PrintGreeting()
    {
        std::cout << "좋은 저녁입니다.\n";
    }

    int GetClassStartHour()
    {
        return 19;
    }
}

int main()
{
    // 네임스페이스이름::이름 형태로 정확한 대상을 지정한다.
    Morning::PrintGreeting();
    std::cout << "아침 수업 시작 시각: " << Morning::GetClassStartHour() << "시\n\n";

    Evening::PrintGreeting();
    std::cout << "저녁 수업 시작 시각: " << Evening::GetClassStartHour() << "시\n\n";

    /*
        using 선언과 using namespace

        using Morning::PrintGreeting;
        처럼 특정 이름 하나만 가져오는 방식은 범위가 명확하다.

        using namespace Morning;
        처럼 네임스페이스 전체를 가져올 수도 있지만, 이름 충돌 가능성이 커진다.
        특히 헤더 파일이나 전역 범위에서는 using namespace를 사용하지 않는 것이 좋다.
    */

    {
        // 필요한 작은 범위 안에서만 using 선언을 사용할 수 있다.
        using Morning::GetClassStartHour;
        std::cout << "using 선언으로 가져온 시각: " << GetClassStartHour() << "시\n";
    }

    // GetClassStartHour(); // 오류: 위 블록 안에서만 using 선언이 유효하다.

    return 0;
}
