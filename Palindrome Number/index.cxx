# include<iostream>
# include<string>
# include<algorithm>
class Solution {
    public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        std::string str = std::to_string(x);
        return checkPalindrome(str);
    }

    private:
    bool checkPalindrome(const std::string& str) {
        std::string reversedStr = str;
        std::reverse(reversedStr.begin(), reversedStr.end());
        return str == reversedStr;
    }
};

int main(int argc, const char** argv) {
    Solution ob;
    int x1 = 121;
    int x2 = -121;
    int x3 = 10;
    std::cout<<std::boolalpha;
    std::cout<<"Is "<<x1<<" a palindrome? "<<ob.isPalindrome(x1) << std::endl;
    std::cout<<"Is "<<x2<<" a palindrome? "<<ob.isPalindrome(x2)<<std::endl;
    std::cout<<"Is "<<x3<<" a palindrome? "<<ob.isPalindrome(x3)<<std::endl;
    return EXIT_SUCCESS;
}