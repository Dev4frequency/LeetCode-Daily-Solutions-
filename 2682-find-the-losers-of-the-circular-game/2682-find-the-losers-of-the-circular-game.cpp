class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        
        unordered_map<int, int>mp;
        int len=1;

        int pos=1;
     
        while(1)
        {
            
            if(pos>=n)
            {
                  pos=pos%n;
            }
            if(pos==0)pos=n;
              mp[pos]++;
            
            if(mp[pos]>1 )break;
          
             
            pos=k*len+pos;
               len++;
            
            
        }
        vector<int>v;
       int i=1;
      while(i<=n)
      {
           if(!mp[i])v.push_back(i);
          i++;
      }
        return v;
    }
};