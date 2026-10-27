class Solution {
public:
    int helper(vector<int>&obstacles, int row, int index,vector<vector<int>>&dp){
        if(index>=obstacles.size()-1){
            return 0;
        }

        if(dp[row][index]!=-1){
            return dp[row][index];
        }
       

        int option1=INT_MAX;
        int option2=INT_MAX;
        if(obstacles[index+1]!=row){
            option1=helper(obstacles,row,index+1,dp);
        }
        else {

            for(int i=1;i<=3;i++){
                if(i==row || obstacles[index]==i){
                    continue;
                }
                else{
                    int curr=0;
                    curr=1+helper(obstacles,i,index,dp);
                    option2=min(option2,curr);
                }
            }

        }

        dp[row][index]= min(option1,option2);
        return dp[row][index];
    }
    int minSideJumps(vector<int>& obstacles) {

        vector<vector<int>>dp(4, vector<int>(obstacles.size(),-1));
        int result=helper(obstacles,2,0,dp);
        return result;
    }
};