class Solution {
public:
    int countGoodSubseq(vector<int>& arr, int p, vector<vector<int>>& queries) {
        set<pair<int,int>>st;
        int res = 0;
        int n = arr.size();
        for(auto a : arr){
            if((a % p )== 0){
                auto it = st.lower_bound({a,INT_MIN});
                if(it != st.end() && it->first == a){
                    int prev = it->second;
                    st.erase(it);
                    st.insert({a,prev + 1});
                    
                }
                else{
                    st.insert({a,1});
                }
            }
            
        }
        int  m = queries.size();
        for(int i=0;i<m;i++){
            vector<int>& a = queries[i];
            int index = a[0];
            int prev = arr[index];
            int new_val = a[1];
            arr[index] = new_val;
            if((prev % p )== 0){
                
                auto it = st.lower_bound({prev,INT_MIN});
                if(it != st.end() && it->first == prev){
                    int freq = it->second;
                    st.erase(it);
                    if(freq > 1) st.insert({prev,freq - 1});
                }
            }
            if((new_val % p) == 0){
                auto it = st.lower_bound({new_val,INT_MIN});
                if(it != st.end() && it->first == new_val){
                    int freq = it->second;
                    st.erase(it);
                    st.insert({new_val,freq + 1});
                }
                else{
                    st.insert({new_val,1});
                }
            }
            bool ok = false;
            int ele = 0;
            if(st.size() < n){
                int curr_gcd = 0;
                for(auto & b : st){
                    curr_gcd = __gcd(curr_gcd,b.first);
                    if(curr_gcd == p){
                        ok = 1;
                        break;
                    }
                }
                
            }
            else{
                for(auto &b : st){
                    int curr_gcd = 0;
                    for(auto &c : st){
                        if(c.first != b.first){
                            curr_gcd = __gcd(curr_gcd,c.first);
                        }
                        if(curr_gcd == p){
                            ok = 1;
                            break;
                        }
                    }
                    if(ok) break;
                }
            }
            
            if(ok ){
                res++;
            }
        }
        
        return res;
    }
};