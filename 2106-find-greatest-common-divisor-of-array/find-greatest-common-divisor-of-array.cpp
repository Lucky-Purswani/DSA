class Solution {
public:
    int gcd(int a, int b){
        if(b == 0) return a;
        return gcd(b, a%b);
    }

    int findGCD(vector<int>& nums) {
        int mn = INT_MAX;
        int mx = INT_MIN;
        for(auto &i : nums){
            mx = max(mx, i);
            mn = min(mn, i);
        }

        return gcd(mx,mn);
    }
};