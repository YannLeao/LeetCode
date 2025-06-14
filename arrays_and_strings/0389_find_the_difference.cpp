# include <iostream>
# include <string>
#include <vector>

class Solution {
public:
    static char findTheDifference(const std::string s, std::string t) {
        std::vector<char> s_(s.begin(), s.end());
        std::vector<char> t_(t.begin(), t.end());
        bool find = false;

        for (int i = 0; i < t.length(); ++i)
        {
            for (int j = 0; j < s_.size(); ++j)
            {
                if (t_[i] == s_[j])
                {
                    find = true;
                    s_.erase(s_.begin() + j);
                    break;
                }
            }
            if (find == false)
            {
                return t[i];
            }
            find = false;
        }
        return 1;
    }
};

int main() {
  std::cout << Solution::findTheDifference("abc", "awbc") << std::endl;
  return 0;
}