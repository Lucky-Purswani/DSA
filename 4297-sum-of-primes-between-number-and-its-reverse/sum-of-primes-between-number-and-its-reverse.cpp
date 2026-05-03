class Solution {
public:
    vector<bool> sieve(int n) {
        vector<bool> isPrime(n + 1, true);

        isPrime[0] = isPrime[1] = false;

        for(int i = 2; i * i <= n; i++){
            if(isPrime[i]){
                for(int j = 2*i; j <= n; j += i){
                    isPrime[j] = false;
                }
            }
        }
        return isPrime;
    }
    int reverseNumber(int n) {
        int rev = 0;
        while(n > 0){
            int digit = n % 10;
            rev = rev * 10 + digit;
            n /= 10;
        }
        return rev;
    }
    int sumOfPrimesInRange(int n) {
        int rev = reverseNumber(n);
        int s = min(n, rev);
        int e = max(n, rev);
        vector<bool> v = sieve(e);
        long long sum = 0;
        for(int i = s; i<=e; i++){
            if(v[i]){
                sum += i;
            }
        }
        return sum;
    }
};