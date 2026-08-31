#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>

/*
    함수 실습 - 검 강화 게임

    1. 검 강화하기: 골드를 지불하고 성공하면 레벨이 1 증가한다.
                   실패하면 검 레벨은 1로 돌아간다.
    2. 검 팔기    : 현재 레벨에 비례한 골드를 받고 검 레벨이 1로 돌아간다.
    3. 돈 받기    : 선택할 때마다 지원금 1,000G를 받는다.

    강화 함수 TryUpgrade는 성공하면 true, 실패하면 false를 반환한다.
*/

// 게임 규칙을 바꾸고 싶을 때 이 값들만 수정한다.
#define START_GOLD 0                         // 게임 시작 골드
#define SUPPORT_GOLD_AMOUNT 1000             // 한 번 받을 수 있는 지원금
#define BASE_UPGRADE_COST 50.0               // 레벨 1 검의 첫 강화 비용
#define UPGRADE_COST_MULTIPLIER 1.5          // 강화 성공 후 다음 강화 비용 배율
#define FIRST_UPGRADE_SUCCESS_RATE 0.75      // 레벨 1 검의 첫 강화 성공 확률
#define SUCCESS_RATE_MULTIPLIER 0.75         // 강화 성공 후 다음 강화 확률 배율
#define SELL_PRICE_MULTIPLIER 100            // 판매가 계산에 곱할 골드

void PrintStatus(int weaponLevel, int gold); // 현재 검 레벨, 골드, 다음 강화 정보를 출력
int GetUpgradeCost(int weaponLevel);         // 현재 검 레벨의 강화 비용을 계산하여 반환
double GetSuccessRate(int weaponLevel);      // 현재 검 레벨의 강화 성공 확률을 계산하여 반환
bool TryUpgrade(int& weaponLevel, int& gold); // 강화 시도 후 성공 여부를 반환
int SellSword(int weaponLevel);              // 현재 검 레벨로 판매 가격을 계산하여 반환
void ReceiveSupportGold(int& gold);          // 지원금을 골드에 더함

int main()
{
    int weaponLevel = 1;
    int gold = START_GOLD;

    while (true)
    {
		system("cls"); // 화면을 지운다. (Windows 전용)
        PrintStatus(weaponLevel, gold);

        std::cout << "1. 검 강화하기\n";
        std::cout << "2. 검 팔기\n";
        std::cout << "3. 돈 받기 (지원금 1,000G)\n";
        std::cout << "0. 게임 종료\n";
        std::cout << "선택: ";

        int menu = 0;
        std::cin >> menu;

        if (menu == 1)
        {
            int upgradeCost = GetUpgradeCost(weaponLevel);

            // 강화 시도 전에 비용을 낼 수 있는지 확인한다.
            if (gold < upgradeCost)
            {
                std::cout << "골드가 부족합니다. 필요한 골드: " << upgradeCost << "G\n";
                continue;
            }

            // 반환값 true는 강화 성공, false는 강화 실패를 뜻한다.
            bool isSuccess = TryUpgrade(weaponLevel, gold);
            if (isSuccess)
            {
                std::cout << "강화 성공! 검 레벨이 " << weaponLevel << "이 되었습니다.\n";
            }
            else
            {
                std::cout << "강화 실패! 검 레벨이 1로 돌아갔습니다.\n";
            }
        }
        else if (menu == 2)
        {
            int soldWeaponLevel = weaponLevel;
            int sellPrice = SellSword(weaponLevel);
            gold += sellPrice;
            weaponLevel = 1;

            std::cout << "레벨 " << soldWeaponLevel << " 검을 " << sellPrice << "G에 팔았습니다.\n";
            std::cout << "판매 후 보유 골드: " << gold << "G\n";
            std::cout << "새 검을 받아 검 레벨이 1이 되었습니다.\n";
        }
        else if (menu == 3)
        {
            ReceiveSupportGold(gold);
        }
        else if (menu == 0)
        {
            std::cout << "게임을 종료합니다.\n";
            break;
        }
        else
        {
            std::cout << "잘못된 선택입니다.\n";
        }
    }

    return 0;
}

void PrintStatus(int weaponLevel, int gold)
{
    int upgradeCost = GetUpgradeCost(weaponLevel);
    int sellPrice = SellSword(weaponLevel);
    double successRate = GetSuccessRate(weaponLevel);

    std::cout << "\n========== 현재 상태 ==========\n";
    std::cout << "현재 무기 강화: +" << weaponLevel << '\n';
    std::cout << "보유 골드: " << gold << "G\n";
    std::cout << "현재 판매 가격: " << sellPrice << "G\n";
    std::cout << "다음 강화 비용: " << upgradeCost << "G\n";
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "다음 강화 성공 확률: " << successRate * 100.0 << "%\n";
    std::cout << "===============================\n";
}

int GetUpgradeCost(int weaponLevel)
{
    // 레벨 1 -> 2 강화 비용은 50G다.
    // 강화에 성공해 레벨이 올라갈 때마다 다음 비용은 1.5배가 된다.
    double cost = BASE_UPGRADE_COST * std::pow(UPGRADE_COST_MULTIPLIER, weaponLevel - 1);

    // 골드는 정수로 사용하므로 소수점 비용은 올림 처리한다.
    return static_cast<int>(std::ceil(cost));
}

double GetSuccessRate(int weaponLevel)
{
    // 레벨 1 -> 2 강화 확률은 75%다.
    // 성공해 레벨이 하나 올라갈 때마다 다음 강화 확률은 이전 확률의 0.75배가 된다.
    return FIRST_UPGRADE_SUCCESS_RATE * std::pow(SUCCESS_RATE_MULTIPLIER, weaponLevel - 1);
}

bool TryUpgrade(int& weaponLevel, int& gold)
{
    int upgradeCost = GetUpgradeCost(weaponLevel);
    double successRate = GetSuccessRate(weaponLevel);

    // 강화 비용은 성공·실패와 관계없이 시도할 때 바로 지불한다.
    gold -= upgradeCost;

    // rand() 결과를 0.0 이상 1.0 이하의 실수로 바꾼다.
    double randomValue = static_cast<double>(rand()) / RAND_MAX;

    if (randomValue < successRate)
    {
        ++weaponLevel;
        return true;
    }

    weaponLevel = 1;
    return false;
}

int SellSword(int weaponLevel)
{
    // 판매가 = 무기 레벨의 제곱 * 100G
    // std::pow(밑, 지수)는 double을 반환하므로 골드(int)로 변환한다.
    double sellPrice = std::pow(weaponLevel, 2) * SELL_PRICE_MULTIPLIER;
    return static_cast<int>(sellPrice);
}

void ReceiveSupportGold(int& gold)
{
	// 보유골드가 1000미만일 경우에만 지원금을 받을 수 있다.
	if (gold >= 1000)
	{
		std::cout << "보유 골드가 1,000G를 초과하여 지원금을 받을 수 없습니다.\n";
		return;
	}

    gold += SUPPORT_GOLD_AMOUNT;
    std::cout << "지원금 " << SUPPORT_GOLD_AMOUNT << "G를 받았습니다.\n";
}
