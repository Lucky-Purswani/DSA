class Solution {
public:
    bool isSafe(int row,int col, vector<string>& curr, int n){
        int r = row;
        int c = col;
        while(c >= 0 && r >= 0){
            if(curr[r][c] == 'Q') return false;
            r--;
            c--;
        }
        r = row;
        c = col;
        while(c >= 0){
            if(curr[r][c] == 'Q') return false;
            c--;
        }
        r = row;
        c = col;
        while(c >= 0 && r < n){
            if(curr[r][c] == 'Q') return false;
            r++;
            c--;
        }
        return true;
    }


    void solve(int n, vector<vector<string>>& ans, int col, vector<string> &curr){
        if(col == n){
            ans.emplace_back(curr);
            return;
        }
        for(int r = 0; r<n; r++){
            if(isSafe(r, col, curr, n)){
                curr[r][col] = 'Q';
                solve(n, ans, col+1, curr);
                curr[r][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> curr(n, string(n, '.'));
        solve(n, ans, 0, curr);
        return ans;
    }
};