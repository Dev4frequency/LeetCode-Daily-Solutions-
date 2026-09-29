class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) 
    {
        int total = 0;
        for (int x : arr) 
        {
            total += x;
        }
        if (total % 3 != 0) return false;
        
        int target = total / 3;
        int currentSum = 0;
        int parts = 0;
        
        for (int x : arr) 
        {
            currentSum += x;
            if (currentSum == target) 
            {
                parts++;
                currentSum = 0;
            }
        }
        return parts >= 3;
    }
};