class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int lo = *min_element(nums.begin(), nums.end());
        int hi = *max_element(nums.begin(), nums.end());
        unordered_set<int> present(nums.begin(), nums.end());
        vector<int> res;
        for (int v = lo + 1; v < hi; ++v)
            if (!present.count(v)) res.push_back(v);
        return res;
    }
};