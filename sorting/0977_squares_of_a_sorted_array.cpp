#include <algorithm>
#include <vector>

class Solution {
public:
    std::vector<int> sortedSquares(std::vector<int>& nums) {
        std::vector<int> squares;

        for (int i : nums) squares.push_back(i*i);

        std::sort(squares.begin(), squares.end());

        return squares;
    }
};
