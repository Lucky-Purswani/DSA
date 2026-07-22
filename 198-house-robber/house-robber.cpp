class Solution {
public:
    int solve(vector<int>& nums, int i, vector<int>& dp){
        if(i >= nums.size()) return 0;
        if(dp[i] != -1) return dp[i];

        int pick = nums[i] + solve(nums, i + 2, dp);
        int notPick = solve(nums, i + 1, dp);

        return dp[i] = max(pick, notPick);
    }

    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return solve(nums, 0, dp);
    }
};





// class Solution {
// public:

//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> dp(n, 0);
//         dp[0] = nums[0];
//         int p = 0, np=0;
//         for(int i = 1; i<n; i++){
//             int p = nums[i];
//             if(i-2>=0) p += dp[i-2];
//             int np = dp[i-1];
//             dp[i] = max(p, np);
//         }
//         return dp[n-1];
//     }
// };