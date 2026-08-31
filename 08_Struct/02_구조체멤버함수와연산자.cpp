#include <iostream>

/*
    구조체는 멤버 변수뿐 아니라 멤버 함수를 가질 수 있다.
    같은 구조체의 멤버 함수는 자신의 멤버 변수에 바로 접근할 수 있다.

    또한 사용자 정의 연산자를 만들어 구조체끼리 +, += 같은 연산을 할 수 있다.
*/

struct Point
{
    int x;
    int y;

    void Print() const
    {
        // const 멤버 함수는 이 함수 안에서 x, y를 바꾸지 않겠다는 뜻이다.
        std::cout << "x: " << x << ", y: " << y << '\n';
    }

    Point operator+(const Point& other) const
    {
        // Point + Point의 결과로 새 Point를 반환한다.
        return { x + other.x, y + other.y };
    }

    Point& operator+=(const Point& other)
    {
        // 현재 객체 자신의 값을 바꾼 뒤, 자기 자신을 참조로 반환한다.
        x += other.x;
        y += other.y;
        return *this;
    }
};

int main()
{
    Point point1{ 1, 2 };
    Point point2{ 10, 20 };

    Point result = point1 + point2;
    std::cout << "point1 + point2: ";
    result.Print();

    point1 += point2;
    std::cout << "point1 += point2: ";
    point1.Print();

    return 0;
}
