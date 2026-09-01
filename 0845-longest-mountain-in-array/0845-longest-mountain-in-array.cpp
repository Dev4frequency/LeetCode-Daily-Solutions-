class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        int up = 0;
        int down = 0;

        for(int i = 1; i < n; i++){
            if(down > 0 && arr[i] > arr[i-1]){
                down = 0;
                up = 0;
            }

            if(arr[i] > arr[i-1])up++;
            else if(up > 0 && arr[i] < arr[i-1])down++;
            else if(arr[i] == arr[i-1]){
                up = 0;
                down = 0;
            }

            if(down > 0 && up > 0)ans = max(ans, up+down+1);
        }
        return ans;
    }
};