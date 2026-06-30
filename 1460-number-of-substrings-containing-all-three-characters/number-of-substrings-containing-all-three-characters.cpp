class Solution {
public:
    int numberOfSubstrings(string s) {
        int l = 0;
        int r = 0;
        int ans = 0;
        unordered_map<char, int> mp;
        while(r < s.size()){
            mp[s[r]]++;
            while(mp['a'] && mp['b'] && mp['c']){
                ans += s.size() - r;
                mp[s[l]]--;
                l++;
            }
            r++;
        }
        return ans;
    }
};

//Brute force
// class Solution {
// public:
//     int numberOfSubstrings(string s) {
//         int ans=0;
//         for(int i = 0; i<s.size(); i++){
//             unordered_map<char, int> mp;
//             for(int j = i; j<s.size(); j++){
//                 mp[s[j]]++;
//                 if(mp['a'] && mp['b'] && mp['c']) ans++;
//             }
//         }
//         return ans;
//     }
// };