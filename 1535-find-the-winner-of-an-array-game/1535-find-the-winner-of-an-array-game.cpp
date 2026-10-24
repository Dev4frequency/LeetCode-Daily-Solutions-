class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n=arr.size();
        int max=*max_element(begin(arr),end(arr));

       int winner=arr[0];
       int streaks=0;

        if(k>=n){
            return winner=max;
        }
        else{
            for(int i=1;i<n;i++){
                if(arr[i]>winner){
                    winner=arr[i];
                    streaks=1;
                }
                else{
                    streaks++;
                }
                if(streaks==k||winner==max){
                    return winner;
                }
            }

        }
        return winner;

    }
};