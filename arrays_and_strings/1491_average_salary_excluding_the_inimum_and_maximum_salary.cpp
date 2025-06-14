#include <algorithm>
#include <numeric>
#include <vector>

class Solution {
public:
    double average(std::vector<int>& salary) {
        std::sort(salary.begin(), salary.end());
        return std::accumulate(salary.begin() + 1, salary.end() - 1, 0.0) / (salary.size() - 2);
    }
};
