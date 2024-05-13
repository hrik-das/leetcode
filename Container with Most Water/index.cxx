# include<iostream>
# include<vector>
# include<algorithm>
class Solution{
    public:
    int maxArea(std::vector<int>& height){
        int left = 0, max_area = 0;
        int right = height.size() - 1;
        while(left < right){
            max_area = std::max(max_area, (right - left) * std::min(height[left], height[right]));
            if(height[left] < height[right]) left++;
            else right--;
        }
        return max_area;
    }
};
int main(int argc, const char* argv[]){
    Solution ob;
    std::vector<int> height1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    std::cout<<"Test case 1:\n";
    std::cout<<"Input: ";
    for(int h : height1)
        std::cout<<h<<" ";
    std::cout<<"\nOutput: "<<ob.maxArea(height1)<<std::endl;
    std::vector<int> height2 = {1, 1};
    std::cout<<"\nTest case 2:\n";
    std::cout<<"Input: ";
    for(int h : height2)
        std::cout << h << " ";
    std::cout<<"\nOutput: "<<ob.maxArea(height2)<<std::endl;
    return EXIT_SUCCESS;
}