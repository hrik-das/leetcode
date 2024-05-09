#include <iostream>
#include <vector>
class Solution{
    public:
    int removeDuplicates(std::vector<int>& nums){
        if(nums.empty()){
            return 0;
        }
        int k = 1;
        for(int i=1; i<nums.size(); i++){
            if(nums[i] != nums[i - 1]){
                nums[k++] = nums[i];
            }
        }
        return k;
    }
    void run(){
        std::vector<int> nums1 = {1, 1, 2};
        int k1 = removeDuplicates(nums1);
        std::cout<<"After Removing Duplicates the size of the array is: "<<k1<<std::endl;
        std::vector<int> nums2 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
        int k2 = removeDuplicates(nums2);
        std::cout<<"After Removing Duplicates the size of the array is: "<<k2<<std::endl;
    }
};
int main(int argc, char* argv[]){
    Solution ob;
    ob.run();
    return 0;
}