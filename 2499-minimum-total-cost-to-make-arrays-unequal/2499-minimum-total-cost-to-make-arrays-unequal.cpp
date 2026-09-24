class Solution {
public:
    long long minimumTotalCost(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();
        long long cost = 0;
        int maxFreq = 0;
        int maxFreqVal = 0;
        int noOfIndexToChange = 0;
        unordered_map<int, int> sameIndex;
        for (int i=0; i<n; i++) {
            if (nums1[i] != nums2[i]) continue;
            cost += i;
            noOfIndexToChange++;
            sameIndex[nums1[i]]++;
            if (sameIndex[nums1[i]] > maxFreq) {
                maxFreq = sameIndex[nums1[i]];
                maxFreqVal = nums1[i];
            }
        }
        int extraNSwapping = 2 * maxFreq - noOfIndexToChange;
        if (extraNSwapping <= 0) return cost;
        for (int i=0; i<n; i++) {
            if (extraNSwapping <= 0) return cost;
            if (nums1[i] != nums2[i] && nums1[i] != maxFreqVal && nums2[i] != maxFreqVal) {
                cost += i;
                extraNSwapping--;
            }
        }
        return (extraNSwapping > 0 ? -1 : cost);
    }
};