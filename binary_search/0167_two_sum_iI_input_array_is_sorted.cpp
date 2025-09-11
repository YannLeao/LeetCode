#include <vector>

class Solution {
public:
    static std::vector<int> twoSum(std::vector<int>& numbers, int target)
    {
        int left = 0;
        int right = numbers.size() - 1;

        while (numbers[left] + numbers[right] != target)
        {
            if (numbers[left] + numbers[right] < target) left++;
            else if (numbers[left] + numbers[right] > target) right--;
        }
        return {left, right};
    }
};
