# include<iostream>
# include<vector>
class Solution{
    public:
    int search(std::vector<int>& nums, int target){
        int left = 0, right = nums.size() - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }
};
int main(int argc, const char** argv){
    Solution ob;
    std::vector<int> array = {-1, 0, 3, 5, 9, 12};
    int target_one = 9, target_two = 2;
    int result_postion_one = ob.search(array, target_one);
    int result_postion_two = ob.search(array, target_two);
    for(const int ele : array)
        std::cout<<ele<<" ";
    std::cout<<"\nThe Position of "<<target_one<<" is: "<<result_postion_one<<std::endl;
    std::cout<<"The Position of "<<target_two<<" is: "<<result_postion_two<<std::endl;
    return EXIT_SUCCESS;
}