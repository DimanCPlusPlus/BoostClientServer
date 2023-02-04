all: server client
server: source/server.cpp headers/readWriteSocket.hpp
	clang++ -Iheaders source/server.cpp -std=c++17 -o server -lpthread
client: source/client.cpp headers/readWriteSocket.hpp
	clang++ -Iheaders source/client.cpp -std=c++17 -o client -lpthread