#include <iostream>
int main(){
    int a = 3;
    int& b = a;
    int& c = b;
    //引用的时候是地址传递，但是编译的时候，符号表上记录的 引用变量名所对应的地质 为引用对象的地址值
    std::cout << "a de dizhi:" << &a << "\n" << "b de dizhi:" << b << "\n" << "b de dizhi:" << &b << "\n" << "c de zhi:" << c << "\n" << "c de dizhi" << &c << "\n";
}

