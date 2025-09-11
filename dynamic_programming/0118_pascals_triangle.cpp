#include <iostream>
#include <vector>

class Solution {
public:
    static std::vector<std::vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> triangle = { {1} };

        for (int i = 2; i <= numRows; ++i)
        {
            std::vector row = {1};
            int previous = i - 2;

            for (int j = 1; j < i - 1; ++j)
            {
                int value = triangle[previous][j] + triangle[previous][j - 1];
                row.push_back(value);
            }

            row.push_back(1);
            triangle.push_back(row);
        }
        return triangle;
        
    }
};

int main()
{
    int n = 3;
    std::vector<std::vector<int>> result = Solution::generate(n);

    for (int i = 0; i < result.size(); i++) {
        for (int s = 0; s < n - i - 1; s++) {
            std::cout << "  ";
        }
        for (auto num : result[i]) {
            std::cout << num << "   ";
        }
        std::cout << "\n";
    }
}
