class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        for(int i = 0; i < nums1.size(); i++)
        {
            
            int index = -1;
            for(int j = 0; j < nums2.size(); j++)
            {
                if(nums1[i] == nums2[j])
                {
                    index = j;
                    break;
                }
            }
        
            int nextGreater = -1;
            for(int k = index + 1; k < nums2.size(); k++)
            {
                if(nums2[k] > nums1[i])
                {
                    nextGreater = nums2[k];
                    break;
                }
            }
            nums1[i] = nextGreater;
        }
        return nums1;
    }
};