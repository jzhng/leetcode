class Solution {
    unordered_map<string, map<string, int>> targets;
    
    bool backtracking(int ticketNum, vector<string> &res) {
        if (res.size() == ticketNum + 1) {
            return true;
        }

        for (auto &target: targets[res.back()]) {
            if (target.second > 0) {
                res.push_back(target.first);
                --target.second;
                if (backtracking(ticketNum, res)) return true;
                ++target.second;
                res.pop_back();
            }
        }
        return false;
    }

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> res;

        for (const auto &ticket: tickets) {
            ++targets[ticket[0]][ticket[1]];
        }

        res.push_back("JFK");
        backtracking(tickets.size(), res);
        return res;
    }
};