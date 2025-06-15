#include <algorithm>
#include <string>

class Solution {
public:
    std::string convertToTitle(int columnNumber) {
        std::string result;
        while (columnNumber)
        {
            int mod = columnNumber % 26;
            if (mod == 0) result.push_back('Z');
            else result.push_back((mod - 1) + 'A');
            columnNumber = (columnNumber - 1) / 26;
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
};
