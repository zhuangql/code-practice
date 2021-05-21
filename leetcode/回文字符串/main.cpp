#include<iostream>
#include<vector>
//#include<solution.h>
using namespace std;
class solution{
    private:
        bool valid( string data, size_t left, size_t right ){
            while(left < right){
                if(data[left] != data[right]){
                    return false;
                }
                ++left;
                --right;
            }   
            return true;
        }

    public:
       string longestString(string data){

           size_t length = data.size();
           if(length < 2){
               return data;
           }
            string result = data.substr(0, 1);
            size_t maxLength = 1;
            for(size_t first = 0; first < length - 1; ++first){
                for(size_t second = first + 1; second < length; ++second){
                    if( second - first + 1 > maxLength && valid(data, first, second)){
                        maxLength = second - first + 1;
                        result = data.substr(first, maxLength);
                    }
                }
            }
            return result;
       }
};

int main(){
    solution m_solution;
    string str;
    std::cin >> str;
    string result = m_solution.longestString(str);
    std::cout << result << std::endl;
    return 0;
}

