class Solution {
public:
    bool isSafe(int row, int col, vector<string>& curr, int n) {
        int r = row;
        int c = col;

        // Upper-left diagonal
        while (r >= 0 && c >= 0) {
            if (curr[r][c] == 'Q') return false;
            r--;
            c--;
        }

        // Same column upwards
        r = row;
        c = col;
        while (r >= 0) {
            if (curr[r][c] == 'Q') return false;
            r--;
        }

        // Upper-right diagonal
        r = row;
        c = col;
        while (r >= 0 && c < n) {
            if (curr[r][c] == 'Q') return false;
            r--;
            c++;
        }

        return true;
    }

    void solve(vector<vector<string>> &ans, vector<string> &v, int n, int i){
        if(i == n){
            ans.push_back(v);
            return;
        } 

        for(int j = 0; j < n; j++){
            if(isSafe(i, j, v, n)){
                v[i][j] = 'Q';
                solve(ans, v, n, i+1);
                v[i][j] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> v(n, string(n, '.'));
        solve(ans, v, n, 0);
        return ans;
    }
};