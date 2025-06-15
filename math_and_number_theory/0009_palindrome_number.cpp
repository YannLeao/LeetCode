#include <algorithm>
#include <string>

class Solution {
public:
    bool isPalindrome(int x) {
        std::string str = std::to_string(x);
        std::reverse(str.begin(), str.end());
        return (std::to_string(x) == str) ? true : false;        
    }
};
