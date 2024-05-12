# include<iostream>
# include<vector>
class Solution{
    public:
    int singleNumber(std::vector<int>& nums){
        int uniqueValue = 0;
        for(int num : nums)
            uniqueValue ^= num;
        return uniqueValue;
    }
};
int main(int argc, char *argv[]){
    Solution ob;
    std::vector<int> array = {5, 1, 2, 1, 3, 2, 5, 4, 3};
    int result = ob.singleNumber(array);
    (result != 0) ? std::cout<<"The Unique Value is: "<<result<<std::endl : std::cout<<"No Match Found!!!"<<std::endl;
    return 0;
}
