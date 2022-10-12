#include <WinSock2.h>
#include <iostream>
#include <thread>

#define MSG "Hello World\0"
#define PACKET_SIZE 255
int main()
{
	WSADATA					    ws2_data; //소켓 초기화 정보를 저장하기 위한 구조체
	WSAStartup(MAKEWORD(2, 2), &ws2_data);
	
	SOCKET	    srv_socket = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP), cli_socket; //소켓 생성
	sockaddr_in srv_address, cli_address;

	srv_address.sin_addr.s_addr = ::inet_addr("127.0.0.1"); //루프벡
	srv_address.sin_port		= ::htons(7000); //사용할 포트 7000
	srv_address.sin_family	    =   AF_INET;

	std::cout << ::bind  (srv_socket, (const sockaddr*)&srv_address, sizeof(sockaddr_in)) << std::endl;
					// 소켓에 위에 설정한 주소 정보를 묶어주고, 소켓을 접속대기상태로 만듬
	std::cout << ::listen(srv_socket, 20) << std::endl; 
					//소켓을 접속대기상태로 만듬 ,최대 20개까지

	int cli_address_size = sizeof(sockaddr_in);
	cli_socket = ::accept(srv_socket, (sockaddr*)&cli_address, &cli_address_size); 
					//접속 요청 수락(소켓,클라이언트측 구조체 주소,구조체의 크기를 저장해둔 변수의 주소)
			     ::send(cli_socket, MSG, ::strlen(MSG) + 1, 0);
				 

	

	/*char cBuffer[PACKET_SIZE] = {0x00,};
	recv(cli_socket, cBuffer, PACKET_SIZE, 0);
	printf("RecV Msg : %s\n", cBuffer);
			
	char cMsg[] = "Server Send";
	send(cli_socket, cMsg, strlen(cMsg), 0);
	*/
	
	while (1) {}
}