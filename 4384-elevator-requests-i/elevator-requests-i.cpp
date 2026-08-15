class Solution {
public:
    int elevatorRequests(int n, vector<int>& req) {
        int ans = req[0];
        for(int i = 1; i<req.size(); i++){
            ans += abs(req[i-1]-req[i]);
        }
        return ans;
    }
};