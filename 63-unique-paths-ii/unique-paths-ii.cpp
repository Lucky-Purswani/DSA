class Solution {
public:
    int paths(vector<vector<int>>& mat, int m, int n, int i, int j, vector<vector<int>> &dp){
        if(i == m) return 0;
        if(j == n) return 0;
        if(mat[i][j] == 1) return 0;
        if(i == m-1 && j == n-1) return 1;

        if(dp[i][j] != -1) return dp[i][j];

        long long cnt = paths(mat, m, n, i+1, j, dp) + paths(mat, m, n, i, j+1, dp);

        return dp[i][j] = cnt;

    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1)); 
        return paths(obstacleGrid, m, n, 0, 0, dp);
    }
};