# include<iostream>
# include<string>
# include<climits>    // for INT_MAX and INT_MIN
class Solution{
    public:
    int myAtoi(std::string s){
        int i=0, sign=1, result = 0;
        while(i<s.length() && s[i]==' ')
            i++;
        if(i<s.length() && (s[i]=='+' || s[i]=='-')) sign = (s[i++] == '-') ? -1 : 1;
        while(i<s.length() && s[i]>='0' && s[i]<='9'){
            if(result > INT_MAX / 10 || (result == INT_MAX / 10 && s[i] - '0' > INT_MAX % 10)) return (sign == 1) ? INT_MAX : INT_MIN;
            result = result * 10 + (s[i++] - '0');
        }
        return result * sign;
    }
    void testMyAtoi(std::string s, int expected){
        int result = myAtoi(s);
        std::cout<<"Input: \""<<s<< "\""<<std::endl;
        std::cout<<"Output: "<<result<<std::endl;
    }
};
int main(int argc, const char** argv){
    Solution ob;
    ob.testMyAtoi("42", 42);
    ob.testMyAtoi(" -042", -42);
    ob.testMyAtoi("1337c0d3", 1337);
    ob.testMyAtoi("0-1", 0);
    ob.testMyAtoi("words and 987", 0);
    return EXIT_SUCCESS;
}