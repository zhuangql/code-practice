#include <iostream>
#include <vector>
int main(){
    std::vector<int> temp;
    temp.resize(3, 6);
    std::cout << temp.size() << std::endl;
    for(const auto n : temp){
        std::cout << n << std::endl;
    }
    std::cout << sizeof(temp) << std::endl;
    return 0;
}