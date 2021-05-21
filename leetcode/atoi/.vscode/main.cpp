#include <string>
#include<unordered_map>
#include<vector>
#include<limits.h>
#include<iostream>
using namespace std;
class fsm
{
    public:
        int calSpeciesOfChar(char const& c){
        if(isspace(c)) return 0;
        if(c == '+' || c == '-') return 1;
        if(isdigit(c)) return 2;
        return 3;
    }


    void dealChar(char const& c){
        state = table[state][calSpeciesOfChar(c)];//根据下一个状态判断当前的字符是什么
       // if(state == "start") //do nothing
        if(state == "signed"){ //c 是正负号
            flag = (c == '+')? 1: -1;
        }
        if(state == "in_number"){//c 是数字
            ans = ans*10 + c - '0';
            ans = (flag == 1) ? min(ans, static_cast<long long>(INT_MAX)) : min(ans, -static_cast<long long>(INT_MIN));
        }
      //  if(state == "end")//do nothing
    }


    int atoi(string const& s){
        for(char  const& c : s){
            dealChar(c);
        }
        return flag*ans;
    }




    private:
    string state{"start"};
    int flag{1};
    long long ans{0};
    unordered_map<string, vector<string>> table{
        {"start", {"start", "signed", "in_number", "end"}},
        {"signed", {"end", "end", "in_number", "end"}},
        {"in_number", {"end", "end", "in_number", "end"}},
        {"end", {"end", "end", "end", "end"}}
    };
};


int main(){
    fsm fsmObj;
    //fsmObj.dealChar('c');
    std::cout << fsmObj.atoi("42") << std::endl;
        return fsmObj.atoi("42");
}