# include<iostream>
#include <vector>
class Solution{
public:
    std::vector<int> plusOne(std::vector<int>& digits){
        int carry = 1;
        int n = digits.size();
        for(int i=n-1; i>=0; i--){
            int sum = digits[i] + carry;
            digits[i] = sum % 10;
            carry = sum / 10;
            if(carry == 0) break;
        }
        if(carry > 0){
            digits.insert(digits.begin(), carry);
        }
        return digits;
    }
};
int main(int argc, char* argv[]){
    std::vector<int> digits = {1, 2, 3};
    Solution sol;
    std::vector<int> result = sol.plusOne(digits);
    for(int digit : result){
        std::cout<<digit<<" ";
    }
    return 0;
}