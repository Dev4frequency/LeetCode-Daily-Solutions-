class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        if (nums.size() == 1)
            return true;
        for (auto num : nums)
            if (num == 1)
                return false;
        
        int maxValue = *max_element(nums.begin(), nums.end());
        vector<int> factors(maxValue+1, 0);
        for (int d = 2; d <= maxValue; ++d) {
            if (factors[d])
                continue;
            for (int f = d; f <= maxValue; f += d) {
                factors[f] = d;
            }
        }

        vector<int> groups(maxValue * 2 + 1, 0);
        for (int i = 1; i < groups.size(); ++i) {
            groups[i] = i;
        }
        for (auto num : nums) {
            int d = num;
            while (d > 1) {
                int factor = factors[d];
                int f_i = factor + maxValue;
                if (find(num, groups) != find(f_i, groups)) {
                    merge(find(num, groups), find(f_i, groups), groups);
                }
                while (d % factor == 0) {
                    d /= factor;
                }
            }
        }

        int g = find(nums[0], groups);
        for (auto num : nums) {
            if (g != find(num, groups))
                return false;
        }
        return true;
    }
    int find(int a, vector<int>& g) {
        return g[a] == a ? a : g[a] = find(g[a], g);
    }
    void merge(int a, int b, vector<int>& g) {
        g[a] = b;
    }
};