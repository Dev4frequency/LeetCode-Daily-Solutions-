class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        vector<int> final = {INT_MAX};
        int result = 0;
        for(int num:arr){
            while(final.back() <= num){
                int mid = final.back();
                final.pop_back();
                result += mid*min(final.back(),num);
            }
            final.push_back(num);
        }
        for(int i =2; i<final.size(); i++){
            result += final[i]*final[i-1];
        }
        return result;
    }
};