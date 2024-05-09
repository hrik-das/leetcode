#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
class Solution{
    public:
    std::vector<int> computePrefix(const std::string& pattern){
        int i = 1, len = 0;
        int m = pattern.size();
        std::vector<int> prefix(m, 0);
        while(i < m){
            if(pattern[i] == pattern[len]){
                len++;
                prefix[i] = len;
                i++;
            }else{
                if(len != 0) len = prefix[len - 1];
                else{
                    prefix[i] = 0;
                    i++;
                }
            }
        }
        return prefix;
    }
    int strStr(const std::string& haystack, const std::string& needle){
        int n = haystack.size();
        int m = needle.size();
        if(m == 0){
            return 0;
        }
        std::vector<int> prefix = computePrefix(needle);
        int i = 0, j = 0;
        while(i < n){
            if(haystack[i] == needle[j]){
                i++;
                j++;
            }
            if(j == m){
                return i - j;
            }else if(i < n && haystack[i] != needle[j]){
                if(j != 0){
                    j = prefix[j - 1];
                }else{
                    i++;
                }
            }
        }
        return -1;
    }
};
int main(int argc, char* argv[]){
    Solution ob;
    std::string haystack1 = "sadbutsad";
    std::string needle1 = "sad";
    std::cout<<ob.strStr(haystack1, needle1)<<std::endl;
    std::string haystack2 = "leetcode";
    std::string needle2 = "leeto";
    std::cout<<ob.strStr(haystack2, needle2)<<std::endl;
    return EXIT_SUCCESS;
}