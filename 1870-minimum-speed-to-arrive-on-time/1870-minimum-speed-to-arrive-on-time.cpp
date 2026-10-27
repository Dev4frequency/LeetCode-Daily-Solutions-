class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
       if(hour<dist.size()-1){
         return -1;
       } 
       int l=0;
       int r=10000000;
       int mid;
       int ans=-1;
       while(l<=r){
         mid=(l+r)/2;
         if(check(dist, hour, mid)){
           ans=mid;
           r=mid-1;
         }
         else{
           l=mid+1;
         }
       }
       return ans;
    }
    bool check(vector<int> & dist, double hour, int speed){
      double time=0;
      int i=0;
      while(time<=hour && i<dist.size()-1){
        time+=ceil(static_cast<double>(dist[i])/speed);
        i++;
      }
      time+=static_cast<double>(dist[dist.size()-1])/speed;
      return (time<=hour);
    }
};