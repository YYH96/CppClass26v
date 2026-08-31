//전처리기 
#include <iostream>

//c++ 11 전용 int 
#include <cstdint>

//넘어가도 되는거 
//cout 에서 double 값을 보기 위해서 추가. 
//std::setprecision 
#include <iomanip>

//주석 
//주석 코드에서 예외됩니다. 
// //를 이용하거나
	/*
		주석 1
		주석 2
	*/
	//을 이용해서 주석을 사용합니다 . 

	/*
		출력문
		#include <iostream>

		출력문
		printf();
		std:: cout;

		# 이스케이프 시퀀스
		- 특정 문자를 조합하여 줄을 바꾸거나 특별한 문자를 출력할때 사용하는 조합문자
		https://learn.microsoft.com/ko-kr/cpp/c-language/escape-sequences?view=msvc-170

		\n : 줄바꿈
		\t : tab 만큼 공백
		\" : 특수문자도 출력하게 해준다.
		\\ : \를 출력해준다 이것도 특수문자다 .



		# 서식지정자
		- 변수의 자료형에 맞는 형식으로 값을 출력할 때 사용하는 기호
		- printf()에서 주로 사용한다.

		# 정수
		%d : 부호 있는 10진수 정수
		%i : 부호 있는 10진수 정수
		%u : 부호 없는 10진수 정수
		%x : 16진수 정수
		%o : 8진수 정수

		# 실수
		%f : 실수
		%lf : double형 실수
		%e : 지수 표기법
		%g : 실수 또는 지수 표기법 중 짧은 형식

		# 문자와 문자열
		%c : 문자
		%s : 문자열

		# 포인터
		%p : 포인터 주소
		- 포인터 주소를 출력할 때 사용한다.
		- 주소는 보통 16진수 형태로 출력된다.

		예시:
		int number = 10;
		double real = 3.14;
		int* pointer = &number;

		printf("%d\n", number);
		printf("%f\n", real);
		printf("%p\n", pointer);
	*/


	/*
		자료형

		-변수 : 프로그램에서 데이터를 저장하고 조작할 수 있도록 이름을 붙인 메모리 공간
		-자료형 : 데이터의 종류와 크기, 표현을 나타낸다 정의한다

		종류
		기본 자료형, 포인터 타입 자료형, 레퍼런스 타입 자료형, 사용자정의 자료형

		우리는 먼저 기본 자료형을 배울것이다.

		#데이터 크기
		1bit 0 과 1을 나타내는 기본 단위
		8bit = 1byte
		1024 byte = 1 kb 킬로바이트
		1024 kb = 1 mb 메가바이트
		1024 mb = 1 gb 기가바이트

		# 기본 자료형
		문자형
		형식(자료형)					데이터 크기(바이트 )
		char						1
		wchar_t						2	나중에

		정수형
		bool						1 참 또는 거짓을 나타낼때 사용한다.
		short						2
		int							4
		long						4
		long long					8

		실수형
		float						4
		double						8

		long double					8 거의 사용 안함 MSDN 에 존재는 한다.


	*/


int main()
{
	// 컨트롤 K + C 선택한 곳 주석 
	// 컨트롤 K + U 선택한 곳 주석 풀기 
	//printf(" \"Hello world! \" \n\n"); 

	////강아지 그리기 
	//printf("    / \\_\n");
	//printf("   (    @\\__\n");
	//printf("   /        O\n");
	//printf("  /   (_____/\n");
	//printf(" /_____/   U\n");

	////escape sequence
	//printf("\n 줄바꿈 \n");	// 줄 바꾸기
	//printf("Hello\tWorld\n");	// tab 
	//printf(" \" 쌍 따옴표 \"\n");	// 특수문자들 
	//printf(" \\ 슬래쉬 \n");
	//printf(" 백스페이스 ABC\bD \n"); //백스페이스 
	//printf("\n\n");

	/////////////////////////////////////////////////////////////

	// bool 
	// 1바이트 
	// 참 또는 거짓을 나타낸다. 
	// true -> 0을 제외한 모든 수
	// false -> 0 인 경우 
	// bool 값은 어떠한 값을 넣어도 0 또는 1로 저장이 된다. 
	bool b1 = true;
	b1 = 25;
	bool b2 = false;
	std::cout << "b1 : " << b1 << std::endl;
	std::cout << "b2 : " << b2 << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	// 문자형
	/*
	*	타입				주용도							크기			값의 범위
		char			문자 데이터 저장할때 사용한다.		1			-128 ~ + 127
		unsinged char	부호가 양수 바이너리 파일 처리하	1			0~ 255
	*/
	char c1 = 'A';
	std::cout << "c1 : " << c1 << std::endl;
	std::cout << "char size : " << sizeof(char) << std::endl;
	std::cout << "c1 size : " << sizeof(c1) << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	// 정수형 
	// 용도는 -> 정수값으 저장한다. 
	/*
		타입			크기			값의 범위
		short		2			-32768 ~ +32767
		unsigned	2			0 ~ 65535
	*/
	// short 
	short s1 = 101;
	unsigned short s2 = 102;

	std::cout << "short size :" << sizeof(short) << std::endl;
	std::cout << "s1 : " << s1 << std::endl;
	std::cout << "s2 : " << s2 << std::endl;

	//short 자료형의 최대 값을 받아올수 있는거 
	s2 = std::numeric_limits<unsigned short>::max();
	std::cout << "s2 : " << s2 << std::endl;

	//업데이트 내용 확인 ..
	s2 += +1;
	std::cout << "s2 + 1 : " << s2 << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;

	// int 
	// 4byte(32bit)
	// 가장 보편적으로 많이 사용되는 자료형이다. 
	// int 값 범위 -2,147,483,648 ~ 2,147,483,647
	// unsiged int 값 범위  : 0 ~ 4,294,967,295
	int i1 = 2100000000;
	unsigned int i2 = 2;

	std::cout << "int size :" << sizeof(int) << std::endl;
	std::cout << "unsigned size :" << sizeof(unsigned int) << std::endl;
	std::cout << "i1 size :" << i1 << std::endl;
	std::cout << "i2 size :" << i2 << std::endl;

	// MS 전용 확장자 자료형이있다. 표준 C++ 아니다. 
	__int16 i16 = 16;
	__int32 i32 = 32;
	__int64 i64 = 64;
	std::cout << "__int16 size :" << sizeof(__int16) << std::endl;
	std::cout << "__int32 size :" << sizeof(__int32) << std::endl;
	std::cout << "__int64 size :" << sizeof(__int64) << std::endl;

	//표준 c++ 11 
	//이 int 사용하라고 권장은 하고있어요
	//이거 사용하는분 못본거같아요 
	int16_t i16t = 2;
	int32_t i32t = 4;
	int64_t i64t = 8;

	std::cout << "int16_t size :" << sizeof(int16_t) << std::endl;
	std::cout << "int32_t size :" << sizeof(int32_t) << std::endl;
	std::cout << "int64_t size :" << sizeof(int64_t) << std::endl;


	std::cout << std::endl;
	std::cout << std::endl;

	////////////////////////
	// long
	// 4byte 윈도우 기준 

	long l1 = 101L;
	unsigned long l2 = 102L;

	std::cout << "sizeof long : " << sizeof(long) << std::endl;
	std::cout << "sizeof unsigned long : " << sizeof(unsigned long) << std::endl;
	std::cout << "sizeof l1 : " << sizeof(l1) << std::endl;
	std::cout << "sizeof l2 : " << sizeof(l2) << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;

	////////////////////////
	// long long 
	// 8byte 64bit 
	long long ll1 = 90000000000LL;
	unsigned long long ll2 = 99999999999999999LL;

	std::cout << "sizeof long long : " << sizeof(long long) << std::endl;
	std::cout << "sizeof unsigned long long : " << sizeof(unsigned long long) << std::endl;
	std::cout << "sizeof l1 : " << sizeof(ll1) << std::endl;
	std::cout << "sizeof l2 : " << sizeof(ll2) << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;
	//////////////////////////////////
	//실수형 
	//정밀도 => 부동 소수점 오차 => 실수형을 나타내는 방식은 "부동소수점 방식"을 이용하므로 끝 부분이 정확하지 않다. 오차가 생길 수 있다.
	//float
	// 4바이트 
	// 정밀도 :
	// 소수부분은 약 7자리의 정밀도를 가진다. => 소수점이 6~7자리까지는 정확하다 

	// 소수 부분만 출력해봤을때 
	float f1 = 0.123456789f;
	std::cout << "float f1 : " << f1 << std::endl;

	float f2 = 321.123456789f;
	std::cout << "float f2 : " << f2 << std::endl; //321.123
	std::printf("float printf f2 : %f \n", f2); // 321.123444
	std::cout << "float sizeof : " << sizeof(float) << std::endl; // 4

	std::cout << std::endl;
	std::cout << std::endl;
	//double
	// #include <iomanip>
	// 8바이트  
	// 정밀도 
	// 소수부분이 약 15~16자리 정밀도를 가진다. 

	//0.12345678901234567737
	double d1 = 0.1234567890123456789;
	std::cout << std::setprecision(20) << "double d1 : " << d1 << std::endl; //

	//정수부분만 나온다. 
	//9876543210987655168
	double d2 = 9876543210987654321.123456789;
	std::cout << std::setprecision(20) << "double d2 : " << d2 << std::endl; //
	//654321.12345678906422
	double d3 = 654321.1234567890123456789;
	std::cout << std::setprecision(20) << "double d3 : " << d3 << std::endl; //

	std::cout << "double sizeof : " << sizeof(double) << std::endl; // 8

	return 0;
}