class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        int len = 0;
        string ans;
        for(auto &w:strs){
            if(w.size() > len){
                len = w.size();
                ans = w;
            }
        }
        for(int i = 0; i < len; i++){
            char ch = strs[0][i];

            for(int j = 1; j < strs.size(); j++){
                // mismatch or string ended
                if(strs[j][i] != ch){
                    return strs[0].substr(0, i);
                }
            }
        }

        return ans;
    }
};