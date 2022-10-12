#include <WinSock2.h>
#include <xmmintrin.h>

#include <iostream>


int main()
{
	WSADATA					    ws2_data; //소켓 초기화 정보를 저장하기 위한 구조체
	WSAStartup(MAKEWORD(2, 2), &ws2_data);// 윈속을 초기화하고 초기화정보를 wsaData에 담는다.

	SOCKET	    cli_socket = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); 
	// 소켓생성 ,(AF_INET : 주소 체계 IPv4 , SOCK_STREAM :TCP/IP사용)
	sockaddr_in cli_address;

	cli_address.sin_addr.s_addr = ::inet_addr("127.0.0.1"); // 윈도우 안에서 루프
	cli_address.sin_port		= ::htons(7000); //7000포트 사용
	cli_address.sin_family		= AF_INET;

	::connect(cli_socket, (const sockaddr*)&cli_address, sizeof(sockaddr_in));

	
	while (1) { _mm_pause(); }// 

	
}
/*char cMsg[] = "Client Send\0";
send(cli_socket, cMsg, strlen(cMsg), 0);

char cBuffer[PACKET_SIZE] = { 0x00, };
recv(cli_socket, cBuffer, PACKET_SIZE, 0);

printf("RecV Msg : %s\n", cBuffer);
*/