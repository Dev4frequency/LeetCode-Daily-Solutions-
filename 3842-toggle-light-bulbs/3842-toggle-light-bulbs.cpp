class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        vector<bool> ans(101, false);
        vector<int> bulb;
        for(int val : bulbs) {
            if(ans[val] == false) {
                ans[val] = true;
            } else {
                ans[val] = false;
            }
        }
        for(int i = 0; i<ans.size(); i++) {
            if(ans[i] == true) {
                bulb.push_back(i);
            }
        }
        return bulb;
    }
};