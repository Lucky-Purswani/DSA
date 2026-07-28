class Solution {
public:
    
    string smallestPalindrome(string s) {
        if(s.length() <= 1) return s;
        int n = s.length();
        sort(s.begin(), s.begin()+n/2);
        if(n%2==0){
            sort(s.begin()+n/2, s.end());
            reverse(s.begin()+n/2, s.end());
        } 
        else{
            sort(s.begin()+n/2+1, s.end());
            reverse(s.begin()+n/2+1, s.end());
        } 
        return s;
    }
};