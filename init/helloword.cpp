#include<iostream>
//#include<linshi.h>
#include<vector>
using namespace std;
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);
int main()
{
    cout << "hello world" << endl;
    vector<int> a{1, 2}, b{3};
    findMedianSortedArrays(a, b);
    return 0;
}


double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        size_t length1 = nums1.size();
        size_t length2 = nums2.size();

        if(length1 == 0){
            if(length2%2 == 0){//oushu
                return (nums2[length2/2-1] + nums2[length2/2])/2.0;
            }else{//jishu
                return nums2[length2/2];
            }
        }

        if(length2 == 0){
            if(length1%2 == 0){//oushu
                return (nums1[length1/2 - 1] + nums1[length1/2])/2.0;
            }else{
                return nums1[length1/2];
            }
        }

        size_t p1 = 0;
        size_t p2 = 0;
        size_t pNew = 0;
        std::vector<int> numNew;
        for( ;pNew < length1 + length2; ){
            if(p1 == length1){
                while(p2 < length2){
                    numNew.push_back(nums2[p2++]);
                    ++pNew;
                }
                //break;
            }
            if(p2 == length2){
                while(p1 < length1){
                    numNew.push_back(nums1[p1++]);
                    ++pNew;
                }
                //break;
            }

            if(nums1[p1] < nums2[p2]){
                numNew.push_back(nums1[p1++]);
                ++pNew;
            }else{
                numNew.push_back(nums2[p2++]);
                ++pNew;
            }
        }

        if(pNew%2 == 0){
            return (numNew[pNew/2 - 1] + numNew[pNew/2])/2.0;
        }else{
            return numNew[pNew/2];
        }
    }