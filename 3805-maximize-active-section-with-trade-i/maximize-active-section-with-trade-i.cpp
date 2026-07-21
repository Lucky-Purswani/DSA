class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int prev = 0, curr = 0, mx = 0;
        int i = 0, n = s.size();

        while(i < n){
            //count number of 0's
            while(i < n && s[i] == '0'){
                curr++;
                i++;
            }

            //Skip 1's
            while(i<n && s[i] == '1'){
                i++;
            }

            //mx update condition
            if(curr && prev){
                mx = max(mx, prev+curr);
            }
            
            prev = curr;
            curr = 0;
        }

        for(auto &i:s){
            if(i=='1') mx++;
        }
        return mx;
    }
};