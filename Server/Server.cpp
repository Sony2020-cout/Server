// Server.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <iostream>
#pragma comment(lib, "ws2_32.lib")
#include <WinSock2.h>
#pragma warning(disable: 4996)
using namespace std;

int main() {

	WSAData wsaData;
	WORD DLLVersion = MAKEWORD(2, 1);//запрашиваемая версия библиотеки winsock
	if (WSAStartup(DLLVersion, &wsaData) != 0){
		cout << "Error" << endl;
		exit(1);
	}

	SOCKADDR_IN addr;
	int sizeOfAddr = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(1111);
	addr.sin_family = AF_INET;

	SOCKET sListen = socket(AF_INET, SOCK_STREAM, NULL);
	bind(sListen, (SOCKADDR*)&addr, sizeof(addr));
	listen(sListen, SOMAXCONN);

	SOCKET newConnection;
	newConnection = accept(sListen, (SOCKADDR*)&addr, &sizeOfAddr);

	if (newConnection == 0) {
		cout << "Error #2\n";
	}
	else {
		cout << "Client connected!\n";
	}

	system("pause");
	return 0;
}


