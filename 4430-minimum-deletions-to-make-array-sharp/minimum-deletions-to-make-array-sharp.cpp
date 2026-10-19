class Solution {
public:
    int minDeletions(vector<int>& nums) {
        int i = 0;
        int cnt = 1;
        for(int i = 0; i< nums.size()-1; i++){
            if(nums[i] == nums[i+1]){
                continue;
            }
            else{
                cnt++;
            }
        }

        return nums.size()-cnt;
    }
};