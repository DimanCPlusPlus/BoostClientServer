#ifndef READWRITESOCKET
#define READWRITESOCKET

#include <boost/asio.hpp>

namespace asio = boost::asio;

using tcp=asio::ip::tcp;

class readWriteSocket
{
    public:
    static void writeSocket(tcp::socket&socket,char*data,int len)
    {
        boost::asio::write(socket,boost::asio::buffer(&len,sizeof(int)));
        int transferedBytes=0;
        while(transferedBytes!=len)
        {
            transferedBytes+=boost::asio::write(socket,boost::asio::buffer(data+transferedBytes,len));
        }
    }
    static void readSocket(tcp::socket&socket,char*data)
    {
        int len;
        boost::asio::read(socket,boost::asio::buffer(&len,sizeof(int)));
        int transferedBytes=0;
        while(transferedBytes!=len)
        {
            transferedBytes+=boost::asio::read(socket,boost::asio::buffer(data+transferedBytes,len));
        }
    }
};

#endif /* READWRITESOCKET */
