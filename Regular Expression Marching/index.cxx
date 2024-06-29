#include <vector>
#include <string>
class Solution {
    public:
    bool isMatch(std::string s, std::string p) {
        int m = s.size();
        int n = p.size();
        // dp[i][j] will be true if s[0..i-1] matches p[0..j-1]
        std::vector<std::vector<bool>> dp(m + 1, std::vector<bool>(n + 1, false));    
        // Both s and p are empty
        dp[0][0] = true;
        // Deal with patterns like a*, a*b*, a*b*c* etc.
        for (int j = 1; j <= n; ++j) {
            if (p[j - 1] == '*') {
                dp[0][j] = dp[0][j - 2];
            }
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == s[i - 1] || p[j - 1] == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    dp[i][j] = dp[i][j - 2]; // Treat * as matching zero preceding elements
                    if (p[j - 2] == s[i - 1] || p[j - 2] == '.') {
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                }
            }
        }
        return dp[m][n];
    }
};
int main(int argc, const char** argv) {
    Solution solution;
    std::string s1 = "aa";
    std::string p1 = "a";
    bool result1 = solution.isMatch(s1, p1);    // Expected output: false
    std::string s2 = "aa";
    std::string p2 = "a*";
    bool result2 = solution.isMatch(s2, p2);    // Expected output: true
    std::string s3 = "ab";
    std::string p3 = ".*";
    bool result3 = solution.isMatch(s3, p3);    // Expected output: true
    return 0;
}