all: server client
server: source/server.cpp
	clang++ -I/home/dima/CPP/ConsoleApp/headers/ source/server.cpp -std=c++17 -o server -lpthread
client: source/client.cpp
	clang++ -I/home/dima/CPP/ConsoleApp/headers/ source/client.cpp -std=c++17 -o client -lpthread