#include <iostream>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
using namespace std;

int main() {

	int sockfd;
	struct sockaddr_in serv_addr;
	struct hostent* server;

	int port = 5000;
	sockfd = socket(PF_INET, SOCK_STREAM, 0);
	if(sockfd < 0) {
		cout<<"error open socket"<<endl;
		exit(1);
	}
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	serv_addr.sin_port = htons(port);

	int ret = connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)); 
	if(ret < 0){
		cout<<"error connecting"<<endl;
		cout<<ret<<endl;
		exit(1);
	}
    while(true) {
    	cout<<"please enter message:"<<endl;
	    char buffer[256];
	    memset(buffer, 0, 256);
	    cin>>buffer;
	    write(sockfd, buffer, strlen(buffer));
    }
	
	close(sockfd);

}