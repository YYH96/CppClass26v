#include <iostream>

/*
    반복문 실습 1 - 별찍기 5가지

    바깥쪽 반복문은 행(row)을, 안쪽 반복문은 한 행의 공백과 별 개수를 담당한다.
*/

void PrintRectangle()
{
    std::cout << "[1. 5 x 5 사각형]\n";
    for (int row = 0; row < 5; ++row)
    {
        for (int star = 0; star < 5; ++star)
        {
            std::cout << '*';
        }
        std::cout << '\n';
    }
}

void PrintTopLeftRightTriangle()
{
    std::cout << "\n[2. 왼쪽 위가 직각인 직각삼각형]\n";
    for (int row = 0; row < 5; ++row)
    {
        // 첫 줄은 별 5개, 다음 줄부터 별 개수를 하나씩 줄인다.
        for (int star = 0; star < 5 - row; ++star)
        {
            std::cout << '*';
        }
        std::cout << '\n';
    }
}

void PrintPyramid()
{
    std::cout << "\n[3. 피라미드]\n";
    for (int row = 0; row < 5; ++row)
    {
        // 오른쪽 정렬을 위한 공백: 4개에서 시작해 한 개씩 감소한다.
        for (int space = 0; space < 4 - row; ++space)
        {
            std::cout << ' ';
        }

        // 별 개수: 1, 3, 5, 7, 9처럼 홀수로 증가한다.
        for (int star = 0; star < row * 2 + 1; ++star)
        {
            std::cout << '*';
        }
        std::cout << '\n';
    }
}

void PrintDiamond()
{
    std::cout << "\n[4. 다이아몬드]\n";

    // 위쪽 피라미드: 가운데 줄까지 출력한다.
    for (int row = 0; row < 5; ++row)
    {
        for (int space = 0; space < 4 - row; ++space)
        {
            std::cout << ' ';
        }
        for (int star = 0; star < row * 2 + 1; ++star)
        {
            std::cout << '*';
        }
        std::cout << '\n';
    }

    // 아래쪽 역피라미드: 가운데 줄은 이미 출력했으므로 row 3부터 시작한다.
    for (int row = 3; row >= 0; --row)
    {
        for (int space = 0; space < 4 - row; ++space)
        {
            std::cout << ' ';
        }
        for (int star = 0; star < row * 2 + 1; ++star)
        {
            std::cout << '*';
        }
        std::cout << '\n';
    }
}

void PrintRhombus()
{
    std::cout << "\n[5. 마름모]\n";
    for (int row = 0; row < 5; ++row)
    {
        // 행이 내려갈수록 앞 공백을 하나씩 줄여 기울어진 사각형을 만든다.
        for (int space = 0; space < 4 - row; ++space)
        {
            std::cout << ' ';
        }
        for (int star = 0; star < 5; ++star)
        {
            std::cout << '*';
        }
        std::cout << '\n';
    }
}

int main()
{
    PrintRectangle();
    PrintTopLeftRightTriangle();
    PrintPyramid();
    PrintDiamond();
    PrintRhombus();

    return 0;
}
