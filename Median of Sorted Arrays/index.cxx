# include<iostream>
# include<vector>
# include<algorithm>
class Solution{
    public:
    // double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
    //     int totalSize = nums1.size() + nums2.size();
    //     if(totalSize % 2 == 1)
    //         return findKth(nums1, 0, nums2, 0, totalSize / 2 + 1);
    //     else
    //         return (findKth(nums1, 0, nums2, 0, totalSize / 2) + findKth(nums1, 0, nums2, 0, totalSize / 2 + 1)) / 2.0;
    // }
    // double findKth(vector<int>& nums1, int start1, vector<int>& nums2, int start2, int k){
    //     int size1 = nums1.size() - start1;
    //     int size2 = nums2.size() - start2;
    //     if(size1 > size2)
    //         return findKth(nums2, start2, nums1, start1, k);
    //     if(size1 == 0)
    //         return nums2[start2 + k - 1];
    //     if(k == 1)
    //         return min(nums1[start1], nums2[start2]);
    //     int partition1 = min(k / 2, size1);
    //     int partition2 = k - partition1;
    //     if(nums1[start1 + partition1 - 1] < nums2[start2 + partition2 - 1])
    //         return findKth(nums1, start1 + partition1, nums2, start2, k - partition1);
    //     else
    //         return findKth(nums1, start1, nums2, start2 + partition2, k - partition2);
    // }
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2){
        int i = 0, j = 0;
        std::vector<int> merged;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i] < nums2[j]){
                merged.push_back(nums1[i]);
                i++;
            }else{
                merged.push_back(nums2[j]);
                j++;
            }
        }
        while(i < nums1.size()){
            merged.push_back(nums1[i]);
            i++;
        }
        while(j < nums2.size()){
            merged.push_back(nums2[j]);
            j++;
        }
        int totalSize = merged.size();
        if(totalSize % 2 == 1)
            return merged[totalSize / 2];
        else
            return (merged[totalSize / 2 - 1] + merged[totalSize / 2]) / 2.0;
    }
};
int main(int argc, const char** argv){
    Solution ob;
    std::vector<int> nums1 = {1, 3};
    std::vector<int> nums2 = {2};
    std::cout<<"Median: "<<ob.findMedianSortedArrays(nums1, nums2)<<std::endl;
    nums1 = {1, 2};
    nums2 = {3, 4};
    std::cout<<"Median: "<<ob.findMedianSortedArrays(nums1, nums2)<<std::endl;
    return 0;
}
