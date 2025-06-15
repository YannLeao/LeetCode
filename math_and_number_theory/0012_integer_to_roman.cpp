#include <map>
#include <string>
#include <vector>

class Solution {
public:
    std::vector<std::pair<int, char>> roman = {
        {1000, 'M'},
        {500, 'D'},
        {100, 'C'},
        {50, 'L'},
        {10, 'X'},
        {5, 'V'},
        {1, 'I'}
    };

    std::string intToRoman(int num) {
        std::string result;
        for (int i = 0; i < roman.size(); i += 2)
        {
            int div = num / roman[i].first;
            if (div < 4)
            {
                for (int j = 0; j < div; ++j) result.push_back(roman[i].second);
            }
            else if (div == 4)
            {
                result.push_back(roman[i].second);
                result.push_back(roman[i - 1].second);
            }
            else if (div < 9)
            {
                result.push_back(roman[i - 1].second);
                for (int j = 5; j < div; ++j) result.push_back(roman[i].second);
            }
            else
            {
                result.push_back(roman[i].second);
                result.push_back(roman[i - 2].second);
            }
            num %= roman[i].first;
        }
        return result;
    }
};
