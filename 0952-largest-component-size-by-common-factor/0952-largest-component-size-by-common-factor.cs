public class Solution {
    public int LargestComponentSize(int[] nums) {
        int max = nums.Max();
        UnionFind uf = new UnionFind(max + 1);

        foreach (int num in nums) {
            for (int fact = 2; fact * fact <= num; fact++) {
                if (num % fact == 0) {
                    uf.Union(num, fact);
                    uf.Union(num, num / fact);
                }
            }
        }

        var count = new Dictionary<int, int>();
        int maxSize = 0;

        foreach (int num in nums) {
            int root = uf.Find(num);
            if (!count.ContainsKey(root)) count[root] = 0;
            count[root]++;
            maxSize = Math.Max(maxSize, count[root]);
        }

        return maxSize;
    }

    class UnionFind {
        private int[] parent;

        public UnionFind(int size) {
            parent = new int[size];
            for (int i = 0; i < size; i++) parent[i] = i;
        }

        public int Find(int x) {
            if (parent[x] != x) parent[x] = Find(parent[x]);
            return parent[x];
        }

        public void Union(int x, int y) {
            int px = Find(x);
            int py = Find(y);
            if (px != py) parent[py] = px;
        }
    }
}