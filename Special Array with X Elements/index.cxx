# include<iostream>
# include<vector>
# include<algorithm>
# include<functional>
class Solution{
    public:
    int specialArray(std::vector<int>& nums){
        // int n = nums.size();
        // for(int x=0; x<=n; ++x){
        //     int count = std::count_if(nums.begin(), nums.end(), [&x](int num){
        //         return num >= x;
        //     });
        //     if(count == x) return x;
        // }
        // return -1;
        std::sort(nums.begin(), nums.end(), std::greater<int>());
        for(int x=1; x<=nums.size(); ++x){
            if(nums[x - 1] >= x && (x == nums.size() || nums[x] < x)){
                return x;
            }
        }
        return -1;
    }
};
int main(int argc, const char** argv){
    Solution ob;
    std::vector<std::vector<int>> testCases = {{3, 5},{0, 0},{0, 4, 3, 0, 4},{1, 2, 2, 2, 2, 2, 2},{1, 2, 2, 2, 3, 4}};
    std::vector<int> expectedResults = {2, -1, 3, -1, 3};
    for(size_t i=0; i<testCases.size(); ++i){
        int result = ob.specialArray(testCases[i]);
        std::cout<<"Input: ";
        for(int num:testCases[i]){
            std::cout<<num<<" ";
        }
        std::cout<<"\nOutput: "<<result<<"\n";
    }
    return 0;
}