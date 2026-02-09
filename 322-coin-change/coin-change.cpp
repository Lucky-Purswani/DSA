// class Solution {
// public:
//     int coinChange(vector<int>& coins, int amount) {
//         if(amount == 0) return 0;
//         vector<int> prev(sum+1, 0);
//         vector<int> curr(sum+1, 0);

//         for(int j = 0; j<=amount; j++){
//             dp[0][j] = 1e9;
//         }
        
//         for(int i = 1; i<dp.size(); i++){
//             for(int j = 1; j<dp[0].size(); j++){
//                 if(j >= coins[i-1]){
//                     int np = dp[i-1][j];
//                     int p = 1+dp[i][j-coins[i-1]];
//                     dp[i][j] = min(p,np);
//                 }
//                 else{
//                     int np = dp[i-1][j];
//                     dp[i][j] = np;
//                 }
//             }
//         }
//         return dp[coins.size()][amount] == 1e9 ? -1 : dp[coins.size()][amount];
//     }
// };
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1, 0));

        for(int j = 1; j<=amount; j++){
            dp[0][j] = 1e9;
        }
        
        for(int i = 1; i<dp.size(); i++){
            for(int j = 1; j<dp[0].size(); j++){
                if(j >= coins[i-1]){
                    int np = dp[i-1][j];
                    int p = 1+dp[i][j-coins[i-1]];
                    dp[i][j] = min(p,np);
                }
                else{
                    int np = dp[i-1][j];
                    dp[i][j] = np;
                }
            }
        }
        return dp[coins.size()][amount] == 1e9 ? -1 : dp[coins.size()][amount];
    }
};
// class Solution {
// public:
//     int solve(vector<int> coins, int amount, int n, vector<vector<int>> &dp){
//         if(amount == 0) return 0;
//         if(n == 0) return 1e9;
//         if(dp[n][amount] != -1) return dp[n][amount];
//         if(amount >= coins[n-1]){
//             int np = solve(coins, amount, n-1, dp);
//             int p = 1+solve(coins, amount-coins[n-1], n, dp);
//             return dp[n][amount] = min(np, p);
//         }
//         else{
//             int np = solve(coins, amount, n-1, dp);
//             return dp[n][amount] = np;
//         }
//     }
//     int coinChange(vector<int>& coins, int amount) {
//         if(amount == 0) return 0;
//         vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1, -1));
//         int ans = solve(coins, amount, coins.size(), dp);
//         return dp[coins.size()][amount] == 1e9 ? -1 : dp[coins.size()][amount];
//     }
// };
// class Solution {
// public:
//     int solve(vector<int> coins, int amount, int n, vector<vector<int>> &dp){
//         if(amount == 0) return 0;
//         if(n == 0) return 1e9;

//         if(amount >= coins[n-1]){
//             int np = solve(coins, amount, n-1, dp);
//             int p = 1+solve(coins, amount-coins[n-1], n, dp);
//             return min(np, p);
//         }
//         else{
//             int np = solve(coins, amount, n-1, dp);
//             return np;
//         }
//     }
//     int coinChange(vector<int>& coins, int amount) {
//         vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1, -1));
//         int ans = solve(coins, amount, coins.size(), dp);
//         return ans == 1e9 ? -1 : ans;
//     }
// };