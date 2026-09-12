class Solution {
public:
    vector<int> PSE(vector<int>& nums) {
        vector<int> pse(nums.size());
        stack<int> st;
        for (int i = 0; i < nums.size(); i++) {
            while (!st.empty() && nums[st.top()] >= nums[i])
                st.pop();
            st.empty() ? pse[i] = -1 : pse[i] = st.top();
            st.push(i);
        }
        return pse;
    }
    vector<int> NSE(vector<int>& nums) {
        vector<int> nse(nums.size());
        stack<int> st;
        for (int i = nums.size() - 1; i >= 0; --i) {
            while (!st.empty() && nums[st.top()] >= nums[i])
                st.pop();
            st.empty() ? nse[i] = nums.size() : nse[i] = st.top();
            st.push(i);
        }
        return nse;
    }
    int maximumScore(vector<int>& nums, int k) {
        vector<int> pse = PSE(nums);
        vector<int> nse = NSE(nums);
        int score = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            int left = pse[i] + 1;
            int right = nse[i] - 1;
            if (left <= k && right >= k)
                score = max(score, nums[i] * (right - left + 1));
        }

        return score;
    }
};