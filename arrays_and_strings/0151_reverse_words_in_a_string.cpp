#include <algorithm>
#include <sstream>
#include <string>
#include <vector>

class Solution {
public:
    static std::string reverseWords(std::string s) {
        std::istringstream iss(s);
        std::vector<std::string> words;
        std::string word;

        while (iss >> word) words.push_back(word);
        std::reverse(words.begin(), words.end());

        std::string result;
        for (int i = 0; i < words.size(); ++i)
        {
            if (i > 0) result += " ";
            result += words[i];
        }
        return result;
    }
};
