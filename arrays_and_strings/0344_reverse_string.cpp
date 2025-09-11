#include <vector>

class Solution {
public:
    static void reverseString(std::vector<char>& s) {
        int limit = s.size() / 2 - 1;
        int final_ptr = s.size() - 1;

        for (int i = 0; i <= limit; ++i)
        {
            char temp = s[i];
            s[i] = s[final_ptr];
            s[final_ptr] = temp;
            final_ptr--;
        }
    }
};
