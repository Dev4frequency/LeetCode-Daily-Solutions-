class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
         int evenCount = 0, oddCount = 0;

        for (int chipPos : position) {
            if (chipPos % 2 == 0) {
                evenCount++;
            } else {
                oddCount++;
            }
        }

        return std::min(evenCount, oddCount);
    }
};