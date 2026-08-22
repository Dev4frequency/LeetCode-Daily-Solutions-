class Solution {
public:
    vector<int>d;
    multiset<int>ans;
    int k;
    int n;
    int res = 1e9;
    vector<int>r;
    vector<int> minDifference(int n, int k) {
        this->n = n;
        this->k = k;
        int va = ceil(sqrt(n));
        cout<<va<<endl;
        for(int i=1;i<=ceil(sqrt(n));i++){
            
            if(n%i==0){
                int v = n/i;
                d.push_back(i);
                d.push_back(v);
            }
        } 
         cout<<endl;
        vector<int>st;
        dp(1,0,st);
        
        
        return r;
    }
    void dp(long long p,int t,vector<int>&st){
        if(t==k){
            if(p==n){
                int m = *max_element(st.begin(),st.end());
                int mm = *min_element(st.begin(),st.end());
                int diff = m-mm;
                 if(res>diff){
                    res = diff; 
                    r= st;
                }
               
                return;
            }
            return;
        }
        if(t>k){
            return;
        }
        if(p>=n){
            return;
        }
        for(auto x: d){
            p = p*x;
            st.push_back(x);
            dp(p,t+1,st);
            st.pop_back();
            p = p/x;
        }
        return;
    }
};