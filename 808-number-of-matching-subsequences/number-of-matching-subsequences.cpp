class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<pair<string,int>>> bucket(26);
        
        // Put words in bucket of their first char
        for (auto &w : words) {
            bucket[w[0] - 'a'].push_back({w, 0});
        }

        int ans = 0;

        for (char c : s) {
            auto current = bucket[c - 'a'];
            bucket[c - 'a'].clear();

            for (auto &p : current) {
                p.second++; // move pointer

                if (p.second == p.first.size()) {
                    ans++;
                } else {
                    bucket[p.first[p.second] - 'a'].push_back(p);
                }
            }
        }

        return ans;
    }
};
