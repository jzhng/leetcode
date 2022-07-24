#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class ValidWordAbbr {
    unordered_map<string, unordered_set<string>> mp;

    string abbr(string word) {
        int n = word.size();
        if (n <= 2) return word;

        return word[0] + to_string(n-2) + word[n-1];
    }
public:
    ValidWordAbbr(vector<string>& dictionary) {
        for (auto &word: dictionary) {
            mp[abbr(word)].insert(word);
        }
    }
    
    bool isUnique(string word) {
        string s = abbr(word);
        return mp.find(s) == mp.end() || (mp[s].size() == 1 && *mp[s].begin() == word);
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr* obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj->isUnique(word);
 */

int main() {
    vector<string> dictionary = {"deer", "door", "cake", "card"};
    ValidWordAbbr* obj = new ValidWordAbbr(dictionary);
    cout << obj->isUnique("dear") << endl;
    cout << obj->isUnique("door") << endl;
    cout << obj->isUnique("cart") << endl;
    cout << obj->isUnique("cake") << endl;
    return 0;
}
