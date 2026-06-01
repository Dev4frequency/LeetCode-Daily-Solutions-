class Solution {
public:
    int minimumCost(vector<int>& cost) {
       sort(cost.begin(),cost.end());
       int n=cost.size();
       int totalCost=0;
       for(int i=n-1;i>=0;i-=3){
        totalCost+=cost[i];
        if(i-1>=0){
            totalCost+=cost[i-1];
        }
       }
       return totalCost; 
    }
};