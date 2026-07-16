class Solution {
public:
    int paths(int m, int n, int i, int j, vector<vector<int>> &dp){
        if(i == m) return 0;
        if(j == n) return 0;
        if(i == m-1 && j == n-1) return 1;

        if(dp[i][j] != -1) return dp[i][j];

        long long cnt = paths(m, n, i+1, j, dp) + paths(m, n, i, j+1, dp);

        return dp[i][j] = cnt;

    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1)); 
        return paths(m, n, 0, 0, dp);
    }
};






// class Solution {
// public:
//     int paths(int m, int n, vector<vector<int>> &dp){
//         if(m == 0 && n == 0) return 1;
//         if(m < 0 || n < 0) return 0;

//         if(dp[m][n] != -1) return dp[m][n];

//         return dp[m][n] = paths(m-1, n, dp) + paths(m, n-1, dp);
//     }

//     int uniquePaths(int m, int n) {
//         vector<vector<int>> dp(m, vector<int>(n, -1));
//         // return paths(m-1, n-1, dp);
//         dp[0][0] = 1;
//         for(int i = 0; i<m; i++){
//             for(int j = 0; j<n; j++){
//                 if(i==0 && j==0) continue;
//                 int up = (i > 0) ? dp[i-1][j] : 0;
//                 int left = (j > 0) ? dp[i][j-1] : 0;

//                 dp[i][j] = up + left;
//             }
//         }
//         return dp[m-1][n-1];
//     }
// };