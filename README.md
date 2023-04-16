# OnlineChat
소켓 초기 설계

# 1차

## Lobby
메인 서버 TCP
단일 스레드 : User Login, Room 검색, Room 생성에 대한 응답 및 반환

## GameRoom
게임 서버 TCP : 마피아 게임으로 손실에 불리하며 게임 플레이상 최소단위가 초단위여도 상관없기 때문에 속도가 중요하지 않음   
단일 스레드 : 단순한 게임형식이기 때문에 게임의 진행은 대부분 서버내에서 진행, 시간과 룰에 의해 클라이언트에게 응답 요청, 클라이언트는 의사, 출력 위주   

채팅 서버 TCP : 손실방지를 위한 TCP, Echo서버, User가 포함된 Room내 모든 User에게 발송   
멀티 스레드 : 소켓 1당 Recv, Send 스레드(2) 부여, Game Room당 Thread Pool을 이용한 발송   

>추가 예정 : UDP사용 예제를 위한 음성 서버

현재 구현 단계
- User Ip와 닉네임을 통한 해시 연산을 통해 고유 식별자 키 생성 및 HashMap에 User정보(소켓포함) 저장
- MFC 프레임 워크를 통한 GUI 구현
- 메인 서버 - Login, Room 검색 및 생성, 게임서버 인도
- 게임 서버 - 방 최초 생성 및 User 입장

## 프로토콜
헤더와 몸통으로 구분되며 헤더의 형태
ProtocolHeader (struct)
byte code; word Type; word PayloadSize;

몸통(data)는 각 서버별 프로토콜에 따라 구현
구조체며 각 소켓통신에 데이터 불필요를 줄이기 위한 직렬화와 역직렬화가 있고 때문에 서버와 클라이언트가 Protocol파일을 동일하게 사용

## 클래스 구조
부모 - TCP_Server, UDP_Server - 기본 소켓 통신을 위한 윈속 설정 클래스 | virsual addClient (to Thread), recv
자식 - MainServer, GameServer, ChatServer | 요청에 행동 함수
