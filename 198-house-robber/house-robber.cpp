class Solution {
public:
    int sum(vector<int> &a, int i, vector<int> &dp){
        if(i < 0) return 0;
        if(i == 0) return a[i];
        if(dp[i] != -1) return dp[i];
        int p = a[i] + sum(a, i-2, dp);
        int np = sum(a, i-1, dp);
        
        return dp[i] = max(p, np);
        
    }

    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        int ans = sum(nums, nums.size()-1, dp);
        return ans;
    }
};