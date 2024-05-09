# include<iostream>
# include<vector>
# include<algorithm>
class Solution{
    public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n){
        int index1 = m - 1;
        int index2 = n - 1;
        int mergedIndex = m + n - 1;
        while(index1 >= 0 && index2 >= 0){
            if(nums1[index1] > nums2[index2])
                nums1[mergedIndex--] = nums1[index1--];
            else
                nums1[mergedIndex--] = nums2[index2--];
        }
        while(index2 >= 0)
            nums1[mergedIndex--] = nums2[index2--];
    }
};
int main(int argc, char* argv[]){
    Solution ob;
    std::vector<std::vector<int>> nums1 = {{1, 2, 3, 0, 0, 0}, {1}, {0}};
    std::vector<int> m = {3, 1, 0};
    std::vector<std::vector<int>> nums2 = {{2, 5, 6}, {}, {1}};
    std::vector<int> n = {3, 0, 1};
    for(size_t i=0; i<nums1.size(); i++){
        std::cout<<"Test Case "<<i+1<<": "<<std::endl;
        std::cout<<"nums1: ";
        for(int num : nums1[i])
            std::cout<<num<<" ";
        std::cout<<std::endl;
        std::cout<<"m: "<< m[i]<<std::endl;
        std::cout<<"nums2: ";
        for(int num : nums2[i])
            std::cout<<num<<" ";
        std::cout<<std::endl;
        std::cout<<"n: "<<n[i]<<std::endl;
        ob.merge(nums1[i], m[i], nums2[i], n[i]);
        std::cout<<"Merged Array: ";
        for(int num : nums1[i])
            std::cout<<num<< " ";
        std::cout<<std::endl<<std::endl;
    }
    return 0;
}