#include <vector>

class Solution {
public:
    std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
        int size = nums.size();
        std::vector<int> missing;
        std::vector<bool> seen(size + 1, false);

        for (auto num : nums) seen[num] = true;
        for (int i = 0; i < seen.size(); ++i) if (!seen[i]) missing.push_back(i);

        return missing;
    }
};
