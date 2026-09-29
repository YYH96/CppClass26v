#include <iostream>
#include <cstdlib> // system("cls"), system("pause")

class TicTacToe
{
private:
    char** Board = nullptr;
    char Player = 'X';
    int TurnCount = 0;

public:
    TicTacToe() = default;

    // 같은 메모리를 중복 해제하지 않도록 복사 금지
    TicTacToe(const TicTacToe&) = delete;
    TicTacToe& operator=(const TicTacToe&) = delete;

    ~TicTacToe()
    {
        if (Board != nullptr)
        {
            // 1. 각 행의 배열 해제
            for (int row = 0; row < 3; ++row)
            {
                delete[] Board[row];
            }

            // 2. 행 포인터 배열 해제
            delete[] Board;
            Board = nullptr;
        }
    }

    void Init()
    {
        if (Board == nullptr)
        {
            // 1. 행의 주소를 저장할 포인터 3개 생성
            Board = new char* [3] {};

            // 2. 각 행에 문자 3칸 생성
            for (int row = 0; row < 3; ++row)
            {
                Board[row] = new char[3];
            }
        }

        // 3. 모든 칸 초기화
        for (int row = 0; row < 3; ++row)
        {
            for (int col = 0; col < 3; ++col)
            {
                Board[row][col] = '.';
            }
        }

        Player = 'X';
        TurnCount = 0;
    }

    void PrintBoard()
    {
        std::cout << "=== 틱택토 ===\n";
        std::cout << "\n  1 2 3\n";

        for (int row = 0; row < 3; ++row)
        {
            std::cout << row + 1 << ' ';

            for (int col = 0; col < 3; ++col)
            {
                std::cout << Board[row][col] << ' ';
            }

            std::cout << '\n';
        }

        std::cout << '\n';
    }

    bool CheckWin()
    {
        for (int i = 0; i < 3; ++i)
        {
            // 가로 검사
            if (Board[i][0] == Player &&
                Board[i][1] == Player &&
                Board[i][2] == Player)
            {
                return true;
            }

            // 세로 검사
            if (Board[0][i] == Player &&
                Board[1][i] == Player &&
                Board[2][i] == Player)
            {
                return true;
            }
        }

        // 왼쪽 위 → 오른쪽 아래 대각선
        if (Board[0][0] == Player &&
            Board[1][1] == Player &&
            Board[2][2] == Player)
        {
            return true;
        }

        // 오른쪽 위 → 왼쪽 아래 대각선
        if (Board[0][2] == Player &&
            Board[1][1] == Player &&
            Board[2][0] == Player)
        {
            return true;
        }

        return false;
    }

    bool Run()
    {
        if (Board == nullptr)
        {
            std::cout << "Init()을 먼저 호출하세요.\n";
            return false;
        }

        // 매 차례 화면을 지우고 게임판 출력
        system("cls");
        PrintBoard();

        int row = 0;
        int col = 0;

        std::cout << Player << " 차례! 행 열 입력(1~3): ";

        if (!(std::cin >> row >> col))
        {
            std::cout << "숫자가 아닌 입력으로 게임을 종료합니다.\n";
            return false;
        }

        // 배열 접근 전에 범위 검사
        if (row < 1 || row > 3 || col < 1 || col > 3)
        {
            std::cout << "1~3 사이로 입력하세요.\n";
            system("pause");
            return true;
        }

        // 입력값 1~3을 인덱스 0~2로 변환
        --row;
        --col;

        if (Board[row][col] != '.')
        {
            std::cout << "이미 놓인 자리입니다.\n";
            system("pause");
            return true;
        }

        Board[row][col] = Player;
        ++TurnCount;

        if (CheckWin())
        {
            system("cls");
            PrintBoard();
            std::cout << Player << " 승리!\n";
            return false;
        }

        if (TurnCount == 9)
        {
            system("cls");
            PrintBoard();
            std::cout << "무승부!\n";
            return false;
        }

        // 다음 플레이어로 변경
        Player = (Player == 'X') ? 'O' : 'X';

        return true;
    }
};

int main()
{
    TicTacToe Game;

    Game.Init();

    while (Game.Run())
    {
    }

    system("pause");

    return 0;
} // Game 소멸자에서 동적 메모리 해제