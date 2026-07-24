class Solution {
  public:
    int sum(vector<vector<int>>& grid, int i, int j, vector<vector<int>> &dp){
        if(i == grid.size()-1)
            return grid[i][j];

        if(dp[i][j] != 1e9)
            return dp[i][j];

        int down = grid[i][j] + sum(grid, i+1, j, dp);
        int diag = grid[i][j] + sum(grid, i+1, j+1, dp);

        return dp[i][j] = min(down, diag);
    }
    int minimumTotal(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[n-1].size();
        vector<vector<int>> dp(n, vector<int>(m, 1e9));
        return sum(grid, 0, 0, dp);
    }
};





// class Solution {
//   public:
//     // int sum(vector<vector<int>>& a, int i, int j, vector<vector<int>> &dp){
//     //     if(i >= a.size() || j >= a.size()) return 1e9;
//     //     if(i == a.size()-1) return a[i][j];
//     //     if(dp[i][j] != -1) return dp[i][j];
//     //     int u = a[i][j] + sum(a, i+1, j, dp);
//     //     int l = a[i][j] + sum(a, i+1, j+1, dp);
//     //     return dp[i][j] = min(u, l);
//     // }
//     int minimumTotal(vector<vector<int>>& grid) {
//         vector<vector<int>> dp(grid.size(), vector<int>(grid.size(), 1e9));
//         // int ans = sum(grid, 0, 0, dp);
//         // return ans;

//         dp[0][0] = grid[0][0];
//         for(int i = 1; i<grid.size(); i++){
//             for(int j = 0; j<grid[i].size(); j++){
//                 int u = INT_MAX;
//                 int l = INT_MAX;
//                 if(i>0) u = grid[i][j] + dp[i-1][j];
//                 if(j>0) l = grid[i][j] + dp[i-1][j-1];
//                 dp[i][j] = min(u, l);
//             }
//         }
//         int ans = INT_MAX;
//         for(auto &i: dp[grid.size()-1]){
//             ans = min(ans,i);
//         }
//         return ans;
//     }
// };