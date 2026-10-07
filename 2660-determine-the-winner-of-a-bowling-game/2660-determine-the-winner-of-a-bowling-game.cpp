class Solution {
public:
    int isWinner(vector<int>& p1, vector<int>& p2) {

        int sum1=0;
        int sum2=0;
        int n=p1.size();
    sum1+=p1[0];
   
     sum2+=p2[0];
   
        for(int i=1;i<n;i++)
        {  if(p1[i-1]==10 || ((i-2)>=0 &&p1[i-2]==10)) sum1+=2*p1[i];
             else sum1+=p1[i]; 
           
        }
        for(int i=1;i<n;i++)
        {  if(p2[i-1]==10 || ((i-2)>=0 &&p2[i-2]==10)) sum2+=2*p2[i];
             else sum2+=p2[i]; 
           
        }
        
         if(sum1>sum2)
            return 1;
        else if(sum1<sum2)
            return 2;
        else return 0;
    }
};