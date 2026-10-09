class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        set<int> lines;
        for(vector<int> row: nums){
            for(int i=row[0]; i<=row[1]; i++){
                lines.insert(i);
            }
        }
        return lines.size();
    }
};