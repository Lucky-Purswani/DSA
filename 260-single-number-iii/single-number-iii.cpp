class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // vector<int> ans;
        int xo = 0;
        for(auto &i : nums){
            xo ^= i;
        }
        int diff_bit = 1;
        int a = 0, b = 0;
        while((xo & diff_bit) == 0){
            diff_bit <<= 1;
        }
        //Or instead of while loop
        // diff_bit = (xo & (xo-1)) ^ xo;

        for(auto &i : nums){
            if((diff_bit & i) == 0) b ^= i;
            else a ^= i;
        }
        return {a, b};
    }
};