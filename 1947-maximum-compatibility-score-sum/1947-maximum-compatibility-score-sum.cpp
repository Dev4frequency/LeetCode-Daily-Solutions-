class Solution {
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int ans = 0;
        h(students,mentors,0,0,ans);
        return ans;
    }

private:
    void h(vector<vector<int>>& students, vector<vector<int>>& mentors,int i,int com,int& ans){
        if(i >= students.size()){
            ans = max(ans,com);
            return;
        }
        for(int j = 0;j < mentors.size();j++){
            if(mentors[j].size()){
                int c = compatibility(i,j, students,mentors);
                vector<int> temp = mentors[j];
                mentors[j] = {};
                h(students,mentors,i+1, com+c,ans);
                mentors[j] = temp;
            }
        }
    }
    int compatibility(int i,int j,vector<vector<int>>& students, vector<vector<int>>& mentors){
        int count = 0;
        for(int x=0;x < students[i].size();x++){
            if(students[i][x] == mentors[j][x]) count++;
        }
        return count;
    }
};