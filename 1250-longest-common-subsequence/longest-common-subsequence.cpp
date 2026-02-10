class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        //No need of initialization loops as we want 0 so we have 0.

        for(int i = 1; i<=m; i++){
            for(int j = 1; j<=n; j++){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};
// class Solution {
// public:
//     int solve(string &x, string &y, int m, int n, vector<vector<int>> &dp){
//         if(m==0 || n==0) return 0;
//         if(dp[m][n] != -1) return dp[m][n];
//         if(x[m-1] == y[n-1]){
//             return dp[m][n] = 1+solve(x, y, m-1, n-1, dp);
//         }
//         else{
//             return dp[m][n] = max(solve(x, y, m-1, n, dp), solve(x, y, m, n-1, dp));
//         }
//     }
//     int longestCommonSubsequence(string text1, string text2) {
//         int m = text1.length();
//         int n = text2.length();
//         vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
//         return solve(text1, text2, m, n, dp);
//     }
// };