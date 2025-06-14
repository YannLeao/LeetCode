#include <iostream>
#include <string>

class Solution {
public:
    static int strStr(std::string haystack, std::string needle) {
        int location = -1;
        for (int i = 0; i < haystack.length(); ++i)
        {
            int i_ = i;
            if (haystack[i] == needle[0])
            {
                location = i;
                for (auto c : needle)
                {
                    if (c != haystack[i_])
                    {
                        location = -1;
                        break;
                    }
                    else i_++;
                }
                if (location != -1) return location;
            }
        }
        return location;
    }
};

int main()
{
    std::cout << Solution::strStr("mississippi", "issip") << std::endl;
    return 0;
}
