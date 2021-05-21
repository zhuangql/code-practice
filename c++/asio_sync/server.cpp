//g++ server.cpp -o server   -lpthread  -g
#include <iostream>
#include <boost/asio.hpp>
using namespace boost::asio;
int main(int argc, char* argv[]){
    io_service iosev;
    //创建一个socket作为接收连接，listen
    //没有ip的endpoint()一般作为接受方
    ip::tcp::acceptor acceptor(iosev, ip::tcp::endpoint(ip::tcp::v4(), 2000));
    int a;
    int b = a + 1;
    while(true){
        //从listen队列取出 分配一个socket；socket析构中，会close socket断开连接；
        ip::tcp::socket socket(iosev);
        //等待链接
        //从listen队列取连接，分配给socket对象；listen队列为空则阻塞；
        acceptor.accept(socket);
        std::cout << socket.remote_endpoint().address() << "\n";
        // 向客户端发送hello world!
        boost::system::error_code ec;
        //同步发送，发送成功前是阻塞的，发出去就算成功；
        //若客户端在服务器发送前断开连接，服务器照常发送；
        socket.write_some(buffer("hello world"), ec);
        if(ec){
            std::cout << boost::system::system_error(ec).what() << "write ======= ec" << "\n";
            break;
        }
        std::cout << boost::system::system_error(ec).what() << "write ======= ec" << "\n";
    }
    return 0;
}
