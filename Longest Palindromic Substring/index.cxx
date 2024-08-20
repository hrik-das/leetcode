# include<iostream>
# include<string>
class Solution {
    public:
    std::string longestPalindrome(const std::string& str) {
        if (str.length() <= 1) return str;

        std::string longest = "";
        for (int i=0; i<str.length(); ++i) {
            std::string oddPalindrome = expandAroundCenter(str, i, i);
            std::string evenPalindrome = expandAroundCenter(str, i, i + 1);

            if (oddPalindrome.length() > longest.length()) longest = oddPalindrome;
            if (evenPalindrome.length() > longest.length()) longest = evenPalindrome;
        }
        return longest;
    }

    private:
    std::string expandAroundCenter(const std::string& str, int left, int right) {
        while (left >= 0 && right < str.length() && str[left] == str[right]) {
            --left;
            ++right;
        }
        return str.substr(left + 1, right - left - 1);
    }
};

int main(int argc, const char** argv) {
    Solution ob;
    std::string str1 = "babad";
    std::string str2 = "cbbd";
    std::cout<<"Longest Palindromic Substring in '"<<str1<<"' is: "<<ob.longestPalindrome(str1)<<std::endl;
    std::cout<<"Longest Palindromic Substring in '"<<str2<<"' is: "<<ob.longestPalindrome(str2)<<std::endl;
    return EXIT_SUCCESS;
}