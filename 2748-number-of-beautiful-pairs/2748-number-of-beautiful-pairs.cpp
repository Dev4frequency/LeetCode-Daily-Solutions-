class Solution {
private:
    bool isBeautifulPair(int i , int j){
        while(i > 9){
            i /= 10;
        }
        j = j%10;
        return gcd(i,j) == 1;
    }
public:
    int countBeautifulPairs(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < nums.size() - 1; i++){
            for(int j = i + 1; j < nums.size(); j++){
                if(isBeautifulPair(nums[i] , nums[j])){
                    ans++;
                }
            }
        }
        return ans;
    }
};