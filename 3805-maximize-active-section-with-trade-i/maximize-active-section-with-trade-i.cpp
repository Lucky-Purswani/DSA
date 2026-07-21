class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int prev = 0, curr = 0, mx = 0;
        int i = 0, n = s.size();

        while (i < n) {

            // Count current zero block
            curr = 0;
            while (i < n && s[i] == '0') {
                curr++;
                i++;
            }

            // Skip one block of ones
            while (i < n && s[i] == '1') {
                i++;
            }

            // If there was a previous zero block, combine them
            if (prev)
                mx = max(mx, prev + curr);

            // Current becomes previous for the next iteration
            prev = curr;
        }
        for(auto &i : s){
            if(i == '1') mx++;
        }
        return mx;
    }
};