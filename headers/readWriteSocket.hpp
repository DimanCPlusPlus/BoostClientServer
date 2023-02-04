#ifndef READWRITESOCKET
#define READWRITESOCKET

#include <boost/asio.hpp>
#include <string>
#include <iostream>

namespace asio = boost::asio;

using tcp=asio::ip::tcp;

class readWriteSocket
{
    public:
    static void writeSocket(tcp::socket&socket,std::string data)
    {
        int len=data.size();
        boost::asio::write(socket,boost::asio::buffer(&len,sizeof(int)));
        int transferedBytes=0;
        while(transferedBytes!=len)
        {
            transferedBytes+=boost::asio::write(socket,boost::asio::buffer(data.substr(transferedBytes),len));
        }
    }
    static std::string readSocket(tcp::socket&socket)
    {
        int len;
        boost::asio::read(socket,boost::asio::buffer(&len,sizeof(int)));
        std::string data;
        data.resize(len);
        int transferedBytes=0;
        while(transferedBytes!=len)
        {
            transferedBytes+=boost::asio::read(socket,boost::asio::buffer(data.data()+transferedBytes,len));
        }
        return data;
    }
};
#endif /* READWRITESOCKET */
