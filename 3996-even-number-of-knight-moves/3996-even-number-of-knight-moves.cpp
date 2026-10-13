class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        if((start[0] + start[1]) % 2 == (target[0] + target[1]) % 2) return true;
        return false;
    }
};