class Solution {
public:
    
    string largestPalindromic(string num) {
        unordered_map<int,int> mp;
        for(auto a:num)
            mp[a-'0']++;
        priority_queue<pair<int,int>> pq;
        int mx=INT_MIN;
        int size=0;
        
        for(auto a:mp){
            if(a.second>1){
                pq.push({a.first,a.second/2});
                size+=a.second/2;
            }
            if(a.second%2!=0){
                mx=max(a.first,mx);
            }
        }
        if(pq.size()==1&&pq.top().first==0){
            if(mx!=INT_MIN)
                return to_string(mx);
            return "0";
        }
        
        
        string s="";
        while(!pq.empty()){
            int no=pq.top().first;
            int cnt = pq.top().second;
            pq.pop();
            for(int i = 0; i < cnt; i++){
                s+=to_string(no);
            }
        }
        cout<<s;
        string k=s;
        reverse(s.begin(),s.end());
        if(mx!=INT_MIN){
            return k+to_string(mx)+s;
        }
        return k+s;
        
        
        
    }
};