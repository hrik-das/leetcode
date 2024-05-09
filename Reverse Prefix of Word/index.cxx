# include<iostream>
# include<vector>
# include<algorithm>
class Solution{
    public:
    std::string reversePrefix(std::string word, char ch){
        auto pos = word.find(ch);
        std::cout<<pos<<std::endl;
        if(pos != std::string::npos){
            std::reverse(word.begin(), word.begin() + pos + 1);
        }
        return word;
    }
};
int main(int argc, char *argv[]){
    Solution ob;
    std::string word1 = "abcdefd";
    char ch1 = 'd';
    std::cout<<"Input: word = \""<<word1<<"\", ch = \""<<ch1<<"\""<<std::endl;
    std::cout<<"Output: "<<ob.reversePrefix(word1, ch1)<<std::endl;
    std::string word2 = "xyxzxe";
    char ch2 = 'z';
    std::cout<<"Input: word = \""<<word2<<"\", ch = \""<<ch2<<"\""<<std::endl;
    std::cout<<"Output: "<<ob.reversePrefix(word2, ch2)<<std::endl;
    std::string word3 = "abcd";
    char ch3 = 'z';
    std::cout<<"Input: word = \""<<word3<<"\", ch = \""<<ch3<<"\""<<std::endl;
    std::cout<<"Output: "<<ob.reversePrefix(word3, ch3)<<std::endl;
    return EXIT_SUCCESS;
}