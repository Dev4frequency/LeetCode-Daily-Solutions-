class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int ans = 0;
        priority_queue<int, vector<int>, less<int>> pq;
        for (const auto& pile : piles) {
            pq.push(pile);
        }
        while (k > 0 && !pq.empty()) {
            int top = pq.top();
            pq.pop();
            pq.push(top - (floor(top / 2)));
            k--;
        }
        while (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};