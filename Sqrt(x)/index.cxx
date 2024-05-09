# include<iostream>
# include<algorithm>
class Solution{
public:
    int mySqrt(int x){
        if (x == 0 || x == 1) return x;
        int left = 1, right = x;
        while(left <= right){
            int mid = left + (right - left) / 2;
            long long square = static_cast<long long>(mid) * mid;
            if(square == x) return mid;
            else if(square < x) left = mid + 1;
            else right = mid - 1;
        }
        return std::max(right, left - 1);
    }
};
int main(int argc, char* argv[]){
    Solution ob;
    std::cout<<"The Square Root of 4 is: "<<ob.mySqrt(4)<<std::endl;
    std::cout<<"The Square Root of 8 is: "<<ob.mySqrt(8)<<std::endl;
    return 0;
}
