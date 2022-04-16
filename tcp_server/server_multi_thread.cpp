#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <iostream>
using namespace std;

pthread_mutex_t mutex;
void* server_routine(void* param) {
   int* fd = (int*)param;
   char buffer[256];
   pthread_t id = pthread_self();
   while(true) {
       bzero(buffer, 256);
       int count = read(*fd, buffer, 255);
       if(strcmp(buffer, "quit") == 0) {
          cout<<"quit the thread"<<endl;
          break;
       }
       pthread_mutex_lock(&mutex);
       cout<<id<<":get the message:"<<buffer<<endl;
       pthread_mutex_unlock(&mutex);
   }
   
   close(*fd);
}

int main() {
    
    int server_socket;
    
    struct sockaddr_in cli_addr;
    
    mutex = PTHREAD_MUTEX_INITIALIZER;
    pthread_mutex_init(&mutex, NULL);
    server_socket = socket(PF_INET, SOCK_STREAM, 0);
    if(server_socket < 0) {
       cout<<"socket error"<<endl;
    }
    struct sockaddr_in serverAddr;
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = PF_INET;
    serverAddr.sin_port = htons(5000);
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    int ret = bind(server_socket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
    if(ret < 0) {
    	cout<<"fail to bind"<<endl;
    	exit(1);
    }
    ret = listen(server_socket, 8);
    if(ret < 0) {
      cout<<"listen failed"<<endl;
      exit(1);
    }
    socklen_t clilen = sizeof(cli_addr);
    while(true) {
       cout<<"listen to a new connection"<<endl;
       int newclient = accept(server_socket, (struct sockaddr *)&cli_addr, &clilen);
       cout<<"get a new connection"<<endl;
       pthread_t tid;
       pthread_create(&tid, NULL, server_routine, (void*)&newclient);
    }
    close(server_socket);
	 return 0;
}