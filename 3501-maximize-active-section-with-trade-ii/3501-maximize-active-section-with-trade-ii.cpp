class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(
        string s,
        vector<vector<int>>& queries
    ) {
        int n = s.size();
        int ones = ranges::count(s, '1');
        vector<int> zs, ze;

        for (int i = 0; i < n; ) {
            if (s[i] == '0') {
                int j = i;

                while (j < n && s[j] == '0')
                    ++j;

                zs.push_back(i);
                ze.push_back(j - 1);

                i = j;
            } else {
                ++i;
            }
        }

        int blocks = zs.size();
        vector<int> V;

        for (int i = 0; i + 1 < blocks; ++i) {
            V.push_back(
                (ze[i] - zs[i] + 1) +
                (ze[i + 1] - zs[i + 1] + 1)
            );
        }
        int m = V.size();
        vector<vector<int>> sparse{V};

        for (int len = 1; len * 2 <= m; len *= 2) {
            auto& prev = sparse.back();
            vector<int> next;

            for (int i = 0;
                 i + len < (int)prev.size();
                 ++i) {

                next.push_back(
                    max(prev[i],
                        prev[i + len])
                );
            }

            sparse.push_back(move(next));
        }
        auto rmq = [&](int l, int r) {
            int k = bit_width(
                unsigned(r - l + 1)
            ) - 1;

            return max(
                sparse[k][l],
                sparse[k][r - (1 << k) + 1]
            );
        };
        auto clip = [&](int j, int l, int r) {
            return V[j]
                - max(0, l - zs[j])
                - max(0, ze[j + 1] - r);
        };

        auto getGain = [&](int l, int r) {

            if (blocks < 2)
                return 0;
                int left =
                ranges::lower_bound(
                    ze, l
                ) - ze.begin();
                int right =
                ranges::upper_bound(
                    zs, r
                ) - zs.begin() - 2;

            if (left > right)
                return 0;

            int ans = max(
                clip(left, l, r),
                clip(right, l, r)
            );
               if (right - left >= 2) {
                ans = max(
                    ans,
                    rmq(left + 1, right - 1)
                );
            }

            return ans;
        };

        vector<int> answer;
        answer.reserve(queries.size());

        for (auto& q : queries) {
            answer.push_back(
                ones + getGain(q[0], q[1])
            );
        }

        return answer;
    }
};