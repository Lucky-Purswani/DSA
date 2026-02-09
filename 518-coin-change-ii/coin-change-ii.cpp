//Recursion + DP
class Solution {
public:
    int solve(vector<int> coins, int sum, int n, vector<vector<int>> &dp){
        if(sum == 0) return 1;
        if(n == 0) return 0;
        if(dp[n][sum] != -1) return dp[n][sum];
        if(sum >= coins[n-1]){
            int np = solve(coins, sum, n-1, dp);
            int p = solve(coins, sum-coins[n-1], n, dp);
            return dp[n][sum] = p+np;
        }
        else{
            int np = solve(coins, sum, n-1, dp);
            return dp[n][sum] = np;
        }
        
    }
    int change(int sum, vector<int>& coins) {
        if(sum == 0) return 1;
        vector<vector<int>> dp(coins.size()+1, vector<int>(sum+1, -1));
        int ans = solve(coins, sum, coins.size(), dp);
        return dp[coins.size()][sum];
    }
};