class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        unordered_set<int> ban(forbidden.begin(), forbidden.end());
        unordered_set<int> visl;  
        unordered_set<int> visr;

        queue<pair<int, bool>> q;  
        q.push({0, false});  
        visl.insert(0);

        int res = 0; 

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto cur = q.front();
                q.pop();
                int pos = cur.first;
                bool isBackward = cur.second;
                if (pos == x) return res;

                int forward = pos + a;
                if (forward <= 10000 && ban.find(forward) == ban.end() && visl.find(forward) == visl.end()) {
                    visl.insert(forward);
                    q.push({forward, false}); 
                }
                int backward = pos - b;
                if (backward >= 0 && ban.find(backward) == ban.end() && visr.find(backward) == visr.end() && !isBackward) {
                    visr.insert(backward);
                    q.push({backward, true});
                }
            }
            res++;
        }
        return -1;
    }
};