class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        int result = 0;
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }
        for (auto& pair : freq) {
            if (pair.second == 2) {
                result ^= pair.first;
            }
        }
        
        return result;
    }
};