// This is for returning the super seq.
//Tabulation
class Solution {
public:

    string shortestCommonSupersequence(string a, string b) {
        int m = a.length(), n = b.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        // Build LCS table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (a[i-1] == b[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        // Build SCS using LCS table
        int i = m, j = n;
        string ans = "";
        while (i > 0 && j > 0) {
            if (a[i-1] == b[j-1]) {
                ans += a[i-1];
                i--; j--;
            }
            else if (dp[i-1][j] > dp[i][j-1]) {
                ans += a[i-1];
                i--;
            }
            else {
                ans += b[j-1];
                j--;
            }
        }


        while (i > 0) ans += a[--i];
        while (j > 0) ans += b[--j];

        reverse(ans.begin(), ans.end());
        return ans;
    }
};


// // This is for returning the len of the super seq.
// //DP
// class Solution {
// public:
//     int solve(string &a, string &b, int m, int n, vector<vector<int>> &dp) {
//         if (m == 0) return n;
//         if (n == 0) return m;

//         if (dp[m][n] != -1) return dp[m][n];

//         if (a[m-1] == b[n-1])
//             return dp[m][n] = 1 + solve(a, b, m-1, n-1, dp);

//         return dp[m][n] = 1 + min(solve(a, b, m-1, n, dp),
//                                   solve(a, b, m, n-1, dp));
//     }

//     string shortestCommonSupersequence(string a, string b) {
//         int m = a.length(), n = b.length();
//         vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
//         return solve(a, b, m, n, dp);
//     }
// };

//Recursion.
// This is for returning the len of the super seq.
// class Solution {
// public:
//     int solve(string x, string y, int m, int n){
//         if(m==0 || n==0) return 0;

//         if(x[m-1] == y[n-1]){
//             return 1+solve(x, y, m-1, n-1);
//         }
//         else{
//             return 1+min(solve(x, y, m-1, n), solve(x, y, m, n-1));
//         }
//     }
//     string shortestCommonSupersequence(string x, string y){
//         int m = x.length();
//         int n = y.length();
//         int ans = solve(x, y, m, n);
//         return ans;
//     }
// };