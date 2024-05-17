# include<iostream>
# include<string>
# include<set>
# include<algorithm>
class Solution{
    public:
    int lengthOfLongestSubstring(std::string& s){
        int left = 0, right = 0, maxLength = 0;
        std::set<char> charSet;
        while(right < s.size()){
            if(charSet.find(s[right]) == charSet.end()){
                charSet.insert(s[right]);
                maxLength = std::max(maxLength, right - left + 1);
                right++;
            }else{
                charSet.erase(s[left]);
                left++;
            }
        }
        return maxLength;
    }
};
int main(int argc, const char** argv){
    Solution ob;
    std::string s1 = "abcabcbb";
    std::cout<<"Test Case 1: "<<ob.lengthOfLongestSubstring(s1)<<std::endl;
    std::string s2 = "bbbbb";
    std::cout<<"Test Case 2: "<<ob.lengthOfLongestSubstring(s2)<<std::endl;
    std::string s3 = "pwwkew";
    std::cout<<"Test Case 3: "<<ob.lengthOfLongestSubstring(s3)<<std::endl;
    return 0;
}