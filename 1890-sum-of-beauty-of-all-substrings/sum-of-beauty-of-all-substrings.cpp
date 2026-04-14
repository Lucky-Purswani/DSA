// class Solution {
// public:
//     int beauty(string s){
//         if(s.length() <= 1) return 0;
//         unordered_map<char, int> mp;
//         for(auto &ch: s){
//             mp[ch]++;
//         }
//         int mn = INT_MAX;
//         int mx = INT_MIN;
//         for(auto &p: mp){
//             mn = min(mn, p.second);
//             mx = max(mx, p.second);
//         }
//         return mx-mn;
//     }
//     int beautySum(string s) {
//         int sum = 0;
//         for(int i = 0; i<s.length(); i++){
//             for(int j = i; j<s.length(); j++){
//                 sum += beauty(s.substr(i, j-i+1));
//             }
//         }
//         return sum;
//     }
// };
class Solution {
public:

    int getMaxCount(vector<int>& freq) {
        int maxCount = 0;
        for(int i = 0; i < 26; i++) {
            maxCount = max(maxCount, freq[i]);
        }
        return maxCount;
    }

    int getMinCount(vector<int>& freq) {
        int minCount = INT_MAX;
        for(int i = 0; i < 26; i++) {
            if(freq[i] > 0) { // ignore zero freq
                minCount = min(minCount, freq[i]);
            }
        }
        return minCount;
    }

    int beautySum(string s) {
        int sum = 0;

        for(int i = 0; i < s.length(); i++) {
            vector<int> freq(26, 0);

            for(int j = i; j < s.length(); j++) {
                freq[s[j] - 'a']++;

                int beauty = getMaxCount(freq) - getMinCount(freq);
                sum += beauty;
            }
        }

        return sum;
    }
};