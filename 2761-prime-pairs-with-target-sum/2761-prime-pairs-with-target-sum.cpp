class Solution {
public:
    vector<vector<int>> findPrimePairs(int n) {
        vector<vector<int>> ans;
        vector<int> once(n, 0);

        for (int i = 2; i < n; i++) {
            if (once[i] == 0) {
                for (int j = i * 2; j < n; j += i) {
                    once[j] = 1;
                }
            }
        }
        int i = 2;
        int j = n - 2;
        while (i <= j) {
            if (once[i] == 0 && once[j] == 0) {
                if (i + j == n) {
                    ans.push_back({i, j});
                }
            }
            i++;
            j = n - i;
        }
        return ans;
    }
};