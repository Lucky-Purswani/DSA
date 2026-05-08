class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int s = 0;
        int e = n-1;
        int last = -1;
        while(s <= e){
            int m = s + (e-s)/2;
            if(nums[m] < target){
                s = m+1;
            }
            else if(nums[m] > target){
                e = m-1;
            }
            else{
                last = m;
                s = m+1;
            }
        }
        int first = -1;
        s = 0;
        e = n-1;
        while(s <= e){
            int m = s + (e-s)/2;
            if(nums[m] < target){
                s = m+1;
            }
            else if(nums[m] > target){
                e = m-1;
            }
            else{
                first = m;
                e = m-1;
            }
        }
        return {first, last};
    }
};