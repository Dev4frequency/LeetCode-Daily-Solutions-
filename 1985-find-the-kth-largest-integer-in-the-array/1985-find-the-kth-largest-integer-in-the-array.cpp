class Solution {
public:
    struct compare {
        bool operator()(const string& a, const string& b) const {
            if (a.size() != b.size())
                return a.size() > b.size();
            return a > b;
        }
    };
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<string, vector<string>, compare> pq;
        for (auto& entry : nums) {
            pq.push(entry);
            if (pq.size() > k)
                pq.pop();
        }
        return pq.top();
    }
};