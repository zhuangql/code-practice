#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
int main(){
    std::vector<int> temp;
    temp.resize(3, 6);
    std::cout << temp.size() << std::endl;
    for(const auto n : temp){
        std::cout << n << std::endl;
    }
    std::cout << sizeof(temp) << std::endl;

    //static -> const static  ?
    //static int temp_static =  111;
    //auto bbb = (const  int)temp_static;
    //const static int aaaa = static_cast<const  int>(temp_static);

    //io
    //int input = std::cin.get();
    //std::cout << "input:" << input << std::endl;

    //char r, rr;
    //std::cin.get(r).get(rr);
    //std::cout << "r:" << r << std::endl << "rr:" << rr << std::endl;

    //char num[10];
    //std::cin.get(num, 6, 'q').get();
    //std::cout << "num:" << num <<std::endl;

    //std::fstream fs;
    //fs.open("/home/ferry/develop/ferry/code/c++/std::resize/build/zhuangql.txt", std::fstream::app | std::fstream::binary);
    //fs << "中国";
    //std::cout << "is open?" << fs.is_open() << std::endl;
    //fs.close();

/*
    fstream fs;
    fs.open("/home/ferry/develop/ferry/code/c++/std::resize/build/zhuangql.txt");
    if(!fs){
        cout << "open file fail" << endl;
        return 1;
    }
    char num[10], num1[10],num2[10];
    while (fs.getline(num, 10, '\n'))
    {
        cout << "num:" << num << endl;
    }
    if(!fs) cout << "getline is end " << endl;
    cout << "file is open?" << fs.is_open() << endl;
    //fs.getline(num, 10, '\n');
    //fs.getline(num1, 10, 't');
    //cout << "num:" << num <<endl << "num1:" << num1 << endl << "num2:" << num2;
*/
    fstream fs;
    fs.open("/home/ferry/develop/ferry/code/c++/std::resize/build/zhuangql.txt");
    if(!fs.is_open()){
        cout << "open file fail" << endl;
        return 1;
    }
    string str;
    while(!fs.eof()){
        getline(fs, str, '\n');
        cout << "line:" << str << endl;
    }
    if(!fs) cout << "getline is end " << endl;
    fs.close();
    return 0;
}