class Solution {
public:

    long long hoursNeeded(vector<int>& nums, int speed){

        long long total = 0;

        for(auto &i : nums){
            total += ceil((double)i / speed);
        }

        return total;
    }

    int minEatingSpeed(vector<int>& nums, int h) {

        int s = 1;
        int e = *max_element(nums.begin(), nums.end());

        int ans = e;

        while(s <= e){

            int mid = s + (e - s) / 2;

            long long hours = hoursNeeded(nums, mid);

            if(hours <= h){
                ans = mid;
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }
        }

        return ans;
    }
};