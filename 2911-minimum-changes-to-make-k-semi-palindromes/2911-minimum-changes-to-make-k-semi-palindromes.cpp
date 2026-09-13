class Solution {
    int MAX;
    vector<vector<int>> mem;
    int minChanges(string_view s){
        if(s.size() <= 1) return MAX;
        
        int changes = s.size() / 2;
        for(int d = 1; d < s.size(); ++d){
            if(s.size() % d) continue;
            int count = 0;
            for(int i = 0; i < d; ++i){
                int low = i, high = (s.size() / d - 1) * d + i;
                while(low < high){
                    count += (s[low] != s[high]);
                    low += d;
                    high -= d;
                }
            }
            changes = min(changes, count);
        }

        return changes;
    }
    
    int solve(const string& s, int index, int k){
        if(k <= 1){
            return minChanges(string_view(s.c_str() + index, s.size() - index));
        }
        
        if(index >= s.size() || k > s.size() - index) return MAX;
        if(mem[index][k] != -1) return mem[index][k];
        
        int minFlips = MAX;
        for(int i = index + 2; i < s.size(); ++i){
            minFlips = min(minFlips, minChanges(string_view(s.c_str() + index, i - index)) + solve(s, i, k - 1));
        }
        
        mem[index][k] = minFlips;
        return minFlips;
    }
public:
    int minimumChanges(string s, int k) {
        MAX = s.size();
        mem.resize(s.size(), vector<int>(k + 1, -1));
        return solve(s, 0, k);
    }
};