class Solution {
public:
    int countTriplets(vector<int>& arr) {

        unordered_map<int, int> freq;
        unordered_map<int, int> sumIndex;

        int prefixXor = 0;
        int ans = 0;

        // Prefix XOR before the array
        freq[0] = 1;
        sumIndex[0] = -1;

        for (int i = 0; i < arr.size(); i++) {
            prefixXor ^= arr[i];
            if (freq.find(prefixXor) != freq.end()) {
                ans += freq[prefixXor] * (i - 1)
                       - sumIndex[prefixXor];
            }
            freq[prefixXor]++;
            sumIndex[prefixXor] += i;
        }

        return ans;
    }
};