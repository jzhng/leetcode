class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string s = to_string(n);

        int idx = s.size();
        for (int i = s.size() - 1; i > 0; --i) {
            if (s[i-1] > s[i]) {
                idx = i;
                --s[i-1];
            }
        }

        for (int i = idx; i < s.size(); ++i) {
            s[i] = '9';
        }
        
        return stoi(s);
    }
};
