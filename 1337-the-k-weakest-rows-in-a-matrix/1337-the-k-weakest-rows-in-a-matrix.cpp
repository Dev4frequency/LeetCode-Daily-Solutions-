class Solution {
public:

    int bs(vector<int>&arr, int n){
        int lo=0, hi=n-1;
        if(arr[n-1]==1) return n;

        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(arr[mid]==1){
                lo=mid+1;
            }else{
                hi=mid-1;
            }
        }
        return hi+1;
    }

    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue< pair<int, int>, vector<pair<int, int>> >pq;
        int n=mat.size();
        int m=mat[0].size();

        for(int i=0; i<n; i++){
            int weakness=bs(mat[i], m);
            if(pq.size()<k){
                pq.push({weakness, i});
            }else if(!pq.empty() && weakness<pq.top().first){
                pq.pop();
                pq.push({weakness, i});
            }
        }

        vector<int>ans(k);
        for(int i=k-1; i>=0; i--){
            ans[i]=pq.top().second;
            pq.pop();
        }
        return ans;
    }
};