#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    static vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        vector<string> answers;
        answers.reserve(queries.size());

        unordered_set<string> exact;
        map<string, string> lower_map;
        map<string, string> devowel_map;

        for (const string& word : wordlist)
        {
            exact.insert(word);
            string lower = to_lower(word);
            if (lower_map.find(lower) == lower_map.end()) lower_map[lower] = word;
            string devowel = to_devowel(lower);
            if (devowel_map.find(devowel) == devowel_map.end()) devowel_map[devowel] = word;
        }


        for (const string& query : queries)
        {
            if (exact.count(query))
            {
                answers.push_back(query);
                continue;
            }

            string lower = to_lower(query);
            auto it_lower = lower_map.find(lower);
            if (it_lower != lower_map.end())
            {
                answers.push_back(it_lower->second);
                continue;
            }

            string devowel = to_devowel(lower);
            auto it = devowel_map.find(devowel);
            if (it != devowel_map.end()) answers.push_back(it->second);
            else answers.emplace_back("");
        }

        return answers;
    }

private:
    static string to_devowel(const string& s)
    {
        string result = s;
        for (char &c : result) if (is_vowel(c)) c = '*';
        return result;
    }

    static bool is_vowel(char c)
    {
        unsigned char lower = tolower(static_cast<unsigned char>(c));
        return lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u';
    }

    static string to_lower(const string& s)
    {
        string result = s;
        transform(result.begin(), result.end(), result.begin(),
            [](unsigned char c){return tolower(c);});
        return result;
    }
};

int main() {
    vector<string> wordlist = {"KiTe","kite","hare","Hare"};
    vector<string> queries  = {"kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"};

    vector<string> results = Solution::spellchecker(wordlist, queries);

    cout << "Resultados:\n";
    for (int i = 0; i < queries.size(); i++) {
        cout << "Query: " << queries[i] << " -> Resposta: " << results[i] << "\n";
    }

    return 0;
}