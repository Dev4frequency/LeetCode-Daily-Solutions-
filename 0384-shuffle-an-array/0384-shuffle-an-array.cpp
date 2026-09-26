class Solution {
public:
    vector<int> origional;
    vector<int> shuffled;
    Solution(vector<int>& nums) {
        origional = nums;
        shuffled = nums;
    }
    
    vector<int> reset() {
        return origional;
    }
    
    vector<int> shuffle() {
        int n = shuffled.size();
        for(int i = n-1 ; i>0 ; i--){
            int rd = random() % (i+1);
            swap(shuffled[i] , shuffled[rd]);
        }
        return shuffled;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */