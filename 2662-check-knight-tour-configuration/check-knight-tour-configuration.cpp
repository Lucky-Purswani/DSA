class Solution {
public:
    bool solve(vector<vector<int>> &ans, int i, int j, int n, int cnt) {
        if(cnt == n*n-1) return true;
        // 8 possible knight moves

        if (i + 2 < n && j + 1 < n && ans[i + 2][j + 1] == cnt + 1)
            return solve(ans, i + 2, j + 1, n, cnt + 1);

        if (i + 2 < n && j - 1 >= 0 && ans[i + 2][j - 1] == cnt + 1)
            return solve(ans, i + 2, j - 1, n, cnt + 1);

        if (i - 2 >= 0 && j + 1 < n && ans[i - 2][j + 1] == cnt + 1)
            return solve(ans, i - 2, j + 1, n, cnt + 1);

        if (i - 2 >= 0 && j - 1 >= 0 && ans[i - 2][j - 1] == cnt + 1)
            return solve(ans, i - 2, j - 1, n, cnt + 1);

        if (i + 1 < n && j + 2 < n && ans[i + 1][j + 2] == cnt + 1)
            return solve(ans, i + 1, j + 2, n, cnt + 1);

        if (i + 1 < n && j - 2 >= 0 && ans[i + 1][j - 2] == cnt + 1)
            return solve(ans, i + 1, j - 2, n, cnt + 1);

        if (i - 1 >= 0 && j + 2 < n && ans[i - 1][j + 2] == cnt + 1)
            return solve(ans, i - 1, j + 2, n, cnt + 1);

        if (i - 1 >= 0 && j - 2 >= 0 && ans[i - 1][j - 2] == cnt + 1)
            return solve(ans, i - 1, j - 2, n, cnt + 1);

        return false;
    }

    bool checkValidGrid(vector<vector<int>>& grid) {
        if(grid[0][0] != 0) return false;
        int n = grid.size();
        return solve(grid, 0, 0, n, 0);
    }
};