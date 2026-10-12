class Solution {
public:
    vector<int> sortByReflection(vector<int>& nums) {
        vector<pair<int, int>> pairs;
        for (auto num : nums) {
            string s = bitset<32>(num).to_string();
            s.erase(0, s.find_first_not_of('0'));
            reverse(s.begin(), s.end());
            int x = stoi(s, nullptr, 2);
            pairs.push_back({x, num});
        }
        sort(pairs.begin(), pairs.end());
        vector<int> ans;
        for (auto pair : pairs)
            ans.emplace_back(pair.second);

        return ans;
    }
};