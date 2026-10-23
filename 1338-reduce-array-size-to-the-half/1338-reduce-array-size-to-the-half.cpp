class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> freq;
        for (int num : arr) {
            freq[num]++;
        }

        vector<int> counts;
        for (auto& [_, c] : freq) {
            counts.push_back(c);
        }

        sort(counts.begin(), counts.end(), greater<int>());

        int ans = 0, removed = 0, half = arr.size() / 2;
        for (int c : counts) {
            removed += c;
            ans++;
            if (removed >= half) break;
        }
        return ans;
    }
};