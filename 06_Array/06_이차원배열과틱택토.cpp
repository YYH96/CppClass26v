/*
    이차원 배열과 틱택토 (두 사람이 번갈아 하는 게임)

    [1. 일차원 배열에서 이차원 배열로]
    일차원 배열은 칸을 한 줄로 나열한다. 예: int numbers[9] = {};
    이차원 배열은 행과 열로 칸을 구분한다. 예: int numbers[3][3] = {};
    [3][3]은 3행 3열이며, 전체 원소 개수는 3 * 3 = 9개이다.

    [2. 행(row)과 열(column)]
    행은 가로 한 줄이다. 행 번호가 커지면 아래쪽으로 이동한다.
    열은 세로 한 줄이다. 열 번호가 커지면 오른쪽으로 이동한다.
    배열 이름[행 인덱스][열 인덱스] 순서로 접근한다.
    인덱스는 0부터 시작하므로 3행 3열 배열의 유효 인덱스는 각각 0~2이다.

                     열 0          열 1          열 2
        행 0     board[0][0]   board[0][1]   board[0][2]
        행 1     board[1][0]   board[1][1]   board[1][2]
        행 2     board[2][0]   board[2][1]   board[2][2]

    board[1][2]는 두 번째 행, 세 번째 열의 칸이다.
    board[3][0]처럼 범위를 벗어난 접근은 하면 안 된다.
    메모리에는 첫 행의 원소들, 다음 행의 원소들 순서로 연속해서 저장된다.

    [3. 초기화와 중첩 반복문]
    char board[3][3] = {
        { '.', '.', '.' },  // 0번 행
        { '.', '.', '.' },  // 1번 행
        { '.', '.', '.' }   // 2번 행
    };
    작은 중괄호 하나가 한 행을 나타낸다. '.'은 빈칸을 나타내는 문자이다.
    char board[3][3] = {};로 초기화하면 '.'이 아니라 값 0인 문자가 들어간다.
    바깥 for문으로 행을 선택하고, 안쪽 for문으로 그 행의 열을 순서대로 방문한다.
    한 행의 출력이 끝날 때 줄을 바꾸면 이차원 배열이 표처럼 보인다.

    [4. 틱택토 규칙]
    두 사람이 X와 O를 번갈아 빈칸에 놓는다. X가 먼저 시작한다.
    같은 기호로 가로, 세로, 대각선 중 한 줄(3칸)을 완성하면 승리한다.
    승자 없이 9칸을 모두 채우면 무승부이다.
    입력은 사람이 읽기 편하도록 1~3의 행 번호와 열 번호를 사용한다.
    예: 2 3 입력 -> board[1][2]에 표시한다. 입력값에서 각각 1을 뺀다.

    [5. 기능별 함수와 배열 전달]
    main은 초기화 -> 출력 -> 입력과 배치 -> 승리 판정 -> 차례 변경 순서로 진행한다.
    각 기능의 자세한 처리는 아래에 정의한 함수가 담당한다.

    이 예제는 포인터를 배운 뒤 학습한다.
    함수 매개변수의 char board[][3]은 char (*board)[3]과 같은 뜻이다.
    char 3개로 이루어진 한 행을 가리키는 포인터로 받는다.
    main에서 InitializeBoard(board)를 호출하면 첫 번째 행의 주소가 전달된다.
    배열 전체를 복사하지 않으므로 함수에서 칸을 수정하면 원본 게임판도 바뀐다.

    첫 번째 []의 행 개수는 생략할 수 있지만, 두 번째 [3]의 열 개수는 필요하다.
    한 행의 크기를 알아야 board + 1이 다음 행으로 이동할 수 있기 때문이다.
    board[row][column]으로 접근하는 방법은 main 안에서와 같다.
    행 개수가 자동으로 전달되는 것은 아니다. 이 예제는 항상 3행 3열을 받는다고 약속한다.
    const char board[][3]은 전달받은 게임판의 문자를 바꾸지 않고 읽기만 한다.
    char**는 char 포인터를 가리키므로 이차원 배열을 받는 타입으로 사용할 수 없다.
*/

#include <iostream> // cin, cout: 키보드 입력과 화면 출력
#include <limits>   // 잘못 입력한 줄을 끝까지 비울 때 사용
#include <cstdlib>  // std::system("cls"): Windows 콘솔 화면 지우기

// 함수 선언: main보다 뒤에 정의한 함수를 main에서 호출할 수 있게 미리 알려준다.
void InitializeBoard(char board[][3]);                     // 모든 칸을 빈칸으로 초기화
void PrintGuide();                                           // 게임 규칙과 입력 방법 안내
void PrintBoard(const char board[][3]);                   // 행·열 번호와 게임판 출력
bool InputAndPlace(char board[][3], char currentPlayer);   // 올바른 입력을 받아 기호 배치
bool CheckWin(const char board[][3], char currentPlayer);  // 현재 사람의 승리 여부 반환
char GetNextPlayer(char currentPlayer);                       // 다음 사람의 기호 반환

int main()
{
    char board[3][3] = {};    // 이 시점에는 값 0인 문자로 채워져 있다.
    InitializeBoard(board);  // 함수를 통해 원본 배열의 모든 칸을 '.'으로 바꾼다.

    char currentPlayer = 'X'; // X부터 시작한다.
    int moveCount = 0;        // 정상적으로 기호를 놓은 횟수

    // 첫 화면: 이전 콘솔 내용을 지운 다음 안내와 게임판을 그린다.
    std::system("cls");
    PrintGuide();
    PrintBoard(board);

    while (true)
    {


        // 입력 함수가 false를 반환하면 사용자가 종료했거나 입력이 끝난 것이다.
        // 잘못된 입력은 함수 내부에서 다시 받으므로 true일 때만 수를 센다.
        if (!InputAndPlace(board, currentPlayer))
        {
            break;
        }
        ++moveCount;

        // 한 수를 정상적으로 놓았을 때 화면을 갱신한다.
        // 순서: 화면 지우기 -> 안내와 바뀐 게임판 출력 -> 결과 또는 다음 차례 표시.
        // 입력 함수 안에서 지우면 잘못된 입력 안내가 사라질 수 있으므로 여기서 지운다.
        std::system("cls");
        PrintGuide();
        PrintBoard(board); // 방금 놓은 기호와 마지막 승리·무승부 게임판까지 표시한다.

        // 아홉 번째 수로 이길 수도 있으므로 승리를 무승부보다 먼저 확인한다.
        if (CheckWin(board, currentPlayer))
        {
            std::cout << "\n" << currentPlayer << " 승리!\n";
            break;
        }
        if (moveCount == 9)
        {
            std::cout << "\n무승부! 모든 칸이 찼습니다.\n";
            break;
        }

        // 반환된 기호를 대입해야 main의 현재 차례가 실제로 바뀐다.
        currentPlayer = GetNextPlayer(currentPlayer);


    }

    return 0;
}

// [초기화] 중첩 반복문으로 원본 게임판의 9칸을 모두 빈칸 '.'으로 바꾼다.
void InitializeBoard(char board[][3])
{
    for (int row = 0; row < 3; ++row)
    {
        for (int column = 0; column < 3; ++column)
        {
            board[row][column] = '.';
        }
    }
}

// [안내] 화면을 지운 뒤 다시 표시할 게임 규칙과 입력 방법을 모아 둔다.
void PrintGuide()
{
    std::cout << "=== 이차원 배열 틱택토 ===\n";
    std::cout << "두 사람이 X, O를 번갈아 놓습니다. .은 빈칸입니다.\n";
    std::cout << "가로, 세로, 대각선으로 같은 기호 3개를 연결하면 승리합니다.\n";
    std::cout << "행 열 순서로 입력하세요. 예: 2 3 (2행 3열)\n";
}

// [출력] const char 배열을 가리키는 포인터로 받아 게임판을 읽기만 한다.
void PrintBoard(const char board[][3])
{
    std::cout << "\n        열\n";
    std::cout << "      1   2   3\n";
    for (int row = 0; row < 3; ++row)
    {
        // 배열 인덱스는 0~2지만 화면의 행 번호는 1~3이다.
        std::cout << "행 " << row + 1 << "  ";
        for (int column = 0; column < 3; ++column)
        {
            std::cout << board[row][column];
            if (column < 2)
            {
                std::cout << " | "; // 마지막 열 뒤에는 구분선을 붙이지 않는다.
            }
        }
        std::cout << '\n'; // 한 행의 세 칸을 출력했으므로 다음 행으로 내려간다.
        if (row < 2)
        {
            std::cout << "      ---------\n";
        }
    }
}

// [입력과 배치] true: 빈칸에 기호를 놓음, false: 게임 종료 요청 또는 입력 종료.
// 잘못된 입력은 내부 while에서 다시 받는다. 따라서 같은 사람의 차례가 유지된다.
// currentPlayer는 문자 하나를 값으로 받으며, 이 함수에서 차례를 바꾸지 않는다.
bool InputAndPlace(char board[][3], char currentPlayer)
{
    while (true)
    {
        int inputRow = 0;
        int inputColumn = 0;
        std::cout << "\n" << currentPlayer << " 차례 - 행 열 입력 (종료: 0 0): ";

        // 정수 두 개를 읽지 못했다면 입력 종료인지 잘못된 입력인지 구분한다.
        if (!(std::cin >> inputRow >> inputColumn))
        {
            if (std::cin.eof())
            {
                std::cout << "\n입력이 끝나 게임을 종료합니다.\n";
                return false; // 함수 전체를 끝내고 main에 종료를 알린다.
            }
            std::cin.clear(); // 입력 실패 상태를 해제한다.
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "행과 열을 정수 두 개로 입력하세요. 예: 1 2\n";
            continue; // 이 함수의 while 처음으로 돌아가 다시 입력받는다.
        }

        // 이번 줄의 남은 내용을 버려 다음 입력에 영향을 주지 않게 한다.
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (inputRow == 0 && inputColumn == 0)
        {
            std::cout << "게임을 종료합니다.\n";
            return false;
        }

        // 배열에 접근하기 전에 범위를 검사해야 잘못된 메모리 접근을 막을 수 있다.
        if (inputRow < 1 || inputRow > 3 || inputColumn < 1 || inputColumn > 3)
        {
            std::cout << "행과 열은 각각 1~3이어야 합니다.\n";
            continue;
        }

        // 사람이 입력한 번호(1~3)를 배열 인덱스(0~2)로 바꾼다.
        int row = inputRow - 1;
        int column = inputColumn - 1;
        if (board[row][column] != '.')
        {
            std::cout << "이미 놓인 칸입니다. 빈칸을 선택하세요.\n";
            continue;
        }

        board[row][column] = currentPlayer; // 전달받은 주소로 원본 배열의 칸을 수정한다.
        return true; // 한 수를 정상적으로 놓았으므로 main으로 돌아간다.
    }
}

// [승리 판정] 방금 놓은 사람의 기호가 한 줄을 완성했으면 true, 아니면 false.
// 빈칸끼리 같은지를 비교하지 않고 X 또는 O가 세 칸에 있는지를 확인한다.
bool CheckWin(const char board[][3], char currentPlayer)
{
    // 가로 3줄: 행은 고정하고 열 0, 1, 2를 비교한다.
    for (int row = 0; row < 3; ++row)
    {
        if (board[row][0] == currentPlayer &&
            board[row][1] == currentPlayer &&
            board[row][2] == currentPlayer)
        {
            return true; // 승리한 줄을 찾으면 남은 줄은 검사하지 않아도 된다.
        }
    }

    // 세로 3줄: 열은 고정하고 행 0, 1, 2를 비교한다.
    for (int column = 0; column < 3; ++column)
    {
        if (board[0][column] == currentPlayer &&
            board[1][column] == currentPlayer &&
            board[2][column] == currentPlayer)
        {
            return true;
        }
    }

    // 왼쪽 위 -> 오른쪽 아래 대각선: 행과 열의 인덱스가 같다.
    if (board[0][0] == currentPlayer &&
        board[1][1] == currentPlayer &&
        board[2][2] == currentPlayer)
    {
        return true;
    }

    // 오른쪽 위 -> 왼쪽 아래 대각선: 행은 증가하고 열은 감소한다.
    if (board[0][2] == currentPlayer &&
        board[1][1] == currentPlayer &&
        board[2][0] == currentPlayer)
    {
        return true;
    }

    return false; // 가로 3줄 + 세로 3줄 + 대각선 2줄 모두 승리 조건이 아니다.
}

// [차례 변경] 현재 기호를 받아 반대 기호를 반환한다.
// 값으로 받은 매개변수이므로 main의 변수는 직접 바뀌지 않는다.
char GetNextPlayer(char currentPlayer)
{
    if (currentPlayer == 'X')
    {
        return 'O';
    }
    return 'X';
}
