class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {

        int n = arr.size();
        if (m == n) return n; 

        vector<int> length(n + 2, 0); 
        unordered_map<int, int> count;
        int ans = -1;

        for (int step = 0; step < n; ++step) {
            int i = arr[step];
            int left = length[i - 1];
            int right = length[i + 1];
            int total = left + right + 1;
            length[i - left] = total;
            length[i + right] = total;
            if (left > 0) count[left]--;
            if (right > 0) count[right]--;
            count[total]++;
            if (count[m] > 0) ans = step + 1;
        }

        return ans;
    }
};