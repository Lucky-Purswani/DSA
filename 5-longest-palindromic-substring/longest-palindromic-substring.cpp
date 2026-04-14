class Solution {
public:
    string longestPalindrome(string s) {
        string ans;
        for(int i = 0; i<s.length(); i++){
            //odd length check
            int l = i;
            int r = i;
            while(l>=0 && r<s.length() && s[l] == s[r]){
                if(ans.length() < r-l+1) ans = s.substr(l, r-l+1);
                l--;
                r++;
            }
            //even length check
            l = i;
            r = i+1;
            while(l>=0 && r<s.length() && s[l] == s[r]){
                if(ans.length() < r-l+1) ans = s.substr(l, r-l+1);
                l--;
                r++;
            }
        }
        return ans;
    }
};