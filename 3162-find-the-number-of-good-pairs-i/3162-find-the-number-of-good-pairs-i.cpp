class Solution {
public:
    int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
       int m = nums1.size();
       int n = nums2.size();
       int count = 0;
       for(int i = 0; i < nums1.size(); i++) {
          for(int j = 0; j < nums2.size(); j++) {
             int divisor = nums2[j] * k;
             if(nums1[i] % divisor == 0) {
                count++;
             }
          }
       } 
       return count;
    }
};