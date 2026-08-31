#include <cstring> // strcmp, strcpy_s, strtok_s
#include <iostream>

/*
	몬스터 찾기
	- 쉼표(,)로 이어진 C 스타일 문자열을 strtok_s로 하나씩 분리합니다.
	- 분리한 이름을 2차원 char 배열에 저장합니다.
	- strcmp로 입력 문자열과 몬스터 이름이 같은지 비교합니다.

	strtok_s 주의점
	- 문자열을 분리하는 과정에서 구분자 위치를 '\0'으로 바꾸므로 원본 문자열이 수정됩니다.
	- 따라서 "Goblin,Orc" 같은 문자열 리터럴 포인터가 아니라 수정 가능한 char 배열을 사용해야 합니다.
	- strtok_s는 Visual Studio에서 strtok보다 안전하게 분리 상태를 별도 context에 보관하는 함수입니다.
*/

#define MONSTER_LIST_COUNT 10      // 목록에 들어 있는 몬스터 수
#define MAX_MONSTER_NAME_LENGTH 30 // 널 문자까지 포함한 몬스터 이름 최대 크기

int main()
{
	// 수정 가능한 char 배열: strtok_s가 쉼표 위치를 '\0'으로 바꿉니다.
	char monsterList[] = "Goblin,Orc,Dragon,Skeleton,Zombie,Troll,Vampire,Ghost,Hydra,Slime";

	/*
		2차원 배열
		- 배열 안에 배열이 들어 있는 형태입니다.
		- char monsterNames[행][열]로 읽습니다.
		- 행(row) : 몬스터 한 마리씩을 구분하는 세로 칸입니다.
		- 열(column) : 한 몬스터 이름을 이루는 문자 한 글자씩을 저장하는 가로 칸입니다.

		monsterNames[0]은 첫 번째 행, 즉 첫 번째 몬스터 이름 전체를 뜻합니다.
		monsterNames[0][0]은 첫 번째 몬스터 이름의 첫 번째 문자입니다.

		아래 배열은 행 10개(몬스터 최대 10마리), 열 30개(이름 한 개당 문자 공간 30칸)입니다.
	*/
	// 각 행에 몬스터 이름 하나를 저장하는 2차원 문자 배열입니다.
	char monsterNames[MONSTER_LIST_COUNT][MAX_MONSTER_NAME_LENGTH] = {};

	// strtok_s의 분리 상태를 저장하는 포인터입니다.
	char* context = nullptr;
	char* token = strtok_s(monsterList, ",", &context);
	int monsterCount = 0;

	while (token != nullptr && monsterCount < MONSTER_LIST_COUNT)
	{
		// strcpy_s(목적지, 목적지크기, 원본)는 크기를 확인하며 복사합니다.
		strcpy_s(monsterNames[monsterCount], MAX_MONSTER_NAME_LENGTH, token);

		// 첫 호출 뒤에는 첫 번째 인자에 nullptr을 전달해 다음 토큰을 받습니다.
		token = strtok_s(nullptr, ",", &context);
		++monsterCount;
	}

	std::cout << "[등록된 몬스터] ";
	for (int i = 0; i < monsterCount; ++i)
	{
		std::cout << monsterNames[i] << ' ';
	}
	std::cout << "\n\n";

	char userInput[MAX_MONSTER_NAME_LENGTH] = {};
	std::cout << "찾고 싶은 몬스터 이름을 입력하세요(영문, 대소문자 구분): ";
	std::cin >> userInput;

	bool found = false;
	for (int i = 0; i < monsterCount; ++i)
	{
		// strcmp의 반환값이 0이면 두 C 스타일 문자열의 내용이 같습니다.
		if (strcmp(userInput, monsterNames[i]) == 0)
		{
			found = true;
			break;
		}
	}

	if (found)
	{
		std::cout << "입력한 '" << userInput << "' 몬스터가 존재합니다.\n";
	}
	else
	{
		std::cout << "입력한 '" << userInput << "' 몬스터는 존재하지 않습니다.\n";
	}

	return 0;
}
