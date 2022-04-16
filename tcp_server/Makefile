.PHONY: all clean
CC = g++
all: server client
server: server_multi_thread.cpp
	${CC} -std=c++11 server_multi_thread.cpp -o server -pthread
client: single_client.cpp
	${CC} -std=c++11 single_client.cpp -o client -pthread
clean:
	rm server client
