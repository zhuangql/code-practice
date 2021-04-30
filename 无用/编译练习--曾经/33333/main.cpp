#include "student.h"  //Student
int main() {
    Student *pStu = new Student;
    pStu->name = "小明";
    pStu->age = 15;
    pStu->score = 92.5;
    //pStu->say();
    delete pStu;  //删除对象

    Student Stu;
    Stu.leineilian();
    return 0;
}