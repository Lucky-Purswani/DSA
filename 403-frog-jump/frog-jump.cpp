class Solution {
public:
    bool cross(vector<int>& stones, int i, int k, unordered_map<int, int> &mp, vector<vector<int>> &dp){
        if(i == stones.size() - 1) return true;

        if(dp[i][k] != -1) return dp[i][k];

        bool km1 = false, k0 = false, kp1 = false;

        // k-1 jump
        if(k-1 > 0){
            if(mp.find(stones[i]+k-1) != mp.end()){
                km1 = cross(stones, mp[stones[i]+k-1], k-1, mp, dp);
            }
        }

        // k jump
        if(k > 0){
            if(mp.find(stones[i]+k) != mp.end()){
                k0 = cross(stones, mp[stones[i]+k], k, mp, dp);
            }
        }

        // k+1 jump
        if(mp.find(stones[i]+k+1) != mp.end()){
            kp1 = cross(stones, mp[stones[i]+k+1], k+1, mp, dp);
        }

        return dp[i][k] = km1 || k0 || kp1;
    }

    bool canCross(vector<int>& stones) {
        vector<vector<int>> dp(stones.size(), vector<int>(stones.size(), -1));
        unordered_map<int, int> mp;
        for(int i = 0; i<stones.size(); i++){
            mp[stones[i]] = i;
        }
        return cross(stones, 0, 0, mp, dp);
    }
};