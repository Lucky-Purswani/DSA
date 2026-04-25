class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int minend = arr[0];
        int maxend = arr[0];
        int ans = arr[0];
        for(int i = 1; i<arr.size(); i++){
            int v1 = arr[i];
            int v2 = minend*arr[i];
            int v3 = maxend*arr[i];
            minend = min(v1, min(v2, v3));
            maxend = max(v1, max(v2, v3));
            ans = max(ans, maxend);
        }
        return ans;
    }
};