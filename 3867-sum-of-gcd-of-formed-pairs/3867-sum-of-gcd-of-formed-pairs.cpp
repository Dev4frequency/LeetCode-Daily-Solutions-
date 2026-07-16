class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();

        vector<int>v;
        int mx = 0;
        for(int i = 0; i<n; i++){
            mx = max(mx, nums[i]);
            v.push_back(__gcd(mx, nums[i]));
        }

        sort(v.begin(), v.end());
        long long sum = 0;

        int i = 0; int j = n-1;
        while(i<j){
            sum+=(__gcd(v[i], v[j]));
            i++; j--;
        }
        
        return sum;
    }
};