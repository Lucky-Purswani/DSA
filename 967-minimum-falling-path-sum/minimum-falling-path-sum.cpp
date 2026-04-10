class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 0));

        // base case (first row)
        for(int j = 0; j < m; j++){
            dp[0][j] = grid[0][j];
        }

        // fill top → bottom
        for(int i = 1; i < n; i++){
            for(int j = 0; j < m; j++){

                int up = dp[i-1][j];
                int dl = (j > 0) ? dp[i-1][j-1] : 1e9;
                int dr = (j < m-1) ? dp[i-1][j+1] : 1e9;

                dp[i][j] = grid[i][j] + min({up, dl, dr});
            }
        }

        // answer = min in last row
        int ans = INT_MAX;
        for(int j = 0; j < m; j++){
            ans = min(ans, dp[n-1][j]);
        }

        return ans;
    }
};