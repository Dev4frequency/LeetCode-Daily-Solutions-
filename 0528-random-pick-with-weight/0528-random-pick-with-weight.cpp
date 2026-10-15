class Solution {
    vector<int> prefix;
    int total;

public:
    Solution(vector<int>& w) {
        total = 0;

        for (int x : w) {
            total += x;
            prefix.push_back(total);
        }
    }

    int pickIndex() {
        int target = rand() % total + 1;

        int left = 0;
        int right = prefix.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (prefix[mid] >= target)
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }
};