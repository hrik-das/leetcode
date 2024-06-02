# include<iostream>
# include<vector>
class Solution{
    public:
    void reverseString(std::vector<char>& s){
        int left = 0, right = s.size() - 1;
        while(left < right){
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }
    }
    void printVector(const vector<char>& s){
        for(char c:s){
            std::cout<<c;
        }
        std::cout<<std::endl;
    }
};
int main(int argc, const char** argv){
    Solution ob;
    std::vector<char> test1 = {'h', 'e', 'l', 'l', 'o'};
    std::cout<<"Original: ";
    ob.printVector(test1);
    ob.reverseString(test1);
    std::cout<<"Reversed: ";
    printVector(test1);
    std::vector<char> test2 = {'H', 'a', 'n', 'n', 'a', 'h'};
    std::cout<<"Original: ";
    ob.printVector(test2);
    ob.reverseString(test2);
    std::cout<<"Reversed: ";
    ob.printVector(test2);
    std::vector<char> test4 = {'a'};
    std::cout<<"Original: ";
    ob.printVector(test4);
    ob.reverseString(test4);
    std::cout<<"Reversed: ";
    ob.printVector(test4);
    std::vector<char> test5 = {};
    std::cout<<"Original: ";
    ob.printVector(test5);
    ob.reverseString(test5);
    std::cout<<"Reversed: ";
    ob.printVector(test5);
    return 0;
}