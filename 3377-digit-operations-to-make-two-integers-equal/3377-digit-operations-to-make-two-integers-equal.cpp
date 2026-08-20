class Solution {
public:
    int minOperations(int n, int m) {
        int mx=max(n,m);
        mx*=10;
        vector<int>vis(mx+1,-1);
        int i=2;
        while(i<=mx){
            int j=i;
            if(vis[i]!=-1){
                i+=1;
                continue;
            }
            while(j<=mx){
                if(vis[j]==-1){
                    vis[j]=i;
                }
                j+=i;
            }
            i+=1;
        }
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>q;
        vector<int>distance(mx+1,INT_MAX);
        distance[n]=0;
        if(vis[n]==n)return -1;
        if(n==m)return n;
        
        q.push({n,n});
        while(q.size()){
            pair<long long,int>p=q.top();
            q.pop();
            long long val=p.first;
            int curr_val=p.second;
            // cout<<val<<" ";
            string s=to_string(curr_val);
            if(curr_val==m)return val;

            for(int i=0;i<s.size();i++){
                if(s[i]!='9'){
                    string first=s;
                    first[i]+=1;
                    int res=stoi(first);
                    if(vis[res]!=res and val+res<distance[res]){
                        distance[res]=val+res;
                        q.push({distance[res],res});
                    }
                }
                if(s[i]!='0'){
                    string first=s;
                    first[i]-=1;
                    int res=stoi(first);
                    if(vis[res]!=res and val+res<distance[res]){
                        distance[res]=val+res;
                        q.push({distance[res],res});
                    }
                }
            }
        }
        cout<<endl;
        return -1;
    }
};