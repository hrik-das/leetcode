# include<iostream>
# include<vector>
# include<string>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        if (strs.empty()) return "";

        std::string prefix = strs[0];
        for (int i=1; i<strs.size(); i++) {
            while (strs[i].find(prefix) != 0) {
                prefix = prefix.substr(0, prefix.length() - 1);
                if (prefix.empty()) return "";
            }
        }

        return prefix;
    }
};

int main(int argc, const char** argv) {
    Solution ob;
    std::vector<std::string> strs1 = {"flower", "flow", "flight"};
    std::cout<<"Longest Common Prefix: "<<ob.longestCommonPrefix(strs1)<<std::endl;

    std::vector<std::string> strs2 = {"dog", "racecar", "car"};
    std::cout<<"Longest Common Prefix: "<<ob.longestCommonPrefix(strs2)<<std::endl;

    return EXIT_SUCCESS;
}