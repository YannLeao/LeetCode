#include <algorithm>
#include <vector>

class Solution {
public:
    static std::vector<int> findDiagonalOrder(std::vector<std::vector<int>>& mat) {
        int n_r = mat.size();
        int n_c = mat[0].size();
        std::vector<int> result;
        std::vector<int> intermediate;

        for (int i = 0; i < n_c + n_r - 1; ++i)
        {
            int row = i < n_c ? 0 : i - n_c + 1;
            int column = i < n_c ? i : n_c - 1;

            while (row < n_r && column > -1)
            {
                intermediate.push_back(mat[row][column]);
                row++;
                column--;
            }

            if (i % 2 == 0) std::reverse(intermediate.begin(), intermediate.end());
            for (auto num : intermediate) result.push_back(num);

            intermediate.clear();
        }
        return result;
    }
};
