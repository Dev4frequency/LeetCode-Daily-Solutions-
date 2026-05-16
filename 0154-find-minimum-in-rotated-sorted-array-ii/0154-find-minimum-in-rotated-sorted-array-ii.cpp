class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0;
        int rotated = nums.size() - 1;
        while(l<rotated){
       int m = (l + rotated) / 2;
      if (nums[m] == nums[rotated])
        --rotated;
      else if (nums[m] < nums[rotated])
        rotated = m;
      else
        l = m + 1;
    }

    return nums[l];
  }
};