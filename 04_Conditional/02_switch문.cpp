#include <iostream>

/*
    switch 문

    하나의 값이 여러 개의 정해진 값(case) 중 무엇과 같은지 분기할 때 사용한다.
    case에는 정수, 문자, enum처럼 컴파일 시간에 알 수 있는 상수 값을 사용한다.
*/
int main()
{
    int day = 6;

    switch (day)
    {
    case 1:
        std::cout << "월요일\n";
        break; // break가 없으면 다음 case도 계속 실행된다.
    case 2:
        std::cout << "화요일\n";
        break;
    case 3:
        std::cout << "수요일\n";
        break;
    case 4:
        std::cout << "목요일\n";
        break;
    case 5:
        std::cout << "금요일\n";
        break;
    case 6:
    case 7: // case 6과 7은 같은 동작을 하도록 묶었다.
        std::cout << "주말\n";
        break;
    default:
        std::cout << "1부터 7 사이의 숫자를 입력하세요.\n";
        break;
    }

    /*
        !기억
        - break를 생략하면 다음 case로 넘어가는 fall-through가 발생한다.
        - 의도적인 fall-through가 아니라면 각 case 끝에 break를 작성한다.
        - switch는 범위 비교(score >= 90)보다 특정 값 하나를 비교하는 경우에 적합하다.
        - float, double, std::string은 switch의 조건식에 사용할 수 없다.
    */
    return 0;
}
