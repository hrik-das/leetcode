# include<iostream>
# include<vector>
class Solution{
    public:
    int stairs(int n){
        if(n <= 1) return 1;
        std::vector<int> step(n + 1);
        step[0] = step[1] = 1;
        for(int i=2; i<=n; i++)
            step[i] = step[i - 1] + step[i - 2];
        return step[n];
    }
};
int main(int argc, char *argv[]){
    Solution ob;
    int n = 5;
    int step = ob.stairs(n);
    std::cout<<"Total Number of Step: "<<step<<" would be taken to reach the Top"<<std::endl;
    return 0;
}