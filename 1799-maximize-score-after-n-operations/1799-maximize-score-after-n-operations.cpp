class Solution {
public:
    int maxScore(vector<int>& nums) {
        int n = size(nums); 
        map<pair<int, int>, int> memo; 
        
        function<int(int, int)> fn = [&](int k, int mask) {
            pair<int, int> key = make_pair(k, mask); 
            if (!memo.count(key)) 
                for (int i = 0; i < n; ++i) 
                    if (mask & (1 << i)) 
                        for (int j = i+1; j < n; ++j)
                            if (mask & (1 << j)) 
                                memo[key] = max(memo[key], k*gcd(nums[i], nums[j]) + fn(k+1, mask^(1<<i)^(1<<j))); 
            return memo[key]; 
        };
        
        return fn(1, (1 << n)-1); 
    }
};