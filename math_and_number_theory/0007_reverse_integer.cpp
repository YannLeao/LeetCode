#include <algorithm>
#include <stdexcept>
#include <string>

class Solution {
public:
    int reverse(int x) {
        try {
            std::string str = std::to_string(Solution::safe_abs(x));
            if (x < 0) str.push_back('-');
            std::reverse(str.begin(), str.end());
            return std::stoi(str);
        } catch (std::out_of_range& e) {
            return 0;
        } catch (std::overflow_error& e) {
            return 0;
        }
    }

    static int safe_abs(int x) {
        if (x == INT_MIN)  throw std::overflow_error("Result would overflow for INT_MIN");
        return std::abs(x);
    }
};
