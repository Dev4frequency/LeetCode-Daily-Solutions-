class Solution {
public:
    long long maxTotal(vector<int>& value, vector<int>& limit) {
        long long res=0;
        unordered_map<int, priority_queue<int>> u;
 
        int n = value.size();
        for (int i=0;i<n;i++)
        {
            u[limit[i]].push(value[i]);
        }
        
        for (auto &[key, val] : u){
            for (int i=0;i<key && !val.empty(); i++){
                res += val.top();
                val.pop();
            }
        }
        return res;
    }
};