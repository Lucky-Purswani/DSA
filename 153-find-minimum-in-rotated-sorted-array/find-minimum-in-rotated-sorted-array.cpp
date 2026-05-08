class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int s = 0;
        int e = n-1;
        int idx = 0;
        int ans = INT_MAX;
        while(s <= e){
            int m = s + (e-s)/2;
            if(nums[m] >= nums[s]){
                //left one is sorted
                ans = min(ans, nums[s]);
                idx = s;
                s = m+1;
            }
            else{
                idx = m;
                ans = min(ans, nums[m]);
                e = m-1;
            }
        }
        return ans;
    }
};