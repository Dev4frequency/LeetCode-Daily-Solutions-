class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        unordered_set<int>st;
        for (int it : nums){
            sum+=it;
            st.insert(it);
        }
        double avg=(double)sum/n;
        int candidate=max(1,(int)floor(avg)+1);
        while(st.count(candidate))candidate++;
        return candidate;
    }
};