class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {   
    
    int n=nums.size();
    int sum=0;
    for(int i=0;i<n; i++)
       sum+=nums[i];
    int leftsum=0; 
    for (int i=0;i<n;i++) 
    {
      int rightsum=sum-leftsum-nums[i];
      if(leftsum==rightsum)
         return i; 
      leftsum+=nums[i];
    } 
     return -1;
    }
};