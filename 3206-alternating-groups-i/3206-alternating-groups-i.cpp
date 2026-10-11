class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int count = 0;
        int n = colors.size();

        for (int i = 0; i < n; i++) {
            int left = colors[(i - 1 + n) % n];
            int mid = colors[i];
            int right = colors[(i + 1) % n];

            if (mid != left && mid != right) {
                count++;
            }
        }
        return count;
    }
};