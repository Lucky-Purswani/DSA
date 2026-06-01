class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int i = 1;
        int n = cost.size();
        sort(cost.begin(), cost.end());
        reverse(cost.begin(), cost.end());
        long long sum = 0;
        while(i <= n){
            if(i%3 != 0) sum += cost[i-1];
            i++;
        }
        return sum;
    }
};