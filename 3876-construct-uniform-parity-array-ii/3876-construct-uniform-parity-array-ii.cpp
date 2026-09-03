class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        long long minOdd = LLONG_MAX, minEven = LLONG_MAX;
        for (int x : nums1) {
            if (x & 1) minOdd = min(minOdd, (long long)x);
            else minEven = min(minEven, (long long)x);
        }
        bool hasOdd = minOdd != LLONG_MAX;
        bool hasEven = minEven != LLONG_MAX;
        if (!hasOdd || !hasEven) return true;
        return minOdd < minEven;
    }
};