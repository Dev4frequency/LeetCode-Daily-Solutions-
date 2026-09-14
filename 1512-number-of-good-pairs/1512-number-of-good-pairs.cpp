class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
          unordered_map<int, int> freq;
        int goodPairs = 0;

        for (int num : nums) {
            goodPairs += freq[num];
            freq[num]++;
        }

        return goodPairs;
    }
};