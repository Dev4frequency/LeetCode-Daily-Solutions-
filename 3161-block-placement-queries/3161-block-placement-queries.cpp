class SegmentTree {
    int n;
    vector<int> tree;

public:
    SegmentTree(int n) : n(n) {
        tree.assign(4 * (n + 1), 0);
    }

    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            tree[node] = val;
            return;
        }

        int mid = (l + r) >> 1;

        if (idx <= mid)
            update(node * 2, l, mid, idx, val);
        else
            update(node * 2 + 1, mid + 1, r, idx, val);

        tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(int idx, int val) {
        update(1, 0, n, idx, val);
    }

    int query(int node, int l, int r, int L, int R) {
        if (R < l || r < L) return 0;

        if (L <= l && r <= R)
            return tree[node];

        int mid = (l + r) >> 1;

        return max(
            query(node * 2, l, mid, L, R),
            query(node * 2 + 1, mid + 1, r, L, R)
        );
    }

    int query(int L, int R) {
        if (L > R) return 0;
        return query(1, 0, n, L, R);
    }
};

class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {

        int mx = 0;

        for (auto &q : queries)
            mx = max(mx, q[1]);

        set<int> st;

        st.insert(0);
        st.insert(mx);

        for (auto &q : queries) {
            if (q[0] == 1)
                st.insert(q[1]);
        }

        SegmentTree seg(mx);

        auto it = st.begin();
        int prevPos = *it;
        ++it;

        while (it != st.end()) {
            int cur = *it;
            seg.update(cur, cur - prevPos);
            prevPos = cur;
            ++it;
        }

        vector<bool> ans;

        for (int i = (int)queries.size() - 1; i >= 0; i--) {

            if (queries[i][0] == 2) {

                int x = queries[i][1];
                int sz = queries[i][2];

                auto it = prev(st.upper_bound(x));
                int p = *it;

                int bestGap = seg.query(0, p);
                int tailGap = x - p;

                ans.push_back(max(bestGap, tailGap) >= sz);

            } else {

                int x = queries[i][1];

                auto cur = st.find(x);

                auto leftIt = prev(cur);
                auto rightIt = next(cur);

                int left = *leftIt;
                int right = *rightIt;

                seg.update(x, 0);
                seg.update(right, right - left);

                st.erase(cur);
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};