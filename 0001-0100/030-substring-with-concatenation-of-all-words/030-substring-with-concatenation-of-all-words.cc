#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        const int nw = words.size();
        const int word_len = words[0].size();
        int ls = s.size();

        vector<int> res;
        for (int i = 0; i < word_len && i <= ls - nw * word_len; ++i) {
            unordered_map<string, int> diff;
            for (int j = 0; j < nw; ++j) {
                ++diff[s.substr(i + j * word_len, word_len)];
            }

            for (const auto word : words) {
                if (--diff[word] == 0) diff.erase(word);
            }

            for (int k = i; k <= ls - nw * word_len; k += word_len) {
                if (k != i) {
                    string word(s, k + (nw - 1) * word_len, word_len);
                    if (++diff[word] == 0) diff.erase(word);
                    word = string(s, k - word_len, word_len);
                    if (--diff[word] == 0) diff.erase(word);
                }
                if (diff.empty()) res.emplace_back(k);
            }
       
        }
        return res;
    }
};

int main() {
    Solution s;
    string str = "barfoothefoobarman";
    vector<string> words = {"foo", "bar"};
    vector<int> res = s.findSubstring(str, words);
    for (auto i : res) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}