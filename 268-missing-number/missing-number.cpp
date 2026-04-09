class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i = 0;
        int n = nums.size();
        while(i < n){
            int corr = nums[i];
            if(corr >= 0 && corr<n && nums[i] != nums[corr]){
                swap(nums[corr], nums[i]);
            }
            else{
                i++;
            }
        }
        // cout >> nums;
        // for(int i = 0; i<n; i++){
        //     cout << nums[i] << endl;
        // }
        for(int i = 0; i<n; i++){
            if(i != nums[i]) return i;
        }
        return n;
    }
};