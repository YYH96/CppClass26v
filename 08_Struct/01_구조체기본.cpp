#include <iostream>
#include <string>

/*
    구조체(struct)란?
    서로 다른 자료형의 데이터를 하나의 논리적인 단위로 묶는 사용자 정의 자료형이다.

    예: 학생 한 명은 이름(string), 학번(int), 평균(double)처럼
    서로 다른 종류의 데이터를 함께 가져야 한다. 이런 데이터를 구조체로 묶어 관리한다.

    C++의 struct는 멤버 변수뿐 아니라 멤버 함수도 가질 수 있으며,
    기본 접근 지정자가 public이라는 점을 제외하면 class와 같은 기능을 지원한다.
*/

struct Point
{
    int x;
    int y;
};

struct Student
{
    std::string name;
    int studentId;
    int korean;
    int english;
    int math;
    int total;
    double average;
};

int main()
{
    // 구조체 초기화 방법 1: 중괄호 초기화
    Point point1 = { 10, 20 };

    // 구조체 초기화 방법 2: C++11 리스트 초기화(권장)
    Point point2{ 30, 40 };

    // 구조체 초기화 방법 3: 멤버별 직접 대입
    Point point3{}; // {}로 먼저 초기화하면 모든 멤버가 0으로 초기화된다.
    point3.x = 100;
    point3.y = 200;

    std::cout << "point1: (" << point1.x << ", " << point1.y << ")\n";
    std::cout << "point2: (" << point2.x << ", " << point2.y << ")\n";
    std::cout << "point3: (" << point3.x << ", " << point3.y << ")\n\n";

    // 구조체 배열: Point 구조체 두 개를 배열로 만든다.
    Point points[2] = { {1, 2}, {3, 4} };
    for (const Point& point : points)
    {
        std::cout << "구조체 배열 요소: (" << point.x << ", " << point.y << ")\n";
    }

    Student student{
        "Kim",
        1001,
        90,
        80,
        100,
        0,
        0.0
    };

    student.total = student.korean + student.english + student.math;
    student.average = student.total / 3.0;

    // .(점) 연산자로 구조체 변수의 멤버에 접근한다.
    std::cout << "\n학생 이름: " << student.name << '\n';
    std::cout << "총점: " << student.total << ", 평균: " << student.average << '\n';

    return 0;
}
