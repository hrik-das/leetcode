#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    int target = 0;
    std::sort(nums.begin(), nums.end());
    std::set<std::vector<int>> s;
    std::vector<std::vector<int>> output;
    for (int i = 0; i < nums.size(); i++){
        int j = i + 1;
        int k = nums.size() - 1;
        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum == target) {
                s.insert({nums[i], nums[j], nums[k]});
                j++;
                k--;
            } else if (sum < target) {
                j++;
            } else {
                k--;
            }
        }
    }
    for(auto triplets : s)
        output.push_back(triplets);
    return output;
}

void printTriplets(const std::vector<std::vector<int>>& triplets) {
    for(const auto& triplet : triplets) {
        std::cout << "[";
        for(int i = 0; i < triplet.size(); ++i) {
            std::cout << triplet[i];
            if(i < triplet.size() - 1) {
                std::cout << ",";
            }
        }
        std::cout << "]";
    }
    std::cout << std::endl;
}

int main() {
    // Test cases
    std::vector<int> nums1 = {-1, 0, 1, 2, -1, -4};
    std::cout << "Example 1:\nInput: [-1, 0, 1, 2, -1, -4]\nOutput: ";
    printTriplets(threeSum(nums1));

    std::vector<int> nums2 = {0, 1, 1};
    std::cout << "Example 2:\nInput: [0, 1, 1]\nOutput: ";
    printTriplets(threeSum(nums2));

    std::vector<int> nums3 = {0, 0, 0};
    std::cout << "Example 3:\nInput: [0, 0, 0]\nOutput: ";
    printTriplets(threeSum(nums3));

    return 0;
}
