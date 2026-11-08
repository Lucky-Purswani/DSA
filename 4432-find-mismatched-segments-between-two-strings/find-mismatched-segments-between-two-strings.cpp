class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        vector<vector<string>> ans;
        int n = s1.length();
        for(int i = 0; i<n; i++){
            string t1;
            string t2;
            if(s1[i] == s2[i]) continue;
            while(i < n && s1[i] != s2[i]){
                t1 += s1[i];
                t2 += s2[i];
                i++;
            }
            ans.push_back({t1, t2});
        }

        return ans;
    }
};