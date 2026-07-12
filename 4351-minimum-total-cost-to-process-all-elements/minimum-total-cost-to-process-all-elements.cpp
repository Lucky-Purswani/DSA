class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        using ll = long long;
        const ll MOD = 1e9 + 7;

        ll res = k;
        ll ans = 0;
        ll cnt = 0; 

        for (int x : nums) {
            if (res < x) {
                ll need = x - res;

                
                ll temp = (need + k - 1) / k;

                cnt += temp;
                res += temp * 1LL * k;
            }

            res -= x;
        }
        return (ll)(((__int128)cnt * (cnt + 1) / 2) % MOD);
    }
};
// class Solution {
// public:
//     int minimumCost(vector<int>& nums, int k) {
//         using ll = long long;
//         const ll MOD = 1e9 + 7;

//         ll resource = k;
//         ll ans = 0;
//         ll id = 0; 

//         for (int x : nums) {
//             if (resource < x) {
//                 ll need = x - resource;

                
//                 ll cnt = (need + k - 1) / k;

//                 __int128 cost = (__int128)cnt * (2LL * id + cnt + 1) / 2;

//                 ans = (ans + (long long)(cost % MOD)) % MOD;

//                 id += cnt;
//                 resource += cnt * 1LL * k;
//             }

//             resource -= x;
//         }

//         return (int)ans;
//     }
// };