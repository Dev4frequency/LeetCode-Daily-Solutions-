class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> P(m);
        iota(P.begin(), P.end(), 1);
        vector<int> res;
        
        for (int q : queries) {
            auto it = find(P.begin(), P.end(), q);
            res.push_back(distance(P.begin(), it));
            P.erase(it);
            P.insert(P.begin(), q);
        }
        
        return res;
    }
};