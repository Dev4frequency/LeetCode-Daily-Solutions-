class Solution {
public:
    int countGoodSubstrings(string s) {
        int count=0;
        int n= s.size(); 
        for(int i=0;i<n-2;i++){
            string s1=s.substr(i,3);
            set<char> st(s1.begin(),s1.end());
            if(st.size()==s1.size()){
                count++;
            }
        }
        return count;
    }
};