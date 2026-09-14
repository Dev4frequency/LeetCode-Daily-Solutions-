class Solution {
public:
    int sumOfUnique(vector<int>& nums) {

        int hash[101]={0};
        int sum=0;

        for(auto it :nums){
            hash[it]++;
        }

        for(int i=1;i<=100;i++){
            if(hash[i]==1) sum+=i;
        }
        
        return sum;
    }
};