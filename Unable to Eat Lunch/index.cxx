# include<iostream>
# include<algorithm>
# include<vector>
#include <cstdint>
class Solution{
    public:
    int countStudents(std::vector<int>& students, std::vector<int>& sandwiches){
        int64_t unableToEat = 0;
        while(students.size() > 0 && unableToEat < students.size()){
            if(students[0] == sandwiches[0]){
                students.erase(students.begin());
                sandwiches.erase(sandwiches.begin());
                unableToEat = 0;
            }
            students.push_back(students[0]);
            students.erase(students.begin());
            unableToEat++;
        }
        return unableToEat;
    }
};
int main(int argc, char *argv[]){
    Solution ob;
    std::vector<int> students = {1, 1, 1, 0, 0, 1};
    std::vector<int> sandwiches = {1, 0, 0, 0, 1, 1};
    int unable = ob.countStudents(students, sandwiches);
    std::cout<<"Unable to Eat: "<<unable<<std::endl;
    return EXIT_SUCCESS;
}