# include<iostream>
# include<vector>
# include<algorithm>
class Solution{
    public:
    int minCostClimbingStairs(const std::vector<int>& cost){
        int n = cost.size();
        if(n <= 1) return 0;
        std::vector<int> minCost(n);        
        minCost[0] = cost[0];
        minCost[1] = cost[1];
        for(int i=2; i<n; i++)
            minCost[i] = cost[i] + std::min(minCost[i - 1], minCost[i - 2]);
        return std::min(minCost[n - 1], minCost[n - 2]);
    }
};
int main(int argc, char* argv[]){
    Solution ob;
    std::vector<std::vector<int>> testCases = {{10, 15, 20}, {1, 100, 1, 1, 1, 100, 1, 1, 100, 1}};
    for(const auto& cost : testCases){
        std::cout<<"Input: [";
        for(size_t i=0; i<cost.size(); i++){
            std::cout<<cost[i];
            if(i<cost.size() - 1) std::cout<<", ";
        }
        std::cout<<"]"<<std::endl;
        int result = ob.minCostClimbingStairs(cost);
        std::cout<<"Output: "<<result<<std::endl<<std::endl;
    }
    return 0;
}