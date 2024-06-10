# include<iostream>
# include<string>
# include<bitset>
# include<sstream>
class Solution{
    public:
    std::string addBinary(const std::string& a, const std::string& b){
        std::bitset<1024> first_number(a);
        std::bitset<1024> second_number(b);
        std::bitset<1024> sum = first_number.to_ullong() + second_number.to_ullong();
        std::string result = sum.to_string();
        size_t pos = result.find('1');
        if(pos != std::string::npos) return result.substr(pos);
        return "0";
    }
};
int main(int argc, const char** argv){
    Solution ob;
    std::string a = "1010";
    std::string b = "1011";
    std::cout<<ob.addBinary(a, b)<<std::endl;    // Output should be "10101"
    return 0;
}