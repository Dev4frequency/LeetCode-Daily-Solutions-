class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {

        vector<bool>v;
        int cnt = 0;
        vector<int>cmp(n, 0);

        for(int i = 1; i<n; i++){
            if(abs(nums[i]-nums[i-1])>maxDiff)
            cnt++;
            cmp[i] = cnt;
        }

        for(const auto& it:queries){
            v.push_back(cmp[it[0]]==cmp[it[1]]);
        }

        return v;

    }
};