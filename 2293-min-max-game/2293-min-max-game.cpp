class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        ios_base::sync_with_stdio(false) ;
        cin.tie(nullptr) ;
        cout.tie(nullptr) ;

        int n= nums.size() ;

        while(n>1)
        {
            for(int i=0; i+1<n; i+=2)
            {
                if(i%4==0)
                    nums[i/2]=min(nums[i], nums[i+1]) ;

                else
                    nums[i/2]=max(nums[i], nums[i+1]) ;
            }

            n/=2 ;
        }

        return nums[0] ;
    }
};