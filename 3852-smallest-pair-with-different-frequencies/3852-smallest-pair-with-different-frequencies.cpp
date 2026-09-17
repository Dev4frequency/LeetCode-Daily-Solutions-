class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int x : nums) freq[x]++;

        vector<int> vals;
        for(auto &p : freq) vals.push_back(p.first);

        sort(vals.begin(), vals.end());

        for(int i = 0; i < vals.size(); i++) {
            for(int j = i + 1; j < vals.size(); j++) {
                if(freq[vals[i]] != freq[vals[j]]) {
                    return {vals[i], vals[j]};
                }
            }
        }

        return {-1, -1};
    }
};