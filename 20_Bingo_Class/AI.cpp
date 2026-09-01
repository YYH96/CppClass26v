#include "AI.h"

#include <cstdlib>
#include <vector>

int CAI::GetInputNumber() const
{
    // 아직 표시하지 않은 숫자만 후보 vector에 담는다.
    std::vector<int> candidates;

    for (int number : mBingo)
    {
        if (number != MARKED_NUMBER)
        {
            candidates.push_back(number);
        }
    }

    // 더 고를 숫자가 없으면 0을 반환한다. 빙고 숫자는 1~25이므로 구분할 수 있다.
    if (candidates.empty())
    {
        return 0;
    }

    const int randomIndex = std::rand() % static_cast<int>(candidates.size());
    return candidates[randomIndex];
}
