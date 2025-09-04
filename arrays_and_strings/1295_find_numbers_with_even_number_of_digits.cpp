#include <string>
#include <vector>

class Solution {
public:
    int findNumbers(std::vector<int>& nums) {
        int cnt_evens = 0;

        for (int i : nums)
        {
            std::string str_int = std::to_string(i);
            if (str_int.length() % 2 == 0) cnt_evens++;
        }

        return cnt_evens;
    }
};
