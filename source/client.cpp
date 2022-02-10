#include <boost/asio.hpp>
#include <iostream>
#include <string>
#include "readWriteSocket.hpp"

namespace asio = boost::asio;

using tcp=asio::ip::tcp;

int main()
{
    std::string data;
    data.resize(256);
    asio::io_context ioc;
    tcp::resolver resolver(ioc);
    tcp::socket socket(ioc);
    tcp::resolver::results_type endpoint=resolver.resolve("127.0.0.1","13");
    boost::asio::connect(socket,endpoint);
    readWriteSocket::readSocket(socket, data.data());
    std::cout<<data<<std::endl;
    return 0;
}