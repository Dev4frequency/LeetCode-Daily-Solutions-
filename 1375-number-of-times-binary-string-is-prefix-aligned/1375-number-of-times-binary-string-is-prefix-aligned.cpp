class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        
        int rightmost=0, ans=0;

        for(int i=0 ; i<flips.size() ; i++){

            rightmost = max(rightmost, flips[i]);
            if(rightmost==i+1)
                ans++;
        }

        return ans;
    }
};