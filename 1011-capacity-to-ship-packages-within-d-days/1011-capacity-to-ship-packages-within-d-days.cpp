class Solution {
public:

    bool possible(vector<int>& weights, int days, int capacity) {

        int currentLoad = 0;
        int daysUsed = 1;

        for(auto weight : weights) {

            if(currentLoad + weight <= capacity) {
                currentLoad += weight;
            }
            else {
                daysUsed++;
                currentLoad = weight;
            }
        }

        return daysUsed <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {

        int low = 0;
        int high = 0;

        for(auto weight : weights) {
            low = max(low, weight);
            high += weight;
        }

        while(low <= high) {

            int mid = low + (high - low) / 2;

            if(possible(weights, days, mid)) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};