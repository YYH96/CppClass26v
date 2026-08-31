#include <iostream>

/*
    사용자 정의 연산자(User-defined Operators, Operator Overloading)

    기본 자료형에는 +, ==, ++ 등이 이미 정의되어 있다.
    struct나 class 같은 사용자 정의 자료형은 operator 함수를 작성해
    필요한 연산자의 동작을 직접 정의할 수 있다.
*/

struct Point
{
    int x;
    int y;

    // Point + Point를 좌표별 덧셈으로 정의한다.
    Point operator+(const Point& other) const
    {
        return { x + other.x, y + other.y };
    }

    // +=는 현재 객체를 바꾸므로 참조를 반환한다.
    Point& operator+=(const Point& other)
    {
        x += other.x;
        y += other.y;
        return *this;
    }

    // ==는 두 좌표가 모두 같은지 비교한다.
    bool operator==(const Point& other) const
    {
        return x == other.x && y == other.y;
    }

    // 전위 증가: 먼저 증가하고, 변경된 현재 객체를 참조로 반환한다.
    Point& operator++()
    {
        ++x;
        ++y;
        return *this;
    }

    // 후위 증가: int 매개변수는 전위와 구분하기 위한 표식이다.
    // 증가 전 값을 복사본으로 반환해야 하므로 값으로 반환한다.
    Point operator++(int)
    {
        Point before = *this;
        ++(*this);
        return before;
    }
};

void PrintPoint(const Point& point)
{
    std::cout << "(" << point.x << ", " << point.y << ")\n";
}

int main()
{
    Point first{ 1, 2 };
    Point second{ 3, 4 };

    Point sum = first + second;
    std::cout << "first + second = ";
    PrintPoint(sum);

    first += second;
    std::cout << "first after += second = ";
    PrintPoint(first);

    std::cout << std::boolalpha;
    std::cout << "first == sum: " << (first == sum) << "\n";

    Point beforeIncrement = first++;
    std::cout << "first++ returned: ";
    PrintPoint(beforeIncrement);
    std::cout << "first after first++: ";
    PrintPoint(first);

    ++first;
    std::cout << "first after ++first: ";
    PrintPoint(first);

    return 0;
}
