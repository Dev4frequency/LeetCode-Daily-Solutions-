class Solution {
public:
    int minOperations(vector<int>& nums) {
        int maxDouble = 0, totalIncrement = 0;
        for (int num : nums) {
            int doubleCount = 0;
            while (num > 0) {
                if (num % 2) {
                    num--;
                    totalIncrement++;
                } else {
                    num /= 2;
                    doubleCount++;
                }
            }
            maxDouble = max(maxDouble, doubleCount);
        }
        return totalIncrement + maxDouble;
    }
};