//Tabulation
class Solution {
public:
    int minDistance(string x, string y) {
        int m = x.length();
        int n = y.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));

        for(int i = 0; i<=m; i++) dp[i][0] = i;
        for(int j = 0; j<=n; j++) dp[0][j] = j;

        for(int i = 1; i<=m; i++){
            for(int j = 1; j<=n; j++){
                if(x[i-1] == y[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = 1+min(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        return dp[m][n];
    }
};


// //Recursion + Memoization
// class Solution {
// public:
//     int solve(string x, string y, int m, int n, vector<vector<int>> &dp){
//         if (m == 0) return n;
//         if (n == 0) return m;
//         if(dp[m][n] != -1) return dp[m][n];

//         if(x[m-1] == y[n-1]){
//             return dp[m][n] = solve(x, y, m-1, n-1, dp);
//         }
//         else{
//             return dp[m][n] = 1+min(solve(x, y, m-1, n, dp), solve(x, y, m, n-1, dp));
//         }
//     }
//     int minDistance(string x, string y) {
//         int m = x.length();
//         int n = y.length();
//         vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
//         int ans = solve(x, y, m, n, dp);
//         return ans;
//     }
// };