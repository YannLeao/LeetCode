#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Solution {
public:
    static int lengthOfLastWord(std::string s) {
        s = trim(s);
        std::stringstream ss(s);
        std::string iten;
        std::vector<std::string> tokens;

        while (std::getline(ss, iten, ' ')) tokens.push_back(iten);

        return tokens[tokens.size() - 1].length();
        
    }

    static std::string trim(const std::string& s)
    {
        int start = s.find_first_not_of(" \n\t\r");
        if (start == std::string::npos) return "";

        int end = s.find_last_not_of(" \n\t\r");
        return s.substr(start, end - start + 1);
    }
};

int main()
{
    std::cout << Solution::lengthOfLastWord("   fly me   to   the moon  ") << std::endl;
}
