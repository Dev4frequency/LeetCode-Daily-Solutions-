class Solution {
public:
    int getLength(vector<int>& nums) {

        int n = nums.size();
        int ans = 1;

        for (int i = 0; i < n; i++) {

            map<int, int> mp;
            set<int> st;
            map<int, int> fmp;

            for (int j = i; j < n; j++) {

                if (mp[nums[j]] > 0) {

                    fmp[mp[nums[j]]]--;

                    if (fmp[mp[nums[j]]] == 0) {
                        st.erase(mp[nums[j]]);
                        fmp.erase(mp[nums[j]]);
                    }
                }

                mp[nums[j]]++;

                fmp[mp[nums[j]]]++;
                st.insert(mp[nums[j]]);

                if (mp.size() == 1) {

                    ans = max(ans, j - i + 1);
                }
                else {

                    if (st.size() == 2) {

                        int x1 = *st.begin();
                        int x2 = *st.rbegin();

                        if (x2 == 2 * x1) {
                            ans = max(ans, j - i + 1);
                        }
                    }
                }
            }
        }

        return ans;
    }
};