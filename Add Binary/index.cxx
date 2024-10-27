# include<iostream>
# include<string>
class Solution {
    public:
    std::string addBinary(const std::string& a, const std::string& b) {
        std::string result;
        int carry = 0, i = a.size() - 1, j = b.size() - 1;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';
            result = char(sum % 2 + '0') + result;
            carry = sum / 2;
        }
        return result;
    }
};

int main(int argc, const char **argv) {
    Solution ob;
    std::string a = "1010";
    std::string b = "1011";
    std::cout<<ob.addBinary(a, b)<<std::endl;    // Output should be "10101"
    return 0;
}
