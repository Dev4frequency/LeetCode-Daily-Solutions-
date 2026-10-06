class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        string start1 = event1[0], end1 = event1[1], start2 = event2[0], end2 = event2[1];
        start1[2] = start1[3], start1[3] = start1[4]; 
        start1.pop_back();
        start2[2] = start2[3], start2[3] = start2[4]; 
        start2.pop_back();
        end1[2] = end1[3], end1[3] = end1[4]; 
        end1.pop_back();
        end2[2] = end2[3], end2[3] = end2[4]; 
        end2.pop_back();


        if(start1 > end2 || start2 > end1) return false;
        return true;
    }
};