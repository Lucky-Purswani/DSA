class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        using ll = long long;
        const ll MOD = 1e9 + 7;

        ll res = k;
        ll cnt = 0;

        for (int x : nums) {
            if (res < x) {
                ll need = x - res;
                ll buys = (need + k - 1) / k;
                cnt += buys;
                res += buys * k;
            }
            res -= x;
        }

        return (ll)(((__int128)cnt * (cnt + 1) / 2) % MOD);
    }
};