#include <iostream>
#include <map>
#include <string>

class Solution {
public:
    static int romanToInt(std::string s) {
        std::map<char, int> roman = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}

        };

        int result = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            if (roman[s[i]] < roman[s[i + 1]])
            {
                result += (roman[s[i + 1]] - roman[s[i]]);
                i++;
                continue;
            }
            result += roman[s[i]];
        }

        return result;

    }
};

int main()
{
    std::cout << Solution::romanToInt("IV") << std::endl;
}
