class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        int n = nums.size();
        int s = 0;
        int e = n-1;
        int ans = INT_MIN;
        int idx = -1;
        while(s <= e){
            int m = s + (e-s)/2;
            if(m > 0 && m<n-1){
                if(nums[m] > nums[m-1] && nums[m] > nums[m+1]){
                    return m;
                }
                else if(nums[m] > nums[m+1]){
                    e = m-1;
                }
                else{
                    s = m+1;
                }
            }
            else{
                if(m == 0) return nums[0] > nums[1] ? 0 : 1;
                if(m == n-1) return nums[n-2] > nums[n-1] ? n-2 : n-1;
            }
        }
        return -1;
    }
};