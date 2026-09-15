class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {

        unordered_map<int,int>freq;
        int c=0;

        for(int num:nums){
            freq[num]++;
        }

        for(auto [n,f]:freq){
            if(freq.count(n+k)){
                c+=f*freq[n+k];
            }
        }
        
        return c;
    }
};