# include<iostream>
# include<string.h>
# include<vector>
class Solution{
    public:
    std::string zigzagConversion(std::string& str, int numRows){
        if(numRows == 1 || numRows >= str.length()) return str;
        std::vector<std::string> rows(numRows, "");
        bool goingDown = false;
        int currentRow = 0;
        for(char character:str){
            rows[currentRow] += character;
            if(currentRow == 0 || currentRow  == numRows - 1)
                goingDown = !goingDown;
            currentRow += goingDown ? 1 : -1;
        }
        std::string result;
        for(const std::string& row:rows){
            result += row;
        }
        return result;
    } 
};
int main(int argc, const char** argv){
    Solution ob;
    std::string s1 = "PAYPALISHIRING";
    int numRows1 = 3;
    std::cout<<ob.zigzagConversion(s1, numRows1)<<std::endl;
    std::string s2 = "PAYPALISHIRING";
    int numRows2 = 4;
    std::cout<<ob.zigzagConversion(s2, numRows2)<<std::endl;
    std::string s3 = "A";
    int numRows3 = 1;
    std::cout<<ob.zigzagConversion(s3, numRows3)<<std::endl;
    return 0;
}