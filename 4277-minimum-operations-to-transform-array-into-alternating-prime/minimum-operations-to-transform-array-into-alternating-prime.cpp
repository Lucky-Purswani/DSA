class Solution {
public:
    int minOperations(vector<int>& nums) {
        int maxn = 200000;

        //Step 1 sieve erastosthenes
        vector<bool> isPrime(maxn + 1, true);
        isPrime[0] = isPrime[1] = false;
        for(int i = 2; i*i<= maxn; i++){
            if(isPrime[i]){
                for(int j = i*i; j<=maxn; j+=i){
                    isPrime[j] = false;
                }
            }
        }

        //Step 2 get nextPrime
        vector<int> nextPrime(maxn+1, -1);
        int last = -1;
        for(int i = maxn; i>=0; i--){
            if(isPrime[i]) last = i;
            nextPrime[i] = last;
        }
        
        //Step 3 get nextNonPrime
        vector<int> nextNonPrime(maxn+1, -1);
        last = -1;
        for(int i = maxn; i>=0; i--){
            if(!isPrime[i]) last = i;
            nextNonPrime[i] = last;
        }

        //Step 4 calc ans.
        long long ans = 0;
        for(int i = 0; i<nums.size(); i++){
            int x = nums[i];

            if(i%2 == 0){
                int target = nextPrime[x];
                ans += (target-x);
            }
            else{
                int target = nextNonPrime[x];
                ans+=(target-x);
            }
        }
        return ans;
    }
};