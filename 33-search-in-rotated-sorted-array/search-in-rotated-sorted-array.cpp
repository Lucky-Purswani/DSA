class Solution {
public:
    int idx(vector<int> &nums, int s, int e, int key){
        if(s > e) return -1;

        int m = s + (e-s)/2;
        if(nums[m] == key) return m;

        //Left portion sorted
        if(nums[s] <= nums[m]){
            if(nums[s] <= key && key < nums[m]){
                return idx(nums, s, m-1, key);
            }
            else{
                return idx(nums, m+1, e, key);
            }
        }
        //Right portion is sorted.
        else{
            if(nums[m] < key && key <= nums[e]){
                return idx(nums, m+1, e, key);
            }
            else{
                return idx(nums, s, m-1, key);
            }
        }
    }
    int search(vector<int>& nums, int target) {
        return idx(nums, 0, nums.size()-1, target);
    }
};