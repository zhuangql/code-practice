//g++ client.cpp -o client   -lpthread  -g
#include <iostream>
#include <boost/asio.hpp>
using namespace boost::asio;

int main(int argc, char* argv[]){
    io_service iosev;
    ip::tcp::socket socket(iosev);
    ip::tcp::endpoint ep(ip::address_v4::from_string("127.0.0.1"), 2000);
    boost::system::error_code ec;
    socket.connect(ep, ec);
    if(ec){
        std::cout << "==========connect ec :" << boost::system::system_error(ec).what() <<"\n";
        return -1;
    }

    char buf[100];
    size_t len = socket.read_some(buffer(buf), ec);//异步读取缓冲区数据，读完前或遇到错误前阻塞；若服务器socket close，则client取消阻塞，返回end of file返回；
    std::cout.write(buf, len) << "read's content ========" << boost::system::system_error(ec).what() <<"\n";


}