#include <iostream>

/*
	[1단계: 처음에는 이렇게 사용하면 안 됩니다.]

	class Device
	{
	public:
		void PowerOn() const { }
	};

	class Cpu : public Device { };
	class Gpu : public Device { };
	class GameComputer : public Cpu, public Gpu { };

	GameComputer computer;
	computer.PowerOn();
	// 오류: Cpu 쪽 Device::PowerOn()인지 Gpu 쪽 Device::PowerOn()인지 모호합니다.
	// GameComputer 안에 Device 부분이 두 개 생겼기 때문입니다.

	[2단계: virtual 상속으로 공통 부모(Device)를 하나만 둡니다.]
	- Cpu, Gpu가 virtual public Device로 상속하면 Device 부분은 하나만 생깁니다.

	[3단계: 오버라이딩도 충돌할 수 있습니다.]
	- Cpu와 Gpu가 Device::PowerOn()을 각각 override하면, 최종 자식은 어느 구현을 쓸지 결정해야 합니다.
	- GameComputer가 PowerOn()을 다시 override하면 최종 구현이 명확해집니다.

	다중 상속은 역할이 분명한 기능을 조합할 때만 신중하게 사용합니다.
*/

class Device
{
public:
	virtual void PowerOn() const
	{
		std::cout << "장치 전원을 켭니다.\n";
	}
};

// virtual 상속: GameComputer 안에 Device 부분이 하나만 생기도록 합니다.
class Cpu : virtual public Device
{
public:
	void PowerOn() const override
	{
		std::cout << "CPU 전원을 켭니다.\n";
	}

	void Calculate() const
	{
		std::cout << "CPU가 계산합니다.\n";
	}
};

class Gpu : virtual public Device
{
public:
	void PowerOn() const override
	{
		std::cout << "GPU 전원을 켭니다.\n";
	}

	void Render() const
	{
		std::cout << "GPU가 화면을 그립니다.\n";
	}
};

class GameComputer : public Cpu, public Gpu
{
public:
	// Cpu와 Gpu가 Device::PowerOn()을 각각 override했으므로,
	// 최종 자식 GameComputer가 어떤 구현을 사용할지 한 번 더 override하여 결정합니다.
	void PowerOn() const override
	{
		std::cout << "게임 컴퓨터 전원을 켭니다.\n";
		Cpu::PowerOn(); // CPU 쪽 구현을 명시적으로 호출
		Gpu::PowerOn(); // GPU 쪽 구현을 명시적으로 호출
	}

	void PlayGame() const
	{
		std::cout << "게임을 실행합니다.\n";
	}
};

int main()
{
	std::cout << "[virtual 상속과 최종 override로 해결한 코드]\n";
	GameComputer computer;

	computer.PowerOn(); // GameComputer가 최종 override한 PowerOn()이 호출됩니다.
	computer.Calculate();
	computer.Render();
	computer.PlayGame();

	return 0;
}
