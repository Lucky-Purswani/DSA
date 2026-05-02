class Solution {
public:
    string removeKdigits(string s, int k) {
        if(k==s.length()) return "0";
        stack<char> st;
        for(int i =0; i<s.length(); i++){
            while(!st.empty() && k>0 && ((st.top()-'0') > (s[i]-'0'))){
                st.pop();
                k--;
            }
            st.push(s[i]);
        }
        while(k > 0 && !st.empty()) {
            st.pop();
            k--;
        }


        string res = "";
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        while(!res.empty() && res.back() == '0' ){
            res.pop_back();
        }
        reverse(res.begin(), res.end());
        if(res.empty()) return "0";
        return res;
    }
};