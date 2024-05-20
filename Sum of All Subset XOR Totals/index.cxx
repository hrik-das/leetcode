# include<iostream>
# include<vector>
class Solution{
    // Helper function to recursively calculate XOR totals of subsets
    void subsetXORSumHelper(const std::vector<int>& nums, int index, int currentXOR, int& result){
        if(index == nums.size()){
            result += currentXOR;    // Add XOR total of the subset to the result
            return;
        }
        // Include nums[index] in the subset
        subsetXORSumHelper(nums, index + 1, currentXOR ^ nums[index], result);
        // Exclude nums[index] from the subset
        subsetXORSumHelper(nums, index + 1, currentXOR, result);
    }
    public:
    int subsetXORSum(const std::vector<int>& nums){
        int result = 0;
        subsetXORSumHelper(nums, 0, 0, result);
        return result;
    }
};
int main(int argc, const char** argv){
    Solution ob;
    std::vector<std::vector<int>> testCases = {{1, 3}, {5, 1, 6}, {3, 4, 5, 6, 7, 8}};
    for(const auto& nums:testCases){
        std::cout<<"Input: ";
        for(int num:nums){
            std::cout<<num<<" ";
        }
        std::cout<<std::endl;
        int result = ob.subsetXORSum(nums);
        std::cout<<"Output: "<<result<<std::endl;
        std::cout<<std::endl;
    }
    return 0;
}