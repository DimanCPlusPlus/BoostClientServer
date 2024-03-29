#include <boost/asio.hpp>
#include <iostream>
#include "readWriteSocket.hpp"
#include <string>

namespace asio = boost::asio;

using tcp=asio::ip::tcp;

int main()
{
    asio::io_context ioc;
    tcp::acceptor acceptor(ioc,tcp::endpoint(tcp::v4(),13));
    for(;;)
    {
        tcp::socket socket(ioc);
        acceptor.accept(socket);
        tcp::endpoint remote_ep=socket.remote_endpoint();
        asio::ip::address remote_ad = remote_ep.address();
        std::string address=remote_ad.to_string();
        std::cout<<"Good connect\nAddress connect - "<<address<<std::endl;
        for(;;){
            std::string data;
            std::cin>>data;
            readWriteSocket::writeSocket(socket, data);
        }
    }
    return 0;
}