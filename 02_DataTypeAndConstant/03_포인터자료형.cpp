#include <iostream>

/*
    포인터 자료형: 다른 변수의 값이 아니라 메모리 주소를 저장한다.
    &: 변수의 주소를 얻는다.  *: 포인터 선언 또는 가리키는 값을 사용한다.
*/
int main()
{
    int score = 100;
    int bonusScore = 200;
    int* scorePointer = &score;

    std::cout << "score value: " << score << "\n";
    std::cout << "score address: " << scorePointer << "\n";

    *scorePointer = 150; // scorePointer가 가리키는 score의 값을 변경한다.
    std::cout << "score after dereference: " << score << "\n";

    scorePointer = &bonusScore; // 포인터는 다른 대상의 주소를 다시 저장할 수 있다.
    *scorePointer += 50;
    std::cout << "bonusScore: " << bonusScore << "\n";

    scorePointer = nullptr; // 어떤 객체도 가리키지 않는 널 포인터
    if (scorePointer == nullptr)
    {
        std::cout << "scorePointer does not point to an object.\n";
    }

    // nullptr을 역참조(*scorePointer)하면 오류가 발생하므로 사용하지 않는다.
    return 0;
}
