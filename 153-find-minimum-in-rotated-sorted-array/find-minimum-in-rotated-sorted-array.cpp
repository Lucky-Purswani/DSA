class Solution {
public:
    int smallest(vector<int> &nums, int s, int e,  int &idx){
        if(s > e) return idx;

        int m = s + (e-s)/2;
        if(nums[m] >= nums[s]){
            if(idx == -1 || nums[idx] > nums[s])idx = s;
            return smallest(nums, m+1, e, idx);
        }
        else{
            if(idx == -1 || nums[idx] > nums[m])idx = m;
            return smallest(nums, s, m-1, idx);
        }
    }
    int findMin(vector<int>& nums) {
        int i = -1;
        int idx = smallest(nums, 0, nums.size()-1, i);
        return nums[idx];
    }
};
// class Solution {
// public:
//     int findMin(vector<int>& nums) {
//         int n = nums.size();
//         int s = 0;
//         int e = n-1;
//         int idx = 0;
//         int ans = INT_MAX;
//         while(s <= e){
//             int m = s + (e-s)/2;
//             if(nums[m] >= nums[s]){
//                 //left one is sorted
//                 ans = min(ans, nums[s]);
//                 idx = s;
//                 s = m+1;
//             }
//             else{
//                 idx = m;
//                 ans = min(ans, nums[m]);
//                 e = m-1;
//             }
//         }
//         return ans;
//     }
// };