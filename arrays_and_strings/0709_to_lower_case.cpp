#include <string>

class Solution {
public:
    std::string toLowerCase(std::string s) {
        for (char& c : s)
        {
            if (std::islower(c)) continue;
            c = std::tolower(c);
        }
        return s;
    }
};
