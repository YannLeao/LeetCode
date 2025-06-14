#include <iostream>
#include <vector>

class Solution {
public:
    static std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
        std::vector<int> result;
        int top_row = 0;
        int bottom_row = matrix.size() - 1;
        int left_column = 0;
        int right_column = matrix[0].size() - 1;

        while (top_row <= bottom_row && left_column <= right_column)
        {
            for (int j = left_column; j <= right_column; ++j) result.push_back(matrix[top_row][j]);
            top_row++;

            for (int i = top_row; i <= bottom_row; ++i) result.push_back(matrix[i][right_column]);
            right_column--;

            if (top_row <= bottom_row)
            {
                for (int j = right_column; j >= left_column; --j) result.push_back(matrix[bottom_row][j]);
                bottom_row--;
            }

            if (left_column <= right_column)
            {
                for (int i = bottom_row; i >= top_row; --i) result.push_back(matrix[i][left_column]);
                left_column++;
            }
        }
        return result;
    }
};

int main()
{
    std::vector<std::vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    std::vector<int> result = Solution::spiralOrder(matrix);

    for (auto number : result)
    {
        std::cout << number << std::endl;
    }
}
