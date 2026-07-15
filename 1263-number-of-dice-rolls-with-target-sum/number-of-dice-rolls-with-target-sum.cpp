class Solution {
public:
    const int MOD = 1e9 + 7;
    int solve(int n, int k, int target, int sum, vector<vector<long long>> &dp) {
        if (n == 0) {
            return (sum == target) ? 1 : 0;
        }
        if (sum > target) return 0;
        if(dp[n][sum] != -1) return dp[n][sum];
        long long cnt = 0;
        for (int j = 1; j <= k; j++) {
            cnt = (cnt + solve(n - 1, k, target, sum + j, dp)) % MOD;
        }

        return dp[n][sum] = cnt;
    }

    int numRollsToTarget(int n, int k, int target) {
        // if(n == 30) return 0;
        vector<vector<long long>> dp(n+1, vector<long long>(target+1, -1));
        return solve(n, k, target, 0, dp);
    }
};