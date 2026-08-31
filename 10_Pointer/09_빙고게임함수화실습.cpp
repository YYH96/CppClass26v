/*
    포인터 실습 - 빙고 게임 함수화

    06_Array의 "빙고게임_메인만사용" 예제를 함수로 나눈 버전이다.

    main의 int playerBoard[25]를 함수에 전달하면 배열의 첫 번째 요소 주소가 전달된다.
    따라서 int board[] 매개변수로 값을 바꾸면 원본 빙고판도 바뀐다.

    - int board[]       : 함수가 원본 배열을 변경해야 할 때 사용
    - const int board[] : 함수가 원본 배열을 읽기만 할 때 사용

    함수 매개변수에서 int board[]와 int* board는 같은 의미다.
    이번 예제에서는 "배열을 받는다"는 의도가 보이도록 [] 표기를 사용한다.
*/

#include <climits> // INT_MAX
#include <cstdlib> // rand, srand, system
#include <ctime>   // time
#include <iostream>

#define BINGO_SIZE 5                         // 빙고판의 가로, 세로 칸 수
#define BINGO_CELL_COUNT (BINGO_SIZE * BINGO_SIZE) // 빙고판 전체 칸 수
#define WIN_BINGO_LINE 5                     // 승리하기 위해 필요한 빙고 줄 수
#define MARKED_NUMBER INT_MAX                // 선택한 숫자를 표시하는 특별한 값

void InitializeBoard(int board[]);                         // 1~25 숫자로 빙고판 초기화
void ShuffleBoard(int board[]);                            // 빙고판 숫자 순서를 섞음
void PrintBoards(const int playerBoard[], const int aiBoard[]); // 플레이어와 AI 빙고판 출력
int InputNumber();                                         // 플레이어 숫자 입력
bool MarkNumber(int board[], int number);                  // 숫자를 찾아 표시하고 성공 여부 반환
int GetAINumber(const int aiBoard[]);                      // AI가 아직 선택하지 않은 숫자 하나를 반환
int CountBingoLines(const int board[]);                    // 가로, 세로, 대각선의 빙고 줄 수를 반환

int main()
{
    srand((unsigned int)time(0));

    int playerBoard[BINGO_CELL_COUNT] = {};
    int aiBoard[BINGO_CELL_COUNT] = {};

    InitializeBoard(playerBoard);
    InitializeBoard(aiBoard);

    ShuffleBoard(playerBoard);
    ShuffleBoard(aiBoard);

    while (true)
    {
        int playerBingoCount = CountBingoLines(playerBoard);
        int aiBingoCount = CountBingoLines(aiBoard);

        system("cls");
        PrintBoards(playerBoard, aiBoard);
        std::cout << "플레이어 빙고: " << playerBingoCount
            << "\t\tAI 빙고: " << aiBingoCount << "\n\n";

        if (playerBingoCount >= WIN_BINGO_LINE)
        {
            std::cout << "플레이어 승리!\n";
            break;
        }
        if (aiBingoCount >= WIN_BINGO_LINE)
        {
            std::cout << "AI 승리!\n";
            break;
        }

        int playerNumber = InputNumber();
        if (playerNumber == 0)
        {
            std::cout << "게임을 종료합니다.\n";
            break;
        }
        if (playerNumber < 1 || playerNumber > BINGO_CELL_COUNT)
        {
            std::cout << "1~" << BINGO_CELL_COUNT << " 사이의 숫자를 입력하세요.\n";
            system("pause");
            continue;
        }

        // 플레이어가 고른 숫자를 플레이어 빙고판에서 표시한다.
        if (MarkNumber(playerBoard, playerNumber) == false)
        {
            std::cout << "이미 선택한 숫자입니다.\n";
            system("pause");
            continue;
        }

        // 같은 숫자는 AI 빙고판에도 표시한다.
        MarkNumber(aiBoard, playerNumber);

        // AI가 아직 선택하지 않은 숫자 중 하나를 고른다.
        int aiNumber = GetAINumber(aiBoard);
        if (aiNumber == 0)
        {
            std::cout << "더 이상 선택할 숫자가 없습니다.\n";
            break;
        }

        std::cout << "AI가 선택한 숫자: " << aiNumber << '\n';

        // AI가 고른 숫자도 두 빙고판에 모두 표시한다.
        MarkNumber(playerBoard, aiNumber);
        MarkNumber(aiBoard, aiNumber);

        system("pause");
    }

    return 0;
}

void InitializeBoard(int board[])
{
    for (int i = 0; i < BINGO_CELL_COUNT; ++i)
    {
        board[i] = i + 1;
    }
}

void ShuffleBoard(int board[])
{
    // 임의의 두 칸을 여러 번 골라 서로 바꾼다.
    for (int i = 0; i < 100; ++i)
    {
        int firstIndex = rand() % BINGO_CELL_COUNT;
        int secondIndex = rand() % BINGO_CELL_COUNT;

        int temp = board[firstIndex];
        board[firstIndex] = board[secondIndex];
        board[secondIndex] = temp;
    }
}

void PrintBoards(const int playerBoard[], const int aiBoard[])
{
    std::cout << "================ 플레이어 ================     ================== AI ==================\n";

    for (int row = 0; row < BINGO_SIZE; ++row)
    {
        for (int column = 0; column < BINGO_SIZE; ++column)
        {
            int index = row * BINGO_SIZE + column;

            if (playerBoard[index] == MARKED_NUMBER)
            {
                std::cout << "*\t";
            }
            else
            {
                std::cout << playerBoard[index] << '\t';
            }
        }

        std::cout << "||\t";

        for (int column = 0; column < BINGO_SIZE; ++column)
        {
            int index = row * BINGO_SIZE + column;

            if (aiBoard[index] == MARKED_NUMBER)
            {
                std::cout << "*\t";
            }
            else
            {
                std::cout << aiBoard[index] << '\t';
            }
        }

        std::cout << '\n';
    }
}

int InputNumber()
{
    int number = 0;
    std::cout << "숫자를 입력하세요. (0: 게임 종료): ";
    std::cin >> number;
    return number;
}

bool MarkNumber(int board[], int number)
{
    for (int i = 0; i < BINGO_CELL_COUNT; ++i)
    {
        if (board[i] == number)
        {
            board[i] = MARKED_NUMBER;
            return true;
        }
    }

    return false;
}

int GetAINumber(const int aiBoard[])
{
    int selectableNumbers[BINGO_CELL_COUNT] = {};
    int selectableCount = 0;

    for (int i = 0; i < BINGO_CELL_COUNT; ++i)
    {
        if (aiBoard[i] != MARKED_NUMBER)
        {
            selectableNumbers[selectableCount] = aiBoard[i];
            ++selectableCount;
        }
    }

    if (selectableCount == 0)
    {
        return 0;
    }

    return selectableNumbers[rand() % selectableCount];
}

int CountBingoLines(const int board[])
{
    int bingoCount = 0;

    // 가로 5줄과 세로 5줄을 검사한다.
    for (int line = 0; line < BINGO_SIZE; ++line)
    {
        int rowMarkedCount = 0;
        int columnMarkedCount = 0;

        for (int index = 0; index < BINGO_SIZE; ++index)
        {
            if (board[line * BINGO_SIZE + index] == MARKED_NUMBER)
            {
                ++rowMarkedCount;
            }
            if (board[index * BINGO_SIZE + line] == MARKED_NUMBER)
            {
                ++columnMarkedCount;
            }
        }

        if (rowMarkedCount == BINGO_SIZE)
        {
            ++bingoCount;
        }
        if (columnMarkedCount == BINGO_SIZE)
        {
            ++bingoCount;
        }
    }

    int leftToRightMarkedCount = 0;
    int rightToLeftMarkedCount = 0;

    for (int index = 0; index < BINGO_SIZE; ++index)
    {
        // 왼쪽 위 -> 오른쪽 아래: 0, 6, 12, 18, 24
        if (board[index * BINGO_SIZE + index] == MARKED_NUMBER)
        {
            ++leftToRightMarkedCount;
        }

        // 오른쪽 위 -> 왼쪽 아래: 4, 8, 12, 16, 20
        int rightToLeftIndex = index * BINGO_SIZE + (BINGO_SIZE - 1 - index);
        if (board[rightToLeftIndex] == MARKED_NUMBER)
        {
            ++rightToLeftMarkedCount;
        }
    }

    if (leftToRightMarkedCount == BINGO_SIZE)
    {
        ++bingoCount;
    }
    if (rightToLeftMarkedCount == BINGO_SIZE)
    {
        ++bingoCount;
    }

    return bingoCount;
}
