#include <map>
#include <string>

class Solution {
public:
    bool canConstruct(std::string ransomNote, std::string magazine) {
        std::map<char, int> magazine_letters;

        for (char c : magazine) 
        { 
            if (magazine_letters.count(c)) magazine_letters[c]++;
            else magazine_letters[c] = 1;
        }

        for (char c : ransomNote) 
        {
            if (!magazine_letters.count(c) || magazine_letters[c] == 0) return false;
            else magazine_letters[c]--;
        }

        return true;
    }
};
