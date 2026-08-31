#include <conio.h>  // _kbhit, _getch: Windows 콘솔 키 입력
#include <cstdlib>  // std::rand, std::srand, std::system
#include <ctime>    // std::time
#include <iostream>
#include <windows.h> // Sleep, 콘솔 커서 제어: Windows 전용

/*
	스네이크 게임
	- W/A/S/D로 이동 방향을 바꿉니다.
	- F 먹이를 먹으면 점수 +10, 꼬리 길이 +1
	- 벽 또는 자기 꼬리에 닿으면 게임 종료
	- X를 누르면 게임 종료

	게임 반복 흐름
	1. Draw()  : 화면 출력
	2. Input() : 키 입력 처리
	3. Logic() : 이동, 충돌, 먹이 처리
*/

struct Point
{
	int x;
	int y;
};

enum eDirection
{
	STOP = 0,
	LEFT,
	RIGHT,
	UP,
	DOWN
};

#define BOARD_WIDTH 20               // 게임 보드의 가로 칸 수
#define BOARD_HEIGHT 20              // 게임 보드의 세로 칸 수
#define MAX_TAIL_LENGTH 100          // 꼬리 좌표 배열의 최대 칸 수
#define GAME_DELAY_MILLISECOND 100   // 게임 한 프레임의 대기 시간(밀리초)

bool gameOver;
Point head;
Point fruit;
Point tail[MAX_TAIL_LENGTH];
int tailLength;
int score;
eDirection direction;

void HideCursor();
void Setup();
void CreateFruit();
void Draw();
void Input();
void Logic();

void HideCursor()
{
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(output, &cursorInfo);
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(output, &cursorInfo);
}

void Setup()
{
	HideCursor();

	gameOver = false;
	direction = STOP;
	head.x = BOARD_WIDTH / 2;
	head.y = BOARD_HEIGHT / 2;
	tailLength = 0;
	score = 0;

	CreateFruit();
}

void CreateFruit()
{
	bool overlapsSnake = false;

	do
	{
		overlapsSnake = false;
		fruit.x = std::rand() % BOARD_WIDTH;
		fruit.y = std::rand() % BOARD_HEIGHT;

		if (fruit.x == head.x && fruit.y == head.y)
		{
			overlapsSnake = true;
		}

		for (int i = 0; i < tailLength; ++i)
		{
			if (fruit.x == tail[i].x && fruit.y == tail[i].y)
			{
				overlapsSnake = true;
				break;
			}
		}
	} while (overlapsSnake);
}

void Draw()
{
	std::system("cls"); // Windows 콘솔 화면 지우기

	for (int i = 0; i < BOARD_WIDTH + 2; ++i)
	{
		std::cout << '#';
	}
	std::cout << '\n';

	for (int y = 0; y < BOARD_HEIGHT; ++y)
	{
		std::cout << '#';

		for (int x = 0; x < BOARD_WIDTH; ++x)
		{
			if (x == head.x && y == head.y)
			{
				std::cout << 'O'; // 뱀 머리
			}
			else if (x == fruit.x && y == fruit.y)
			{
				std::cout << 'F'; // 먹이
			}
			else
			{
				bool isTail = false;
				for (int i = 0; i < tailLength; ++i)
				{
					if (tail[i].x == x && tail[i].y == y)
					{
						std::cout << 'o'; // 뱀 꼬리
						isTail = true;
						break;
					}
				}

				if (!isTail)
				{
					std::cout << ' ';
				}
			}
		}

		std::cout << "#\n";
	}

	for (int i = 0; i < BOARD_WIDTH + 2; ++i)
	{
		std::cout << '#';
	}
	std::cout << "\n점수: " << score << " / W A S D 이동, X 종료\n";
}

void Input()
{
	if (!_kbhit())
	{
		return;
	}

	switch (_getch())
	{
	case 'a':
	case 'A':
		direction = LEFT;
		break;
	case 'd':
	case 'D':
		direction = RIGHT;
		break;
	case 'w':
	case 'W':
		direction = UP;
		break;
	case 's':
	case 'S':
		direction = DOWN;
		break;
	case 'x':
	case 'X':
		gameOver = true;
		break;
	default:
		break;
	}
}

void Logic()
{
	// 꼬리는 이동 전 머리 위치를 따라갑니다.
	for (int i = tailLength - 1; i >= 0; --i)
	{
		if (i == 0)
		{
			tail[i] = head;
		}
		else
		{
			tail[i] = tail[i - 1];
		}
	}

	switch (direction)
	{
	case LEFT:
		--head.x;
		break;
	case RIGHT:
		++head.x;
		break;
	case UP:
		--head.y;
		break;
	case DOWN:
		++head.y;
		break;
	case STOP:
	default:
		break;
	}

	if (head.x < 0 || head.x >= BOARD_WIDTH || head.y < 0 || head.y >= BOARD_HEIGHT)
	{
		gameOver = true;
	}

	for (int i = 0; i < tailLength; ++i)
	{
		if (head.x == tail[i].x && head.y == tail[i].y)
		{
			gameOver = true;
		}
	}

	if (head.x == fruit.x && head.y == fruit.y)
	{
		score += 10;
		if (tailLength < MAX_TAIL_LENGTH)
		{
			++tailLength;
		}
		CreateFruit();
	}
}

int main()
{
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	Setup();

	while (!gameOver)
	{
		Draw();
		Input();
		Logic();
		Sleep(GAME_DELAY_MILLISECOND);
	}

	std::cout << "\n게임 종료! 최종 점수: " << score << '\n';
	return 0;
}
