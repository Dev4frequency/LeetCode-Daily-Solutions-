class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int l = nums.size();
       vector<int> left(l,0);
       vector<int> right(l,0);
        for(int i= 1; i<l;i++){
            left[i] = left[i-1] +nums[i-1];
            right[l-i-1] = right[l-i] + nums[l-i];
        }
        vector<int> answer(l);
        for(int i = 0;i<l;i++){
            answer[i] = abs(left[i] - right[i]);
        }
        return answer;
    }
};