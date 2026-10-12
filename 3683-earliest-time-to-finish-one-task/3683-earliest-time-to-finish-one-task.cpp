class Solution {
public:
    int earliestTime(vector<vector<int>>& tasks) {
        sort(tasks.begin(),tasks.end(),[](vector<int>&a,vector<int>&b){
            return a[0]+a[1]<b[0]+b[1];
        });
        return tasks[0][0]+tasks[0][1];
    }
};