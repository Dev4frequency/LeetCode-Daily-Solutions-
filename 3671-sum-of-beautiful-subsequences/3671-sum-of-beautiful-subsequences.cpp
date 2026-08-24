class Solution {
public:
    const int mod = 1e9 + 7;
    void increment(vector<int>& BIT, int idx, int value, int n) {
        while (idx < n) {
            BIT[idx] += value;
            BIT[idx] %= mod;
            idx += (idx & (-idx));
        }
    }

    int query(vector<int>& BIT, int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += BIT[idx];
            sum %= mod;
            idx -= (idx & (-idx));
        }
        return sum;
    }

    void denseNum(vector<int> & nums) {
        vector<pair<int, int>> v;

        for(int i = 0; i < nums.size(); i ++) {
            v.push_back({nums[i], i});
        }

        sort(v.begin(), v.end());
        int curr = 1;
        nums[v[0].second] = curr;
        for(int i = 1; i < nums.size(); i ++) {
           if(v[i].first != v[i - 1].first) {
               curr ++;
           }
            nums[v[i].second] = curr;
        }
    }

    int countTotalStrictlyIncreasingSubSequences(vector<int>& nums) {
        
        denseNum(nums);
        vector<int> BIT(nums.size() + 10);

        int N = nums.size() + 1;
        int total_increasing_subsequences = 0;
        for (auto it : nums) {
            int increasing_subsequences_before_curr = query(BIT, it - 1);
            total_increasing_subsequences +=
                increasing_subsequences_before_curr + 1;
            total_increasing_subsequences %= mod;
            increment(BIT, it, increasing_subsequences_before_curr + 1, N);
        }

        return total_increasing_subsequences;
    }

    int totalBeauty(vector<int>& nums) {
        vector<int> inverted[70001];

        for (auto it : nums) {
            int j = sqrt(it);
            for (int i = 1; i <= j; i++) {
                if (it % i == 0) {
                    inverted[i].push_back(it);
                    if ((it / i) != i) {
                        inverted[it / i].push_back(it);
                    }
                }
            }
        }

        vector<int> total_increasing_subs_for_each_factor(70001);

        int ans = 0;
        for (int i = 70000; i >= 1; i--) {
            if (inverted[i].size() > 0) {
                int an = countTotalStrictlyIncreasingSubSequences(inverted[i]);

                for (int j = 2 * i; j <= 70000; j += i) {
                    an -= total_increasing_subs_for_each_factor[j];
                    an += mod;
                    an %= mod;
                }

                total_increasing_subs_for_each_factor[i] = an;
                ans += (an * 1LL * i) % mod;
                ans %= mod;

                cout << i << " " << an << endl;
            }
        }
        return ans;
    }
};