#include <vector>
#include <numeric>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0);

        // Find with path compression
        function<int(int)> find = [&](int x) -> int {
            if (parent[x] != x)
                parent[x] = find(parent[x]);
            return parent[x];
        };

        // Union operation
        auto unite = [&](int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
            if (rootX != rootY) {
                parent[rootX] = rootY;
            }
        };

        // Build connected components using allowed swaps
        for (const auto& swap : allowedSwaps) {
            unite(swap[0], swap[1]);
        }

        // Group indices by component root
        unordered_map<int, vector<int>> components;
        for (int i = 0; i < n; ++i) {
            int root = find(i);
            components[root].push_back(i);
        }

        int totalMatches = 0;

        // Count element frequencies and compute matches within each component
        for (auto& [root, indices] : components) {
            unordered_map<int, int> sourceCount, targetCount;
            for (int idx : indices) {
                sourceCount[source[idx]]++;
                targetCount[target[idx]]++;
            }
            for (const auto& [val, count] : sourceCount) {
                if (targetCount.count(val)) {
                    totalMatches += min(count, targetCount[val]);
                }
            }
        }

        return n - totalMatches;
    }
};