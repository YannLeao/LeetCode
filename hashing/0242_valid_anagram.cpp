#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
public:
    static bool isAnagram(std::string s, std::string t) {
        std::unordered_map<char, int> anagram_s;
        std::unordered_map<char, int> anagram_t;
        for (auto c : s)
        {
            if (anagram_s.count(c)) anagram_s[c]++;
            else anagram_s[c] = 1;
        }
        for (auto c : t)
        {
            if (anagram_s.count(c) == 0) return false;

            if (anagram_t.count(c)) anagram_t[c]++;
            else anagram_t[c] = 1;
        }
        for (auto pair : anagram_s)
        {
            if (anagram_t[pair.first] != pair.second) return false;
        }
        return true;
    }
};

int main()
{
    std::cout << Solution::isAnagram("anagram", "nagaram") << std::endl;
}