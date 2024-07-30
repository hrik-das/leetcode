# include<iostream>
class Solution {
    public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }
};

int main(int argc, const char** argv){
    Solution solution;
    int test1 = 1;
    int test2 = 16;
    int test3 = 3;
    std::cout<<std::boolalpha;
    std::cout<<"Is "<<test1<<" a power of two? "<<solution.isPowerOfTwo(test1)<<std::endl;
    std::cout<<"Is "<<test2<<" a power of two? "<<solution.isPowerOfTwo(test2)<<std::endl;
    std::cout<<"Is "<<test3<<" a power of two? "<<solution.isPowerOfTwo(test3)<<std::endl;
    return 0;
}