class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
        int sum2 = accumulate(nums2.begin(), nums2.end(), 0);
        if(sum1 == sum2) return 0;

        if(sum1 < sum2) {
            swap(nums1, nums2);
            swap(sum1, sum2);
        }

        int m = nums1.size(), n = nums2.size();
        int count = 0;

        int i = m-1, j = 0;
        while(i >= 0 || j < n) {
            if(i >= 0 && j < n && nums1[i] != 1 && nums2[j] != 6) {
                if(nums1[i] - 1 >= 6 - nums2[j]) {
                    if(nums1[i] - 1 >= sum1 - sum2) return count + 1;
                    else {
                        sum1 -= nums1[i] - 1;
                        nums1[i] = 1;
                        i--;
                        count++;
                    }
                }
                else {
                    if(6 - nums2[j] >= sum1 - sum2) return count + 1;
                    else {
                        sum2 += 6 - nums2[j];
                        nums2[j] = 6;
                        j++;
                        count++;
                    }
                }
            }
            else if(i >= 0 && nums1[i] != 1) {
                if(nums1[i] > 1) {
                    if(nums1[i] - 1 >= sum1 - sum2) return count + 1;
                    else {
                        sum1 -= nums1[i] - 1;
                        nums1[i] = 1;
                        i--;
                        count++;
                    }
                }
                else i++;
            }
            else if(j < n && nums2[j] != 6) {
                if(nums2[j] < 6) {
                    if(6 - nums2[j] >= sum1 - sum2) return count + 1;
                    else {
                        sum2 += 6 - nums2[j];
                        nums2[j] = 6;
                        j++;
                        count++;
                    }
                }
                else j++;
            }
            else break;
        }

        return -1;
    }
};