# include<iostream>
# include<string>
class Solution{
    public:
    int compareVersion(std::string version1, std::string version2){
        int i = 0, j = 0;
        while(i < version1.size() || j < version2.size()){
            int num1 = 0, num2 = 0;
            while(i < version1.size() && version1[i] != '.'){
                num1 = num1 * 10 + (version1[i] - '0');
                i++;
            }
            while(j < version2.size() && version2[j] != '.'){
                num2 = num2 * 10 + (version2[j] - '0');
                j++;
            }
            if(num1 < num2) return -1;
            else if(num1 > num2) return 1;
            i++;
            j++;
        }
        return 0;
    }
};
int main(int argc, char *argv[]){
    Solution ob;
    std::string version1 = "1.01";
    std::string version2 = "1.001";
    std::cout<<ob.compareVersion(version1, version2)<<std::endl;
    version1 = "1.0";
    version2 = "1.0.0";
    std::cout<<ob.compareVersion(version1, version2)<<std::endl;
    version1 = "0.1";
    version2 = "1.1";
    std::cout<<ob.compareVersion(version1, version2)<<std::endl;
    return EXIT_SUCCESS;
}