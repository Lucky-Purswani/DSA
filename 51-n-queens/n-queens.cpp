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









// class Solution {
// public:
//     bool isSafe(int row,int col, vector<string>& curr, int n){
//         int r = row;
//         int c = col;
//         while(c >= 0 && r >= 0){
//             if(curr[r][c] == 'Q') return false;
//             r--;
//             c--;
//         }
//         r = row;
//         c = col;
//         while(c >= 0){
//             if(curr[r][c] == 'Q') return false;
//             c--;
//         }
//         r = row;
//         c = col;
//         while(c >= 0 && r < n){
//             if(curr[r][c] == 'Q') return false;
//             r++;
//             c--;
//         }
//         return true;
//     }


//     void solve(int n, vector<vector<string>>& ans, int col, vector<string> &curr){
//         if(col == n){
//             ans.emplace_back(curr);
//             return;
//         }
//         for(int r = 0; r<n; r++){
//             if(isSafe(r, col, curr, n)){
//                 curr[r][col] = 'Q';
//                 solve(n, ans, col+1, curr);
//                 curr[r][col] = '.';
//             }
//         }
//     }

//     vector<vector<string>> solveNQueens(int n) {
//         vector<vector<string>> ans;
//         vector<string> curr(n, string(n, '.'));
//         solve(n, ans, 0, curr);
//         return ans;
//     }
// };