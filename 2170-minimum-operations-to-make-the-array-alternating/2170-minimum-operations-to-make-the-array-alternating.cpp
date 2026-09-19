class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int,int>mpo,mpe;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(i%2)mpo[nums[i]]++;
            else mpe[nums[i]]++;
        }
        int maxi1o=0,maxn1o=0,maxio=0,maxno=0,maxi1e=0,maxn1e=0,maxie=0,maxne=0;
        for(auto it:mpo){
            if(it.second>maxio){
                maxi1o=maxio;
                maxn1o=maxno;
                maxio=it.second;
                maxno=it.first;
            }
            else if(it.second>maxi1o){
                maxi1o=it.second;
                maxn1o=it.first;
            }
        }
        for(auto it:mpe){
            if(it.second>maxie){
                maxi1e=maxie;
                maxn1e=maxne;
                maxie=it.second;
                maxne=it.first;
            }
            else if(it.second>maxi1e){
                maxi1e=it.second;
                maxn1e=it.first;
            }
        }
        int maxi1=0,maxi2=0;
        if(maxno==maxne){
            if(maxi1e+maxio>maxi1o+maxie){
                maxi1=maxio;
                maxi2=maxi1e;
            }
            else{
                maxi1=maxi1o;
                maxi2=maxie;
            }
        }
        else {
            maxi1=maxio;
            maxi2=maxie;
        }
        int cnt1=(n+1)/2-maxi1,cnt2=n/2-maxi2;
        return cnt1+cnt2;
    }
};