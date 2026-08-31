#include <iostream>
#include <limits>

/*
    반복문 실습 3 - switch문으로 성적 출력하기

    점수를 계속 입력받는다.
    -99를 입력하면 반복문을 종료하고, 0~100 이외의 점수는 다시 입력받는다.
*/
int main()
{
    while (true)
    {
        std::cout << "점수를 입력하세요. (-99 입력 시 종료): ";

        int score = 0;
        if (!(std::cin >> score))
        {
            // 숫자가 아닌 입력값이 남아 있으면 다음 반복도 실패하므로 함께 비운다.
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "점수는 숫자로 입력해주세요.\n";
            continue;
        }

        if (score == -99)
        {
            std::cout << "성적 출력을 종료합니다.\n";
            break;
        }

        if (score < 0 || score > 100)
        {
            std::cout << "점수는 0점부터 100점 사이로 입력해주세요.\n";
            continue;
        }

        // score / 10의 몫으로 10점 단위 구간을 나눈다.
        // 예: 87 / 10은 8이므로 B 학점이 출력된다.
        switch (score / 10)
        {
        case 10: // 100점
        case 9:  // 90~99점
            std::cout << "학점: A\n";
            break;
        case 8:
            std::cout << "학점: B\n";
            break;
        case 7:
            std::cout << "학점: C\n";
            break;
        case 6:
            std::cout << "학점: D\n";
            break;
        default: // 0~59점
            std::cout << "학점: F\n";
            break;
        }
    }

    return 0;
}
