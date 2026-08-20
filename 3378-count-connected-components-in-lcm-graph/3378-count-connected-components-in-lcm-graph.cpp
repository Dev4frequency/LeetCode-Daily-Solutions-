class Solution {
    class DSU{
        vector <int> parent;
        public:
        DSU(int n){
            parent.resize(n+1,-1);
        }

        int find(int x){
            if(parent[x]==-1) return x;
            return parent[x]=find(parent[x]);
        }

        void join(int x,int y){
            x=find(x);
            y=find(y);
            if(x!=y){
                parent[y]=x;
            }
        }
    };
public:
    int countComponents(vector<int>& nums, int threshold) {
        int n=nums.size();
        DSU dsu(threshold);


        for(int i=0;i<n;i++){
            if(nums[i] <= threshold){
                for(int j=nums[i];j <= threshold ;j+=nums[i]){
                    dsu.join(nums[i],j);
                }
            }
        }

        int sol=0;

        set<int> st;

        for(int i=0;i<n;i++){
            if(nums[i]>threshold){
                sol++;
            }
            else{
                st.insert(dsu.find(nums[i]));
            }
        }
        sol+=st.size();
        return sol;
    }
};