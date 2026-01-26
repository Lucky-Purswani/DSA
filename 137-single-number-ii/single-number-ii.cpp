class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0;
        int twos = 0;
        for(auto &i:nums){
            ones = (ones^i)&(~twos); //This means that this if this is not in two then we add it.
            // But if someone is already in one and then it will also get deleted as we do ones^i.
            // Same goes for twos. 
            // But we return ones as we want element that occurs only ones.
            twos = (twos^i)&(~ones);
        }
        
        return ones;
    }
};