class Solution {
public:
bool canTransform(string start, string result) {
        int n = start.length();
        int idx1 = 0, idx2 = 0;
        while(idx1<n||idx2<n){
            while(idx1<n&&start[idx1]=='X'){
                idx1++;
            }
            while(idx2<n&&result[idx2]=='X'){
                idx2++;
            }
            if(idx1==n&&idx2==n){
                return true;
            }
            if(idx1==n||idx2==n){
                return false;
            }
            if(start[idx1]!=result[idx2]){
                return false;
            }
            if(start[idx1]=='L'&&idx1<idx2){
                return false;
            }
            if(start[idx1]=='R'&&idx1>idx2){
                return false;
            }
            idx1++;
            idx2++;
        }
        return true;
    }
};