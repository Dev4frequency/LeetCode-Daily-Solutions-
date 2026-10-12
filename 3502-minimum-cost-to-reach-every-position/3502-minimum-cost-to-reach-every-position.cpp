class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        int m = 100;
        vector<int> v;
        for(auto &c : cost) {
            m = min(m,c);
            v.push_back(m);
        }
        return v;
    }
};