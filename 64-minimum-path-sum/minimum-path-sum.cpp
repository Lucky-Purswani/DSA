class Solution {
public:
    // int sum(vector<vector<int>>& a, int i, int j, vector<vector<int>> &dp){
    //     if(i < 0 || j < 0) return 1e9;
    //     if(i == 0 && j == 0) return a[i][j];
    //     if(dp[i][j] != -1) return dp[i][j];
    //     int u = a[i][j] + sum(a, i-1, j, dp);
    //     int l = a[i][j] + sum(a, i, j-1, dp);

    //     return dp[i][j] = min(u, l);
    // }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
        // int ans = sum(grid, grid.size()-1, grid[0].size()-1, dp);
        // return ans;


        dp[0][0] = grid[0][0];
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                if(i == 0 && j == 0) continue;
                int u = INT_MAX;
                int l = INT_MAX;
                if(i) u = grid[i][j] + dp[i-1][j];
                if(j) l = grid[i][j] + dp[i][j-1];
                dp[i][j] = min(u, l);
            }
        }
        return dp[grid.size()-1][grid[0].size()-1];
    }
};