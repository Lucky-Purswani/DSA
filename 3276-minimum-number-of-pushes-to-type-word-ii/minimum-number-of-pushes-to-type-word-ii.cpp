class Solution {
public:
    int minimumPushes(string word) {
        int res = 0;
        vector<int> freq(26, 0);

        for (char c : word) {
            freq[c - 'a']++;
        }

        sort(freq.begin(), freq.end(), greater<int>());

        for (int i = 0; i < 26 && freq[i] != 0; i++) {
            res += freq[i] * ((i / 8) + 1);
        }

        return res;
    }
};