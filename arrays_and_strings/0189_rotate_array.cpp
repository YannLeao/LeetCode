#include <vector>

// in-place solution
class Solution {
public:
    static void rotate(std::vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;

        auto reverseRange = [&](int start, int end) {
            while (start < end) {
                std::swap(nums[start], nums[end]);
                start++;
                end--;
            }
        };

        reverseRange(0, n - 1);
        reverseRange(0, k - 1);
        reverseRange(k, n - 1);
    }
};

// O(n) memory solution
//
// class Solution {
// public:
//     static void rotate(std::vector<int>& nums, int k) {
//         auto copy = nums;
//         int n = nums.size();
//         k %= n;
//         for (int i = 0; i < copy.size(); ++i)
//         {
//             nums[i] = copy[(i - k + n) % n];
//         }
//     }
// };
