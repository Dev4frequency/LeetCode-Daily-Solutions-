class Solution {
public:
    int similarPairs(vector<string>& words) {
        int ans=0;
        
        vector<string>v;
        for(int i=0;i<words.size();i++){
            // int m=words.length();
            set<char>st;
            for(auto x:words[i]){
                st.insert(x);
            }
            string z="";
            for(auto c:st){
                z+=c;
            }
            v.push_back(z);
            
        }
        for(int i=0;i<v.size();i++){
            for(int j=i+1;j<v.size();j++){
                if(v[i]==v[j]){
                    cout<<i<<" "<<j<<endl;
                    ans++;
                }
            }
        }
        return ans;
    }
};