//g++ server.cpp -o server   -lpthread  -g
#include <iostream>
#include <boost/asio.hpp>
using namespace boost::asio;
int main(int argc, char* argv[]){

    io_service iosev;
    ip::tcp::acceptor acceptor(iosev, ip::tcp::endpoint(ip::tcp::v4(), 2000));//listen
    int a;
    int b = a + 1;
    while(true){
        ip::tcp::socket socket(iosev);//从listen队列取出 分配一个socket
        //等待链接
        acceptor.accept(socket);//从listen队列取连接，分配给socket对象；listen队列为空则阻塞；
        std::cout << socket.remote_endpoint().address() << "\n";


        // 向客户端发送hello world!
        boost::system::error_code ec;
        socket.write_some(buffer("hello world"), ec);//同步发送，发送成功前是阻塞的，发出去就算成功；若客户端在服务器发送前断开连接，服务器照常发送；
        if(ec){
            std::cout << boost::system::system_error(ec).what() << "write ======= ec" << "\n";
            break;
        }
        std::cout << boost::system::system_error(ec).what() << "write ======= ec" << "\n";
    }

    return 0;
}
