class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int currWater = capacity;
        int i = -1;
        int len = plants.size();
        int totalSteps = 0;
        while (i != len-1) {
            if (plants[i+1] > currWater) {
                totalSteps += i+1;
                currWater = capacity;
                totalSteps += i+1;
            } else {
                currWater -= plants[i+1];
                totalSteps++;
                i++;
            }
        }
        return totalSteps;
    }
};