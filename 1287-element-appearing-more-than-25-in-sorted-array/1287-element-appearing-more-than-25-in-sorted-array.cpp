class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        map<int,int> mp;
        int res=0,index=0,index2=0;
        for(int i=0 ; i<arr.size() ; i++){
            mp[arr[i]]++;
        }
        for(auto i:mp){
          index=i.second;
          if(index>index2){
              res=i.first;
              index2=i.second;
          }
        }
        return res;
    }
};