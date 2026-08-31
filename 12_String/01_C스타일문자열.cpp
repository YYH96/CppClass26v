#include <cstring>  // strlen, strcmp, strcat_s
#include <iostream>

/*
    C 스타일 문자열

    char 배열 끝에는 문자열이 끝났음을 알리는 '\0' 널 문자가 필요하다.
    "Hello"는 문자 5개와 널 문자 1개이므로 6칸이 필요하다.

    새 C++ 코드에서는 보통 std::string을 사용하지만,
    기존 C 코드나 저수준 API에서는 char 배열 문자열을 만날 수 있다.
*/

int main()
{
    char message[30] = "Hello";
    char playerName[] = "Kim"; // 배열 크기를 생략하면 널 문자를 포함한 크기로 결정된다.

    std::cout << "message: " << message << '\n';
    std::cout << "message 길이: " << std::strlen(message) << '\n';

    // strcat_s(대상 배열, 대상 배열 크기, 붙일 문자열)
    // 대상 배열에 충분한 공간이 있는지 함께 전달한다.
    strcat_s(message, sizeof(message), " C++");
    std::cout << "문자열을 붙인 뒤: " << message << '\n';

    // strcmp의 반환값이 0이면 두 문자열의 내용이 같다.
    if (std::strcmp(playerName, "Kim") == 0)
    {
        std::cout << "플레이어 이름이 Kim입니다.\n";
    }

    std::cout << "\n===== char*와 const char* =====\n";

    // 문자열 리터럴("Warrior")은 수정하면 안 되는 영역에 존재할 수 있다.
    // 따라서 문자열 리터럴을 가리킬 때는 const char*를 사용한다.
    const char* jobName = "Warrior";
    std::cout << "직업: " << jobName << '\n';

    jobName = "Mage"; // 포인터가 가리키는 문자열은 다른 리터럴로 바꿀 수 있다.
    std::cout << "변경한 직업: " << jobName << '\n';
    // jobName[0] = 'M'; // 오류: const char*를 통해 문자열 리터럴을 수정할 수 없다.
	jobName = message; // 포인터가 가리키는 문자열을 다른 문자열로 바꿀 수 있다.
    std::cout << "변경한 직업: " << jobName << '\n';

    // 수정 가능한 char 배열을 가리킬 때는 char*를 사용할 수 있다.
    char mutableName[] = "Kim";
    char* pName = mutableName;
    pName[0] = 'T'; // pName이 가리키는 배열의 첫 번째 문자를 수정한다.
    std::cout << "char*로 수정한 이름: " << mutableName << '\n';

    // char* wrong = "Kim"; // C++에서는 문자열 리터럴을 char*에 저장할 수 없다.
    // 리터럴을 수정하려 하면 위험하므로 const char*를 사용해야 한다.

    // char wrong[5] = { 'H', 'e', 'l', 'l', 'o' }; // 널 문자가 없어 문자열로 사용하면 위험

    return 0;
}
