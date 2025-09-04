#include <algorithm>
#include <vector>

class Solution {
public:
    int heightChecker(std::vector<int>& heights) {
        int count = 0;
        std::vector<int> expected = heights;
        std::sort(expected.begin(), expected.end());

        for (int i = 0; i < heights.size(); ++i)
        {
            if (expected[i] != heights[i]) count++;
        }
        return count;
    }
};
