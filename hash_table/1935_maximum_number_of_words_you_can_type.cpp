#include <sstream>
#include <string>
#include <unordered_set>

class Solution {
public:
    static int canBeTypedWords(const std::string& text, std::string brokenLetters)
    {
        std::unordered_set<char> broken(brokenLetters.begin(), brokenLetters.end());

        std::stringstream ss(text);
        std::string word;
        int count = 0;

        while (ss >> word)
        {
            bool canType = true;
            for (char c : word)
            {
                if (broken.count(c)){ canType = false; break; }
            }
            if (canType) count++;
        }

        return count;
    }
};
