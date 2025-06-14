#include <vector>

class Solution {
public:
    int diagonalSum(std::vector<std::vector<int>>& matrix) {
        int sum = 0;
        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix.size(); ++j)
            {
                if (i == j) sum += matrix[i][j];
                if (i + j == matrix.size() - 1) sum += matrix[i][j];
            }
        }
        if (matrix.size() % 2 == 1) return sum - matrix[matrix.size() / 2][matrix.size() / 2];
        return sum;
    }
};
