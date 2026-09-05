class Solution {
public:
    typedef long long ll;
    ll modPow(ll x, ll y, ll MOD) {
        ll ans = 1;

        while (y) {
            if (y & 1)
                ans = (ans * x) % MOD;

            x = (x * x) % MOD;
            y /= 2;
        }

        return ans;
    }
    int decoded(ll num){
        const ll MOD = 1000000007;
        ll w = num%10;
        ll d = num/10;
        int n = floor(log10(d)) + 1;

        ll mulx = 1;
        ll muly = 1;

        ll x = 0;
        ll y = 0;
        
        while(n){
            if(n > w){
                y += (d%10)*muly;
                muly *= 10;
            }
            else{
                x += (d%10)*mulx;
                mulx *= 10;
            }
            // cout << x << " " << y << endl;
            d /= 10;
            n--;
        }

        // cout << w << " " << d;
        // cout << x << " " << y;

        return modPow(x, y, MOD);
    }
    int sumDecoded(vector<long long>& nums) {
        const ll MOD = 1000000007;
        ll ans = 0;

        for (auto &i : nums) {
            ans = (ans + decoded(i)) % MOD;
        }

        return ans;
    }
};