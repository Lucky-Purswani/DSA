class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum = 0;
        int mn = INT_MAX;
        int n = 0;
        for(auto &i:nums){
            sum += i;
            mn = min(i, mn);
            n++;
        }
        int ans = 0;
        ans = sum - (mn*n);
        return ans;
    }
};