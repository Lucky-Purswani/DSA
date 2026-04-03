class Solution {
public:

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        int p = 0, np=0;
        for(int i = 1; i<n; i++){
            int p = nums[i];
            if(i-2>=0) p += dp[i-2];
            int np = dp[i-1];
            dp[i] = max(p, np);
        }
        return dp[n-1];
    }
};