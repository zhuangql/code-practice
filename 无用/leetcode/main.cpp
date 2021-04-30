#include<iostream>
#include<vector>
int main(){
    std::vector<int> nums1{1, 2};
    std::vector<int> nums2{3, 4};
    size_t length_nums1 = nums1.size();
        size_t length_nums2 = nums2.size();
        size_t length_all = length_nums1 + length_nums2;
        size_t ptr_num1 = 0;
        size_t ptr_num2 = 0;
        int first = -1;
        int second = -1;
        for(size_t i = 0; i < length_all/2 + 1; ++i){
            second = first;
            if(ptr_num1 < length_nums1 && (ptr_num2 >= length_nums2 || nums1[ptr_num1] < nums2[ptr_num2])){
                first = nums1[ptr_num1++];
            }else{
                first = nums2[ptr_num2++];
            }
        }
int x = length_all & 1;
        if((length_all & 1) == 0){
             std::cout << (first + second)/2.0 << std::endl;
            return (first + second)/2.0;
        }else{
             std::cout << first << std::endl;
            return first;
        }
       
}