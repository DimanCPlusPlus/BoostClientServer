all: server client
server: source/server.cpp
	clang++ -Iheaders source/server.cpp -std=c++17 -o server -lpthread
client: source/client.cpp
	clang++ -Iheaders source/client.cpp -std=c++17 -o client -lpthread