#include <iostream>
#include <string>


class Solution {
public:
    static bool repeatedSubstringPattern(std::string s) {
        std::string s_ = s + s;
        s_ = s_.substr(1, s_.length() - 2);

        if (s_.find(s) > s_.length() || s_.find(s) < 0) return false;

        return true;
    }
};

int main ()
{
    std::cout << Solution::repeatedSubstringPattern("aa") << std::endl;
}
