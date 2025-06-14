#include <limits>
#include <numeric>
#include <vector>

class Solution {
public:
    int maximumWealth(std::vector<std::vector<int>>& accounts) {
        int max = std::numeric_limits<int>::min();
        for (auto account : accounts)
        {
            int sum = std::accumulate(account.begin(), account.end(), 0);
            if (sum > max) max = sum;
        }
        return max;
    }
};
