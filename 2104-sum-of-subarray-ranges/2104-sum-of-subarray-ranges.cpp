#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long totalRangeSum = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            long long minVal = LLONG_MAX, maxVal = LLONG_MIN;
            for (int j = i; j < n; ++j) {
                minVal = min(minVal, (long long)nums[j]);
                maxVal = max(maxVal, (long long)nums[j]);
                totalRangeSum += (maxVal - minVal);
            }
        }
        
        return totalRangeSum;
    }
};