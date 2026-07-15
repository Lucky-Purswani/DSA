class Solution {
public:
    vector<string> ans;
    void solve(string d, int i, unordered_map<char, string> &mp, string temp){
        if(i == d.length()) {
            ans.push_back(temp);
            return;
        }

        string atI = mp[d[i]]; //"abc"
        for(int j = 0; j<atI.length(); j++){
            solve(d, i+1, mp, temp+atI[j]);
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        unordered_map<char, string> mp = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        solve(digits, 0, mp, "");
        return ans;
    }
};