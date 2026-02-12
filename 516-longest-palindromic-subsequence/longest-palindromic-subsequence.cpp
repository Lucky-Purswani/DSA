class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string x = s;
        reverse(s.begin(), s.end());
        string y = s;
        int m = x.length();
        int n = y.length();
        vector<int> prev(n+1, 0);
        vector<int> curr(n+1, 0);
        
        //No need of initialization of prev or curr as we want 0 so we have 0.

        for(int i = 1; i<=m; i++){
            for(int j = 1; j<=n; j++){
                if(x[i-1] == y[j-1]){
                    curr[j] = 1+prev[j-1];
                }
                else{
                    curr[j] = max(prev[j], curr[j-1]);
                }
            }
            prev = curr;
        }
        return prev[n];
    }
};