#include <climits>

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;

        bool is_negative = dividend < 0 ^ divisor < 0;

        if (dividend > 0) dividend = -dividend;
        if (divisor > 0) divisor = -divisor;

        if (divisor == -1) return (is_negative) ? dividend : -dividend;
        
        int count = 0;
        while (dividend <= divisor) {
            dividend -= divisor;
            ++count;
        }
        return (is_negative) ? -count : count;
    }    
};
