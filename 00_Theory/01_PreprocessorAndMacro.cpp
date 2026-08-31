/*
    전처리기(Preprocessor)

    전처리기는 컴파일러가 C++ 코드를 번역하기 전에 먼저 소스 코드를 처리한다.
    #으로 시작하는 전처리기 지시문을 처리한 결과가 컴파일러에게 전달된다.

    주요 역할
    1. 파일 포함        : #include
    2. 매크로 치환      : #define
    3. 조건부 컴파일    : #if, #ifdef, #ifndef 등
*/

#include <iostream> // #include: iostream 헤더의 내용을 이 위치에 포함한다.

// -----------------------------------------------------------------------------
// 객체형 매크로(Object-like macro)
// 형태: #define 매크로이름 대체할_값
// 인수가 없으며, 전처리 단계에서 이름이 단순 텍스트로 치환된다.
// -----------------------------------------------------------------------------
#pragma region 객체형_매크로

#define PI 3.141592
#define BUFFER_SIZE 1024
#define COMPANY_NAME "CPP26V"

#pragma endregion

// -----------------------------------------------------------------------------
// 함수형 매크로(Function-like macro)
// 형태: #define 매크로이름(인수) 대체할_코드
// 매크로 이름과 여는 괄호 사이에는 공백이 있으면 안 된다.
// -----------------------------------------------------------------------------
#pragma region 함수형_매크로

// 괄호가 없으면 SQUARE(number + 1)이 number + 1 * number + 1로 치환될 수 있다.
#define SQUARE(value) ((value) * (value))
#define MAX(left, right) (((left) > (right)) ? (left) : (right))

#pragma endregion

// #define DEBUG_OUTPUT
// 위 주석을 해제하면 DEBUG_OUTPUT이 정의되고 #ifdef DEBUG_OUTPUT 영역이 포함된다.

// #define TEMP_MACRO 100
// #undef TEMP_MACRO
// #undef는 이미 정의된 매크로를 해제한다.

// #define PRINT_LEVEL 2
// #if, #elif, #else는 값으로 조건을 검사할 때 사용할 수 있다.
#define PRINT_LEVEL 2

int main()
{
#pragma region 객체형_매크로_사용

    double radius = 10.0;
    double area = PI * radius * radius; // PI는 3.141592로 치환된다.
    char buffer[BUFFER_SIZE] = {};

    std::cout << "원 넓이: " << area << '\n';
    std::cout << "버퍼 크기: " << sizeof(buffer) << '\n';
    std::cout << "프로젝트 이름: " << COMPANY_NAME << "\n\n";

#pragma endregion

#pragma region 함수형_매크로_사용

    int number = 5;
    int left = 20;
    int right = 30;

    std::cout << "SQUARE(number): " << SQUARE(number) << '\n';
    std::cout << "SQUARE(number + 1): " << SQUARE(number + 1) << '\n';
    std::cout << "MAX(left, right): " << MAX(left, right) << "\n\n";

    /*
        SQUARE(number + 1)은 전처리 후 다음처럼 치환된다.

        ((number + 1) * (number + 1))

        매크로는 일반 함수 호출이 아니라 단순 텍스트 치환이다.
        따라서 SQUARE(++number)처럼 부작용이 있는 식을 넣으면
        number가 두 번 증가할 수 있으므로 주의한다.
    */

#pragma endregion

#pragma region 조건부_컴파일

#if PRINT_LEVEL == 1
    std::cout << "출력 단계: 기본\n";
#elif PRINT_LEVEL == 2
    std::cout << "출력 단계: 상세\n";
#else
    std::cout << "출력 단계: 사용자 정의\n";
#endif

#ifdef DEBUG_OUTPUT
    // DEBUG_OUTPUT을 #define 했을 때만 이 줄이 컴파일된다.
    std::cout << "[DEBUG] 디버그 출력이 활성화되었습니다.\n";
#endif

    /*
        프로젝트별 전처리기 정의 추가하기 (Visual Studio)

        프로젝트 우클릭 -> 속성 -> 구성 속성 -> C/C++ -> 전처리기
        -> 전처리기 정의에 CLASS26_TEACHING;%(PreprocessorDefinitions) 추가

        이 프로젝트의 Debug 구성에는 CLASS26_TEACHING이 실제로 등록되어 있다.
        구성별로 정의할 수 있으므로 Debug와 Release에서 서로 다른 코드를 포함할 수 있다.
    */
#ifdef CLASS26_TEACHING
    std::cout << "CLASS26_TEACHING 사용자 정의 구성이 활성화되었습니다.\n";
#endif

#ifndef UNKNOWN_MACRO
    // UNKNOWN_MACRO가 정의되어 있지 않을 때만 이 코드가 컴파일된다.
    std::cout << "UNKNOWN_MACRO는 정의되어 있지 않습니다.\n";
#endif

#pragma endregion

#pragma region Debug_Release

    /*
        Debug   : 개발 중 오류를 찾기 위한 구성이다.
                  디버깅 정보가 포함되고, 보통 최적화를 줄여 추적하기 쉽다.

        Release : 배포를 위한 구성이다.
                  보통 최적화를 적용하여 성능과 파일 크기에 유리하다.

        Visual Studio는 일반적으로 Debug에 _DEBUG를,
        Release에 NDEBUG를 전처리기 매크로로 정의한다.
    */
#ifdef _DEBUG
    std::cout << "현재 빌드 구성: Debug (개발·디버깅용)\n";
#else
    std::cout << "현재 빌드 구성: Release (배포·최적화용)\n";
#endif

#pragma endregion

    /*
        #pragma는 특정 컴파일러의 기능을 제어하는 비표준 지시어다.
        Visual Studio의 #pragma region은 코드를 접는 영역을 만들 때 사용할 수 있다.

        단순 상수는 #define보다 const 또는 constexpr을 우선 사용한다.
    */
    constexpr int MaxStage = 10;
    std::cout << "constexpr 상수 MaxStage: " << MaxStage << '\n';

    return 0;
}
