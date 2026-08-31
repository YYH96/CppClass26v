# lvalue와 rvalue

## 값에도 종류가 있다

C++의 식(expression)은 단순히 값만 가지는 것이 아니라, 그 값을 어떻게 다룰 수 있는지 나타내는 **값 범주(value category)** 도 가집니다. 입문 단계에서는 lvalue와 rvalue를 먼저 구분하면 충분합니다.

## lvalue(엘밸류)란?

**lvalue**는 프로그램 안에서 계속 가리킬 수 있는 대상입니다. 보통 이름이 있는 변수이며, 주소를 구할 수 있습니다.

```cpp
int hp = 100;
int& hpReference = hp;

std::cout << &hp << '\n';          // 가능
std::cout << &hpReference << '\n'; // 가능, hp와 같은 주소
```

`hp`와 `hpReference`는 모두 lvalue입니다. `hpReference`는 hp의 별칭이지만, 표현식으로 사용할 때 hp와 같은 대상을 가리킵니다.

## rvalue(알밸류)란?

**rvalue**는 계산 중 잠시 만들어지는 값, 리터럴, 임시 객체 등을 말합니다. 보통 독립적인 이름으로 계속 가리키지 않습니다.

```cpp
int hp = 100;
int damage = hp + 5;

// 5        : rvalue (리터럴)
// hp + 5   : rvalue (계산 결과)
// damage   : lvalue (이름 있는 변수)
```

## 왼쪽과 오른쪽이라는 설명은 기억법이다

lvalue는 “left value”, rvalue는 “right value”라는 이름 때문에 대입문 왼쪽·오른쪽으로만 외우기 쉽습니다.

```cpp
int hp = 100;
```

위 코드에서 `hp`는 왼쪽에 있고 lvalue, `100`은 오른쪽에 있고 rvalue입니다. 하지만 위치만으로 판단하면 부족합니다. 핵심은 **식이 끝난 뒤에도 계속 가리킬 수 있는 대상인가**입니다.

```cpp
int hp = 100;
hp = hp + 10;

// 왼쪽 hp     : lvalue
// 오른쪽 hp    : lvalue (위치가 오른쪽이어도 이름 있는 변수)
// hp + 10     : rvalue
```

## 참조와의 관계

```cpp
int hp = 100;

int& lvalueReference = hp;       // 일반 참조: lvalue에 연결
const int& constReference = 10;  // const 참조: rvalue를 읽기 전용으로 연결 가능
int&& rvalueReference = 10;      // rvalue 참조: rvalue에 연결
```

| 참조 형태 | 주로 연결하는 대상 | 특징 |
| --- | --- | --- |
| `Type&` | 수정 가능한 lvalue | 원본을 직접 변경할 수 있음 |
| `const Type&` | lvalue 또는 rvalue | 복사 없이 읽기 전용으로 사용 |
| `Type&&` | rvalue | 이동 생성자·이동 대입에 활용 |

## 주의: 이름이 있는 rvalue 참조 변수는 lvalue

```cpp
int&& temporary = 10;
```

`temporary`는 rvalue 참조로 선언되었지만, **temporary라는 이름을 사용한 표현식은 lvalue**입니다. 이름을 통해 나중에 다시 접근할 수 있기 때문입니다.

```cpp
// SomeFunction(temporary); // temporary는 lvalue로 전달됩니다.
```

이를 rvalue처럼 다시 전달하고 싶을 때 `std::move(temporary)`를 사용합니다. `std::move`는 실제로 값을 옮기는 함수가 아니라, 이동 생성자나 이동 대입 연산자가 선택될 수 있게 rvalue 형태로 바꾸는 도구입니다.

```cpp
// SomeFunction(std::move(temporary));
```

이동 생성자와 rvalue 참조의 실제 예제는 `15_Constructor`, 참조 매개변수 활용은 `16_Reference` 프로젝트에서 이어서 확인합니다.
