class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int ans = 0;
        for(auto &i:nums){
            if(cnt == 0 || ans == i){
                ans = i;
                cnt++;
            }
            else{
                cnt--;
            }
        }
        return ans;
    }
};