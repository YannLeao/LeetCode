#include <iostream>
#include <vector>

class Solution {
public:
    static std::vector<int> getRow(int rowIndex) {
        std::vector<int> row = {1};

        for (int i = 1; i <= rowIndex; ++i)
        {
            auto previous = row;
            row.clear();

            row.push_back(1);
            for (int j = 1; j < i; ++j)
            {
                int value = previous[j] + previous[j - 1];
                row.push_back(value);
            }
            row.push_back(1);
        }
        return row;
    }
};