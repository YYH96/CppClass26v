#include <iostream>
#include <string>

/*
    문자열 함수 코딩 테스트 실습 - 첫 번째 문자열 찾기

    출처: LeetCode 28. Find the Index of the First Occurrence in a String
    https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/

    문제를 수업용 main 함수 형태로 바꾸었다.
    긴 문자열(haystack) 안에서 찾을 문자열(needle)이 처음 등장하는 인덱스를 출력한다.
    찾지 못하면 -1을 출력한다.

    핵심 문자열 함수: haystack.find(needle)
    - 찾으면 시작 위치를 반환한다.
    - 찾지 못하면 std::string::npos를 반환한다.
*/

int FindFirstIndex(const std::string& haystack, const std::string& needle); // needle의 첫 위치 또는 -1 반환
int FindFirstIndexDirectly(const std::string& haystack, const std::string& needle); // find 없이 직접 비교해 첫 위치 또는 -1 반환

int main()
{
    const std::string haystack = "sadbutsad";

    // 첫 번째 문자열은 haystack 안에 있으므로 위치 0이 나온다.
    const std::string foundNeedle = "sad";

    // 두 번째 문자열은 haystack 안에 없으므로 -1이 나온다.
    const std::string notFoundNeedle = "leeto";

    int foundIndex = FindFirstIndex(haystack, foundNeedle);
    int notFoundIndex = FindFirstIndex(haystack, notFoundNeedle);

    std::cout << "긴 문자열: " << haystack << "\n\n";
    std::cout << "찾을 문자열 1: " << foundNeedle << ", 결과 위치: " << foundIndex << '\n';
    std::cout << "찾을 문자열 2: " << notFoundNeedle << ", 결과 위치: " << notFoundIndex << '\n';

    std::cout << "\n===== find를 직접 구현한 결과 =====\n";
    std::cout << "찾을 문자열 1 결과 위치: " << FindFirstIndexDirectly(haystack, foundNeedle) << '\n';
    std::cout << "찾을 문자열 2 결과 위치: " << FindFirstIndexDirectly(haystack, notFoundNeedle) << '\n';

    return 0;
}

int FindFirstIndex(const std::string& haystack, const std::string& needle)
{
    std::size_t position = haystack.find(needle);

    if (position == std::string::npos)
    {
        return -1;
    }

    // find의 반환형은 std::size_t이므로, 문제의 정수 반환 형식에 맞춰 int로 변환한다.
    return static_cast<int>(position);
}

/*
    std::string::find를 직접 구현한 버전

    바깥 반복문: haystack에서 needle을 시작해 볼 위치를 하나씩 이동한다.
    안쪽 반복문: 현재 시작 위치부터 needle의 모든 문자가 같은지 비교한다.
*/
int FindFirstIndexDirectly(const std::string& haystack, const std::string& needle)
{
    // 빈 문자열은 첫 번째 위치에서 찾은 것으로 처리한다.
    if (needle.empty())
    {
        return 0;
    }

    // 찾을 문자열이 더 길면 포함될 수 없다.
    if (needle.size() > haystack.size())
    {
        return -1;
    }

    // needle이 들어갈 수 있는 마지막 시작 위치까지 확인한다.
    for (std::size_t startIndex = 0; startIndex <= haystack.size() - needle.size(); ++startIndex)
    {
        bool isSame = true;

        for (std::size_t needleIndex = 0; needleIndex < needle.size(); ++needleIndex)
        {
            if (haystack[startIndex + needleIndex] != needle[needleIndex])
            {
                isSame = false;
                break;
            }
        }

        if (isSame)
        {
            return static_cast<int>(startIndex);
        }
    }

    return -1;
}
