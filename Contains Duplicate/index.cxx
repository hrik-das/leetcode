# include<iostream>
# include<vector>
# include<unordered_set>
class Solution{
    public:
    bool containsDuplicate(std::vector<int>& nums){
        std::unordered_set<int> numbers;
        for(const int& num : nums){
            if(numbers.find(num) != numbers.end()) return true;
            else numbers.insert(num);
        }
        return false;
    }
};
int main(int argc, const char** argv){
    Solution ob;
    std::vector<int> nums1 = {1, 2, 3, 1};
    std::cout<<"Test Case 1: "<<(ob.containsDuplicate(nums1) ? "true" : "false")<<std::endl;
    std::vector<int> nums2 = {1, 2, 3, 4};
    std::cout<<"Test Case 2: "<<(ob.containsDuplicate(nums2) ? "true" : "false")<<std::endl;
    std::vector<int> nums3 = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    std::cout<<"Test Case 3: "<<(ob.containsDuplicate(nums3) ? "true" : "false")<<std::endl;
    return 0;
}