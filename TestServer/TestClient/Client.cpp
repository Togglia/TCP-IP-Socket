#include <WinSock2.h>
#include <xmmintrin.h>

#include <iostream>


int main()
{
	WSADATA					    ws2_data; //���� �ʱ�ȭ ������ �����ϱ� ���� ����ü
	WSAStartup(MAKEWORD(2, 2), &ws2_data);// ������ �ʱ�ȭ�ϰ� �ʱ�ȭ������ wsaData�� ��´�.

	SOCKET	    cli_socket = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); 
	// ���ϻ��� ,(AF_INET : �ּ� ü�� IPv4 , SOCK_STREAM :TCP/IP���)
	sockaddr_in cli_address;

	cli_address.sin_addr.s_addr = ::inet_addr("127.0.0.1"); // ������ �ȿ��� ����
	cli_address.sin_port		= ::htons(7000); //7000��Ʈ ���
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