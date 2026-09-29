class Solution {
private:
    priority_queue<int, vector<int>> pq;
public:
    int lastStoneWeight(vector<int>& stones) {
        for(auto stone : stones) {
            pq.push(stone);
        }
        while(pq.size() > 1) {
            int a = pq.top(); pq.pop();
            int b = pq.top(); pq.pop();
            if(a - b > 0) {
                pq.push(a - b);
            }
        }
        return (pq.size() == 1) ? pq.top() : 0;
    }
};