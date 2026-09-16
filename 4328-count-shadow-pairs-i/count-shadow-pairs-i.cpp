class Solution {
public:

    vector<int> ns(vector<int>& nums) {
        int n = nums.size();
        vector<int> next(n, n);
        stack<int> st;

        for(int i = n-1; i >= 0; i--) {
            while(!st.empty() && nums[st.top()] >= nums[i])
                st.pop();

            if(!st.empty())
                next[i] = st.top();

            st.push(i);
        }

        return next;
    }

    int getEqual(vector<int>& freq, int st, int en) {
        return lower_bound(freq.begin(), freq.end(), en)
             - lower_bound(freq.begin(), freq.end(), st);
    }

    long long shadowPairs(vector<int>& nums) {
        int n = nums.size();

        vector<int> next = ns(nums);

        unordered_map<int, vector<int>> freq;

        for(int i = 0; i < n; i++) {
            freq[nums[i]].push_back(i);
        }

        long long ans = 0;

        for(int i = 0; i < n; i++) {
            long long len = next[i] - i;

            ans += len - getEqual(freq[nums[i]], i, next[i]);
        }

        return ans;
    }
};