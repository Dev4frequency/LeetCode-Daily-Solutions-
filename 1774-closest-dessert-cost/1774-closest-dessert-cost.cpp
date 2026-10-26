class Solution {
public:
    int targetValue;

    int getMinDifference(int option1, int option2) {
        if (option1 == 0) return option2;
        if (option2 == 0) return option1;
        if (abs(targetValue - option1) == abs(targetValue - option2)) return min(option1, option2);
        return abs(targetValue - option1) < abs(targetValue - option2) ? option1 : option2;
    }

    int computePossibleSums(vector<int>& toppings, int idx, int sum) {
        if (idx == toppings.size()) return sum;

        int include = computePossibleSums(toppings, idx + 1, sum + toppings[idx]);
        int doubleInclude = computePossibleSums(toppings, idx + 1, sum + 2 * toppings[idx]);
        int skip = computePossibleSums(toppings, idx + 1, sum);

        return getMinDifference(include, getMinDifference(doubleInclude, skip));
    }

    int closestCost(vector<int>& baseCosts, vector<int>& toppingOptions, int target) {
        targetValue = target;
        int result = INT_MAX;

        for (int base : baseCosts) {
            result = getMinDifference(computePossibleSums(toppingOptions, 0, base), result);
        }

        return result;
    }
};