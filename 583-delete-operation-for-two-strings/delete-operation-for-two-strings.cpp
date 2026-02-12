//Space optimization
class Solution {
public:
    int minDistance(string x, string y) {
        int m = x.length();
        int n = y.length();
        vector<int> prev(n+1, 0);
        vector<int> curr(n+1, 0);

        for(int i = 0; i<=n; i++) prev[i] = i;
        for(int j = 0; j<=n; j++) curr[j] = j;

        for(int i = 1; i<=m; i++){
            curr[0] = i;
            for(int j = 1; j<=n; j++){
                if(x[i-1] == y[j-1]){
                    curr[j] = prev[j-1];
                }
                else{
                    curr[j] = 1+min(curr[j-1], prev[j]);
                }
            }
            prev = curr;
        }
        return curr[n];
    }
};


// //Tabulation
// class Solution {
// public:
//     int minDistance(string x, string y) {
//         int m = x.length();
//         int n = y.length();
//         vector<vector<int>> dp(m+1, vector<int>(n+1, -1));

//         for(int i = 0; i<=m; i++) dp[i][0] = i;
//         for(int j = 0; j<=n; j++) dp[0][j] = j;

//         for(int i = 1; i<=m; i++){
//             for(int j = 1; j<=n; j++){
//                 if(x[i-1] == y[j-1]){
//                     dp[i][j] = dp[i-1][j-1];
//                 }
//                 else{
//                     dp[i][j] = 1+min(dp[i][j-1], dp[i-1][j]);
//                 }
//             }
//         }
//         //For printing the string
//         // string result = "";
//         // int i = m, j = n;

//         // while(i > 0 && j > 0){
//         //     if(x[i-1] == y[j-1]){
//         //         result.push_back(x[i-1]);
//         //         i--;
//         //         j--;
//         //     }
//         //     else{
//         //         if(dp[i-1][j] < dp[i][j-1])
//         //             i--;
//         //         else
//         //             j--;
//         //     }
//         // }

//         // reverse(result.begin(), result.end());
//         // cout << result << endl;
//         // return result;



//         return dp[m][n];
//     }
// };


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