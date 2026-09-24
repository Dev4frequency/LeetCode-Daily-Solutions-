class Solution {
    string makeDigit(int num, int digits) {
        string numStr = to_string(num);
        if (numStr.length() < digits) {
            numStr.insert(numStr.begin(), digits - numStr.length(), '0');
        }
        
        return numStr;
    }

    unordered_set<string> makeSwapChanges(int num, int digits) {
        string s = makeDigit(num, digits);
        unordered_set<string> poss;
        poss.insert(s);
        
        for(int i = 0; i < digits; ++i) {
            for(int j = i + 1; j < digits; ++j) {
                if(s[i] != s[j]) {
                    swap(s[i], s[j]);
                    poss.insert(s);
                    for(int i1 = 0; i1 < digits; ++i1) {
                        for(int j1 = 0; j1 < digits; ++j1) {
                            if(i == i1 && j == j1) continue;

                            if(s[i1] != s[j1]) {
                                swap(s[i1], s[j1]);
                                poss.insert(s);
                                swap(s[j1], s[i1]);
                            }
                        }
                    }
                    swap(s[i], s[j]);
                }
            }
        }
        return poss;
    }

public:
    int countPairs(vector<int>& nums) {
        int n = nums.size();

        int mx = 0;
        for(int num : nums) mx = max(mx, num);

        int digits = to_string(mx).size();

        unordered_map<string, int> mp;
        mp[makeDigit(nums[0], digits)]++;
        int ans = 0;
        for(int i = 1; i < n; ++i) {
            for(const auto& s : makeSwapChanges(nums[i], digits)) {
                if(mp.find(s) != mp.end()) {
                    ans += mp[s];
                }
            }

            mp[makeDigit(nums[i], digits)]++;
        }

        return ans;
    }
};