#include <algorithm>
#include <string>

class Solution {
public:
    int titleToNumber(std::string title) {
        std::reverse(title.begin(), title.end());
        int result = 0;
        long long multiply = 1;
        for (char c : title)
        {
            int i = ((c - 'A') + 1) * multiply;
            result += i;
            multiply *= 26;
        }
        return result;
    }
};
