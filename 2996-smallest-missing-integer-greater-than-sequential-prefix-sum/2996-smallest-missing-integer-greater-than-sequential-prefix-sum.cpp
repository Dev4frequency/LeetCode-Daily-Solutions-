class Solution {
public:
    int missingInteger(vector<int>& n) {
        if(n.size()==1) return n[0]+1;

        int s=n[0];

        for(int i=1;i<n.size();i++) {
            if(n[i]==n[i-1]+1) s+=n[i];
            else break;
        }

        while(find(n.begin(),n.end(),s)!=n.end()) s++;

        return s;
    }
};