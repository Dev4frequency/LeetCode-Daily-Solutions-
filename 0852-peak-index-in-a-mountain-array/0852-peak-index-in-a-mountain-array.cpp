class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr){
         int peak=0;
         int index=0;
         int left=0;
         int right=arr.size()-1;
         while( right>=left){
             if(arr[left]<peak && arr[right]<peak){
                 break;
             }
             peak=max(arr[left] , max(peak , arr[right]) );     
             if(arr[left]>arr[right]) index=left;
             else index=right;
             left++;
             right--;
         }
         return index;
    }
};