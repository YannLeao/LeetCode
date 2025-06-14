#include <iostream>
#include <map>
#include <set>
#include <vector>

class Solution {
public:
    static void setZeroes(std::vector<std::vector<int>>& matrix) {
        std::map<char, std::set<int>> zeros {
            {'r',{}},
            {'c',{}}
        };

        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix[0].size(); ++j)
            {
                if (matrix[i][j] == 0)
                {
                    zeros['r'].insert(i);
                    zeros['c'].insert(j);
                }
            }
        }

        for (auto column : zeros['c'])
        {
            for (auto & i : matrix) i[column] = 0;
        }
        for (auto row : zeros['r'])
        {
            for (int j = 0; j < matrix[0].size(); ++j) matrix[row][j] = 0;
        }
    }
};

int main()
{

    std::vector<std::vector<int>> matrix = {
        {0, 1}
    };

    Solution::setZeroes(matrix);

    for (auto & vector : matrix)
    {
        for (auto number : vector)
        {
            std::cout << number << std::endl;
        }
    };

}
