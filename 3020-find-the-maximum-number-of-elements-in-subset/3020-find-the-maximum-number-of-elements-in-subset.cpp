class Solution {
public:
    int maximumLength(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<long long, long long>mp;
        for(int it:nums)mp[it]++;

        long long ans = 1;
        if(mp.find(1) != mp.end()){
            long long freq = mp[1];
            if(freq % 2 == 0) freq--;
            ans = freq;
        }

        for(long long i : nums){
            long long cans = 0;
            while(i != 1 && mp.find(i) != mp.end() && mp[i] >= 2){
                cans += 2;
                mp.erase(i);
                i = i*i;
            }
            if(mp.find(i) != mp.end()) cans++;
            else cans--;
            ans = max(ans, cans);
        }
        return ans;
    }
};