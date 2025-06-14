# include <iostream>
# include <string>

class Solution {
public:
    static std::string mergeAlternately(const std::string& word1, const std::string& word2) {
        std::string result;
        int index_1 = 0;
        int index_2 = 0;

        for (int i = 0; i < (word1 + word2).length(); i++)
        {
              if (index_1 >= word1.length())
              {
                 result += word2[index_2];
                 index_2++;
              }
              else if (index_2 >= word2.length())
              {
                  result += word1[index_1];
                  index_1++;
              }
              else if (index_1 > index_2)
              {
                  result += word2[index_2];
                  index_2++;
              }
              else
              {
                  result += word1[index_1];
                  index_1++;
              }
        }
            return result;
    }
};

int main() {
    std::cout << Solution::mergeAlternately("ab", "xyz") << std::endl;
    return 0;
}