#include <WinSock2.h>
#include <iostream>
#include <thread>

#define MSG "Hello World\0"
#define PACKET_SIZE 255
int main()
{
	WSADATA					    ws2_data; //���� �ʱ�ȭ ������ �����ϱ� ���� ����ü
	WSAStartup(MAKEWORD(2, 2), &ws2_data);
	
	SOCKET	    srv_socket = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP), cli_socket; //���� ����
	sockaddr_in srv_address, cli_address;

	srv_address.sin_addr.s_addr = ::inet_addr("127.0.0.1"); //������
	srv_address.sin_port		= ::htons(7000); //����� ��Ʈ 7000
	srv_address.sin_family	    =   AF_INET;

	std::cout << ::bind  (srv_socket, (const sockaddr*)&srv_address, sizeof(sockaddr_in)) << std::endl;
					// ���Ͽ� ���� ������ �ּ� ������ �����ְ�, ������ ���Ӵ����·� ����
	std::cout << ::listen(srv_socket, 20) << std::endl; 
					//������ ���Ӵ����·� ���� ,�ִ� 20������

	int cli_address_size = sizeof(sockaddr_in);
	cli_socket = ::accept(srv_socket, (sockaddr*)&cli_address, &cli_address_size); 
					//���� ��û ����(����,Ŭ���̾�Ʈ�� ����ü �ּ�,����ü�� ũ�⸦ �����ص� ������ �ּ�)
			     ::send(cli_socket, MSG, ::strlen(MSG) + 1, 0);
				 

	

	/*char cBuffer[PACKET_SIZE] = {0x00,};
	recv(cli_socket, cBuffer, PACKET_SIZE, 0);
	printf("RecV Msg : %s\n", cBuffer);
			
	char cMsg[] = "Server Send";
	send(cli_socket, cMsg, strlen(cMsg), 0);
	*/
	
	while (1) {}
}