class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        unordered_map<int,int>freq;
        for(int i:nums){
            freq[i]++;
            if(freq[i]>2) return false;
        }
        return true;
    }
};