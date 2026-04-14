class Solution {
public:
    void reverseH(string &s){
        if(s.length() <= 1) return;
        int i = 0;
        int j = s.length()-1;
        while(i < j){
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
    string trim(string s) {
        int i = 0;
        int j = s.length() - 1;

        // move i forward (skip leading spaces)
        while(i <= j && s[i] == ' ') i++;

        // move j backward (skip trailing spaces)
        while(j >= i && s[j] == ' ') j--;

        // if string is all spaces
        if(i > j) return "";

        // return trimmed substring
        return s.substr(i, j - i + 1);
    }

    string reverseWords(string s) {
        string ans;
        string temp = "";
        for(int i = 0; i<s.length(); i++){
            if(s[i] == ' '){
                reverseH(temp);
                ans += trim(temp);
                if(temp.length()) ans += ' ';
                temp = "";
                continue;
            }
            else{
                temp += s[i];
            }
        }
        reverseH(temp);
        ans += trim(temp);
        ans = trim(ans);
        reverseH(ans);
        return ans;
    }
};