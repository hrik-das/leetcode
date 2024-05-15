# include<iostream>
# include<string>
# include<vector>
# include<unordered_map>
# include<unordered_set>
class Solution{
    public:
    int romanToInt(const std::string& s){
        int total = 0, n = s.length();
        std::unordered_map<char, int> roman{{'I', 1}, {'V', 5}, {'X', 10},{'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        std::unordered_set<std::string> subtractiveCombinations{"IV", "IX", "XL", "XC", "CD", "CM"};
        for(int i = 0; i < n; ++i){
            if(roman.find(s[i]) == roman.end()) continue;
            if(i < n - 1){
                std::string twoChars = s.substr(i, 2);
                if(subtractiveCombinations.count(twoChars)){
                    total += (roman[s[i + 1]] - roman[s[i]]);
                    ++i;
                    continue;
                }
            }
            total += roman[s[i]];
        }
        return total;
    }
    void testRomanToInt(Solution& object, const std::string& s){
        int result = object.romanToInt(s);
        std::cout<<"Input: "<<s<<"\nOutput: "<<result<<std::endl;
    }
};
int main(int argc, const char** argv){
    Solution ob;
    std::vector<std::string> testCases = {"III", "IV", "IX", "LVIII", "MCMXCIV", "AIII", "MMXXIV", "CDXLIV", "INVALID", " "};
    for(const auto& testCase : testCases)
        ob.testRomanToInt(ob, testCase);
    return 0;
}
