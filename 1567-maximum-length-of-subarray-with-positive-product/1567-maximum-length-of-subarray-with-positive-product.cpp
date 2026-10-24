class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int s=0;
        int f=-1;
        int l=-1;
        int m=0;
        int n=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                s=i+1;
                f=-1;
                l=-1;
                n=0;
            }else{
                if(nums[i]<0){
                    n++;
                    if(f==-1){
                        f=i;
                    }
                    l=i;
                }
                if(n%2==0){
                    m=max(m,i-s+1);
                }else{
                    m=max(m,max(i-f,l-s));
                }
            }
            
        }
        return m;
    }
    
};