# include<iostream>
# include<vector>
class Solution{
    public:
    std::vector<int> twoSum(std::vector<int>& nums, int target){
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                if(nums[i] + nums[j] == target){
                    return {i, j};
                }
            }
        }
        return {};    // If no solution is found
    }
};
int main(int argc, char *argv[]){
    Solution ob;
    std::vector<int> array = {2, 7, 11, 15};
    int target = 17;
    std::vector<int> result = ob.twoSum(array, target);
    (!result.empty()) ? std::cout<<"The Two Indices are: "<<result[0]<<" and "<<result[1]<<std::endl : std::cout<<"No Match Found!!!"<<std::endl;
    return 0;
}