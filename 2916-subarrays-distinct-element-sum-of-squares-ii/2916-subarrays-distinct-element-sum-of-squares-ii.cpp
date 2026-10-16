class BIT {
public:
    BIT(int size) : n(size) {
        tree1.resize(n + 1, 0);
        tree2.resize(n + 1, 0);
    }

    void update(vector<int>& tree, int index, int value) {
        while (index <= n) {
            tree[index] = (tree[index] + value) % M;
            index += index & -index;
        }
    }

    void rangeUpdate(int l, int r, int value) {
        update(tree1, l, value);
        update(tree1, r + 1, -value);
        update(tree2, l, value * (l - 1));
        update(tree2, r + 1, -value * r);
    }

    int query(vector<int>& tree, int index) {
        long long sum = 0;
        while (index > 0) {
            sum = (sum + tree[index]) % M;
            index -= index & -index;
        }
        return sum;
    }

    int prefixSum(int index) {
        return (query(tree1, index) * (long long)index % M - query(tree2, index) + M) % M;
    }

    int rangeQuery(int l, int r) {
        return (prefixSum(r) - prefixSum(l - 1) + M) % M;
    }

private:
    int n;
    const int M = 1e9 + 7;
    vector<int> tree1, tree2;
};

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        const int M = 1e9 + 7;
        int n = nums.size();
        vector<int> lastOccur(100001, 0);
        long long result = 0;
        long long sumOfSquaresIncrement = 0;
        BIT bit(n);

        for (int i = 0; i < n; i++) {
            int l = lastOccur[nums[i]];
            int r = i;
            long long distinctCountInRange = bit.rangeQuery(l + 1, r + 1);
            bit.rangeUpdate(l + 1, r + 1, 1);
            sumOfSquaresIncrement = (sumOfSquaresIncrement + 2 * distinctCountInRange + r - l + 1) % M;
            result = (result + sumOfSquaresIncrement) % M;
            lastOccur[nums[i]] = i + 1;
        }
        return result;
    }
};



