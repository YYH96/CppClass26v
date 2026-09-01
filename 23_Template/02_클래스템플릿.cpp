/*
    클래스 템플릿

    클래스의 멤버 자료형을 T로 일반화한다.
    Box<int>, Box<double>, Box<std::string>처럼 필요한 자료형을 붙여 객체를 만든다.
*/

#include <iostream>
#include <string>

template<typename T>
class Box
{
private:
    T mX;
    T mY;

public:
    Box(const T& x, const T& y)
        : mX(x), mY(y)
    {
    }

    void Print() const
    {
        // T는 std::cout으로 출력할 수 있는 자료형이어야 한다.
        std::cout << "X: " << mX << ", Y: " << mY << '\n';
    }

    const T& GetX() const
    {
        return mX;
    }

    const T& GetY() const
    {
        return mY;
    }
};

int main()
{
    Box<int> intBox(10, 20);
    Box<double> doubleBox(1.5, 2.75);
    Box<std::string> stringBox("검", "방패");

    intBox.Print();
    doubleBox.Print();
    stringBox.Print();

    return 0;
}
