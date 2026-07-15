class Solution {
public:
    int gcd(int a, int b){
        if(b == 0) return a;
        return gcd(b, a % b);
    }
    int gcdOfOddEvenSums(int n) {
        long long odd = n*n;
        long long eve = n*(n+1);
        return gcd(odd, eve);
    }
};