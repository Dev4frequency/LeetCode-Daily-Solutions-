class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) 
    {
        int n = arr.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) 
        {
            prefix[i + 1] = prefix[i] + arr[i];
        }

        int totalSum = 0;
        for (int len = 1; len <= n; len += 2) 
        {
            for (int start = 0; start + len <= n; start++) 
            {
                totalSum += prefix[start + len] - prefix[start];
            }
        }

        return totalSum;
    }
};