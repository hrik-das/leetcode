# include<iostream>
# include<vector>
# include<algorithm>
class Solution{
    public:
    int numRescueBoats(std::vector<int>& people, int limit){
        std::sort(people.begin(), people.end());
        int boats = 0, left = 0, right = people.size() - 1;
        while(left <= right){
            if(people[left] + people[right] <= limit)
                left++;
            right--;
            boats++;
        }
        return boats;
    }
};
int main(int argc, char *argv[]){
    Solution ob;
    std::vector<int> array = {3, 2, 2, 1};
    int limit = 3;
    int boats = ob.numRescueBoats(array, limit);
    std::cout<<boats<<" boats to carry every given people."<<std::endl;
    return 0;
}