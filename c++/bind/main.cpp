#include <iostream>
#include <functional>
using namespace std;
using namespace std::placeholders;
//1、bind(&basic::plus, basic的指针或对象， _1, _2,  _3);   this指针放在第一个参数
//2、上面的 this/对象  参数，是拷贝到 bind生成的对象中；
//3、关于bind返回的对象赋 给  function<>类型；function类型要与bind的参数一致，包括this参数；
class basic
{
    public:
    basic() : var(6) {cout << "gouzao:" << "var=" << var <<endl;}
    ~basic(){}

    void plus(int a){ cout << "plus:" << a  << endl;
                                                            //var += 1;
                                                            cout << "var=:" << var << endl;
                                                            }

    int data(){return var;}
    private:
    int var;
};


int main(){
    //function<void(int, int, int)> f = bind(&basic::plus, _1, _2, _3, _4);
    //auto fobj  = bind(&basic::plus, _1, _2);
    basic obj;
    int temp =111;
    //auto fobj  = bind(&basic::plus, ref(obj), _1);
    //function<void(int)> fobj = bind(&basic::plus, ref(obj), _1);
    function<void( basic*const, const int&)> fobj = bind(&basic::plus, _1, _2);
    cout << "putPut  : fuzhi: zhiqian" << endl;
    cout << "var=" << obj.data() << endl;
    cout << "putPut  : fuzhi:" << endl;
    fobj(&obj, temp);
    //fobj( 111);
    cout << "putPut  : fuzhi: jieshu" << endl;
    cout << "var=" << obj.data() << endl;
    //system()
    return 0;
}