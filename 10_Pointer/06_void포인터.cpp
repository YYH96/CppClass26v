#include <iostream>

/*
    void* 포인터

    void*는 자료형을 모르는 주소를 저장할 수 있는 포인터다.
    어떤 자료형의 주소인지 정보가 없으므로 그대로는 역참조하거나 포인터 연산을 할 수 없다.
    사용할 때는 원래 자료형 포인터로 명시적으로 변환해야 한다.

    C++에서는 가능한 한 구체적인 자료형 포인터를 사용하는 편이 안전하다.
*/

int main()
{
    int score = 100;
    double ratio = 0.75;

    void* pData = &score; // int의 주소도 void*에 저장할 수 있다.
    int* pScore = static_cast<int*>(pData);
    std::cout << "score: " << *pScore << '\n';

    pData = &ratio; // double의 주소도 같은 void* 변수에 저장할 수 있다.
    double* pRatio = static_cast<double*>(pData);
    std::cout << "ratio: " << *pRatio << '\n';

    // *pData;      // 오류: void*는 대상 자료형을 모르므로 역참조할 수 없다.
    // pData + 1;   // 오류: void*는 한 칸의 크기를 알 수 없어 포인터 연산을 할 수 없다.

    return 0;
}

/*
    ===== 게임 프로그래밍에서 void*를 만날 수 있는 곳 =====

    1. 네트워크 패킷 보내기

    네트워크 전송 함수는 "어떤 자료형인지"보다 "몇 바이트를 보낼지"가 중요할 때가 있다.
    그래서 여러 형태의 패킷을 하나의 전송 함수로 처리하기 위해 const void*를 받을 수 있다.

    struct PacketHeader
    {
        unsigned short size;
        unsigned short id;
    };

    void SendPacket(const void* packetData, int byteSize);

    PacketHeader header = { sizeof(PacketHeader), 1001 };
    SendPacket(&header, sizeof(header));

    const void*의 const는 전송 함수가 원본 패킷 내용을 바꾸지 않겠다는 뜻이다.
    실제 수신 처리에서는 패킷 크기, 패킷 ID, 자료형을 먼저 확인해야 한다.
    받은 바이트를 확인하지 않고 특정 구조체 포인터로 변환해 읽으면 잘못된 패킷 때문에 오류가 날 수 있다.

    2. 렌더링 데이터 업로드

    렌더링 라이브러리나 그래픽 API는 정점 데이터처럼 여러 형태의 데이터를 다룬다.
    공통 함수가 "데이터 시작 주소 + 전체 바이트 수"를 받으면 int 배열, Vertex 배열 등을 모두 전달할 수 있다.

    struct Vertex
    {
        float x;
        float y;
        float z;
    };

    void UploadVertexData(const void* vertexData, int byteSize);

    Vertex vertices[3] = { ... };
    UploadVertexData(vertices, sizeof(vertices));

    실제 API에서는 정점 하나의 크기, 위치/색상 같은 데이터의 배치 정보도 함께 전달한다.
    void*에는 자료형 정보가 없으므로, 호출하는 쪽과 받는 쪽이 같은 데이터 형식을 약속해야 한다.

    3. 콜백의 사용자 데이터(User Data)

    C 스타일 라이브러리의 콜백은 필요한 게임 객체를 함께 전달하기 위해 void* userData를 쓰기도 한다.

    void OnButtonClicked(void* userData);

    Player* pPlayer = ...;
    OnButtonClicked(pPlayer);

    콜백 안에서는 원래 타입을 정확히 알고 있을 때만 Player*로 변환해 사용한다.

    !기억 - void* 자체에는 자료형, 데이터 크기, 소유권, 수명 정보가 없다.
             따라서 원시 데이터를 다룰 때는 반드시 "무슨 데이터인지, 몇 바이트인지,
             아직 유효한 주소인지"를 함께 관리해야 한다.

    C++에서는 가능한 한 int*, Vertex*, Player*처럼 구체적인 포인터 타입을 우선 사용한다.
    void*는 여러 형식의 원시 데이터를 하나의 저수준 인터페이스로 처리해야 할 때 사용한다.
*/
