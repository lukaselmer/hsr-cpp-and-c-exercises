#include <arpa/inet.h>
#include <iostream>
#include <cerrno>
#include <cstring>

using namespace std;

int main(int argc,char**argv){
	int sockfd=socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	struct sockaddr_in sa; // C++ initialisiert mit 0
	sa.sin_family = AF_INET;
	sa.sin_port = htons(80); // HTTP
	char http_command[] = "GET / HTTP/1.1\r\nhost:www.hsr.ch\r\nconnection:close\r\n\r\n";
	if (	sockfd>=0 &&
			inet_pton(AF_INET, "152.96.37.60", &sa.sin_addr) &&
			! connect(sockfd, (const sockaddr*)&sa, sizeof(sa))){
		cout << "connected to www.hsr.ch" << endl;
		write(sockfd, http_command , strlen(http_command));
		char c;
		while(read(sockfd,&c,1)>0){
			cout << c;
		}
		cout << endl;
	}
	else{
		cerr << "connect failed with errno="<<errno<<endl;
	}
	close(sockfd);
}
