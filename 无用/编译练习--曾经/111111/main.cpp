#include "sub/student.h"  //Student
#include "boost/version.hpp"
#include <boost/asio.hpp>
int main() {
    Student *pStu = new Student;
    pStu->name = "小明";
    pStu->age = 15;
    pStu->score = 92.5;
    //pStu->say();
    delete pStu;  //删除对象

    Student Stu;
    Stu.leineilian();
    //std::cout << "boost version" << boost::BOOST_VERSION <<std::endl;
    return 0;
}