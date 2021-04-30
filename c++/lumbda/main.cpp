#include <iostream>
using namespace std;
//lumbda表达式  中 捕获this：
//1、值捕获，[this]{this->}
//2、引用，[&]{this->}
class Foo
{
    public:
        Foo(int res = 5) : result(res) { cout <<"construct Foo " << "this->result:" << this->result << endl << "this:" << this << endl; }
        ~Foo(){cout << "no construct Foo" << endl;}
        int thePlus(){return result+1;}
        void theResult(){
            int aaa =111;
            auto lumObj = [&] () ->int {
                                                        cout << this->result <<"===" << result << "===" << this->thePlus() << endl;
                                                        cout << "capture top:" << aaa << endl << "capture down:"  << endl;
                                                        return this->result;};
            int bbb = 222;
            lumObj();
            return;
            }

 //   private:
        int result;

//数据成员指针
        public:
        static const string Foo::* data(){return &Foo::str;}
        private:
        string str{"aini"};
};

class FooParent : public Foo
{
    public:
    FooParent(): Foo(5){cout << "construct FooParent" << endl;}
    ~FooParent(){cout << "no construct FooParent" << endl;}
};

int main(){
    //lumbda函数
    //Foo foo;
    //foo.theResult();
    //FooParent foop;
    //cerr << "cerr:" << foo.result << endl;


    //数据成员指针
    Foo foo, *pfoo = &foo;
    //const string Foo::* pdata;
    //pdata = &Foo::str;//str是私有成员，编译错误   指针是1
    //auto str = foo.*pdata;
    //string pstr = pfoo->*pdata;
    //cout << "====shujuchengyuanzhizhen:" << str << endl << "===pdata:" << pstr <<endl;
    const string Foo::* pdata = Foo::data();
    cout << "pdata:" << pdata <<endl;

    return 0;
}