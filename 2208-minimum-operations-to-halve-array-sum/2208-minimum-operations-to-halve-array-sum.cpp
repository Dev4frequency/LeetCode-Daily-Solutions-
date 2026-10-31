class Solution {
public:
    int halveArray(vector<int>& nums) {

        double Sum = 0;
        priority_queue<double> pq;
        for(int i=0; i<nums.size(); i++){
            pq.push(nums[i]+0.0);
            Sum += nums[i];
        }

        int op=0;
        double HalveSum = Sum/2.0;
        while(Sum > HalveSum){
            double maxi = pq.top();
            pq.pop();
            Sum-=maxi/2.0;
            double remaining = maxi-maxi/2.0;
            pq.push(remaining);
            op++;
        }
        return op;
    }
};