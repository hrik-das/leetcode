# include<iostream>
# include<vector>
# include<algorithm>
#include <cstdint>
class Solution{
    public:
    std::vector<std::vector<int>> threeSum(const std::vector<int>& nums){
        std::vector<std::vector<int>> result;
        std::sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size() - 2; i++){
            if(i == 0 || (i > 0 && nums[i] != nums[i - 1])){
                int left = i + 1;
                int right = nums.size() - 1;
                int target = -nums[i];
                while(left < right){
                    if(nums[left] + nums[right] == target){
                        result.push_back(std::vector<int>{nums[i], nums[left], nums[right]});
                        left++;
                        right--;
                        while(left < right && nums[left] == nums[left + 1]) left++;
                        while(left < right && nums[right] == nums[right + 1]) right--;
                    }else if(nums[left] + nums[right] < target) left++;
                    else right--;
                }
            }
        }
        return result;
    }
    void printMatrix(const std::vector<std::vector<int>>& matrix){
        std::cout<<"[";
        for(const auto& row : matrix){
            std::cout<<"[";
            for(size_t i=0; i<row.size(); i++){
                std::cout<<row[i];
                if(i != row.size() - 1) std::cout<<", ";
            }
            std::cout<<"]";
        }
        std::cout<<"]"<<std::endl;
    }
};
int main(int argc, const char** argv){
    Solution ob;
    std::vector<int> nums1 = {-1, 0, 1, 2, -1, -4};
    std::vector<std::vector<int>> result1 = ob.threeSum(nums1);
    std::cout << "Test Case 1: ";
    ob.printMatrix(result1);
    return EXIT_SUCCESS;
}