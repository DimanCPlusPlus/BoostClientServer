#include <boost/asio.hpp>
#include <iostream>
#include "readWriteSocket.hpp"
#include <string>

namespace asio = boost::asio;

using tcp=asio::ip::tcp;

int main()
{
    std::string data{"Hello"};
    asio::io_context ioc;
    tcp::acceptor acceptor(ioc,tcp::endpoint(tcp::v4(),13));
    for(;;)
    {
        tcp::socket socket(ioc);
        acceptor.accept(socket);
        std::cout<<"Good connect"<<std::endl;
        readWriteSocket::writeSocket(socket, data.data(), data.size());
    }
    return 0;
}