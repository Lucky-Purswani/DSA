// class Solution {
// public:
//     bool isPalindrome(string s, int ind, int i){
//         while (ind < i) {
//             if (s[ind] != s[i]) {
//                 return false;
//             }
//             ind++;
//             i--;
//         }
//         return true;
//     }
//     int solve(string s, int i, int j){
//         if(i>=j || isPalindrome(s, i, j)){
//             return 0;
//         }
//         for(int k=i; k<j; k++){
//             int temp = solve(s, i, k) + solve(s, k+1, j) + 1;
//             ans = min(ans, temp);
//         }
//     }

//     vector<vector<string>> partition(string s) {
//         return solve(s, i, j);
//     }
// };

class Solution {
public:
    bool isPalindrome(string s, int ind, int i){
        while (ind < i) {
            if (s[ind] != s[i]) {
                return false;
            }
            ind++;
            i--;
        }
        return true;
    }
    void solve(string s, vector<vector<string>> &ans, vector<string>& curr, int ind){
        if(ind == s.size()){
            ans.emplace_back(curr);
            return;
        }

        for(int i = ind; i<s.size(); i++){
            if(isPalindrome(s, ind, i)){
                curr.emplace_back(s.substr(ind, i - ind + 1));
                solve(s, ans, curr, i+1);
                curr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        solve(s, ans, curr, 0);
        return ans;
    }
};