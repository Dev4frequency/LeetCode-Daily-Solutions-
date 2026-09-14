class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int n=logs.size();
        map<int,int>m;
        for(auto it:logs){
            m[it[0]]++;
            m[it[1]]--;
        }
        int cnt=0;
        int max=-1;
        int year=0;
        for(auto it:m){
            cnt=cnt+it.second;
            if(cnt>max){
                max=cnt;
                year=it.first;
            }
        }
        return year;
    }
};