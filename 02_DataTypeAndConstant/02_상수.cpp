#include <iostream>
#include <iterator>

// 매크로 상수: 전처리 단계에서 단순 치환되므로 타입 검사가 없다.
#define MAX_PLAYER_COUNT 4

/*
    상수(Constant): 프로그램 실행 중 값을 바꾸지 않는 데이터
    리터럴, const, constexpr, 매크로를 비교한다.

    !기억 - 리터럴 상수는 모두 데이터 영역에 저장되는 것이 아니다.
    정수, 실수, 문자 리터럴은 보통 명령어 안의 즉시값으로 사용되어
    별도의 메모리 공간을 차지하지 않는다.
    반면 문자열 리터럴("Hello")은 정적 저장 기간을 가지며,
    보통 읽기 전용 데이터 영역(.rdata 또는 .rodata)에 저장된다.
    실제 배치는 컴파일러와 최적화 설정에 따라 달라질 수 있다.
*/
int main()
{
    // 리터럴: 소스 코드에 직접 작성한 고정값
    int level = 10;
    double ratio = 0.5;
    char grade = 'A';
    bool isReady = true;
    std::cout << "literals: " << level << ", " << ratio << ", " << grade << ", " << isReady << "\n";

    // const: 선언 시 초기화해야 하며 이후 값을 바꿀 수 없다.
    const int maxUser = 100;
    // maxUser = 200; // 오류

    // constexpr: 반드시 컴파일 시간에 값을 결정할 수 있는 상수다.
    constexpr double kPi = 3.141592653589793;
    constexpr int kArraySize = 5;
    int scores[kArraySize]{};

    std::cout << "const maxUser: " << maxUser << "\n";
    std::cout << "constexpr pi: " << kPi << ", array size: " << std::size(scores) << "\n";
    std::cout << "macro MAX_PLAYER_COUNT: " << MAX_PLAYER_COUNT << "\n";

    return 0;
}
