class Solution {
public:
    int helper(string s,int k){
        int power=1;
        int ans=0;
        for(int i=0;i<s.size();i++){
            ans=(ans+(s[i]-'0')*power)%k;
            power=(power*10)%k;
        }
        return ans%7==0?1:0;
    }
    string solve(string x,int n){
        string ans="";
        string part=x;
        while(n){
            if(n%2){
                ans+=part;
            }
            part+=part;
            n=n/2;
        }
        return ans;
    }
    string largestPalindrome(int n, int k) {
        string ans="";
        set<int> st = {1,2,3,5,9};
        if(st.count(k)){
            ans=solve("9",n);
            if(k==2) ans[0]='8';
            if(k==5) ans[0]='5';
            ans[n-1]=ans[0];
        }else if(k%4==0){
            if(n<5){
                ans=solve("8",n);
            }else{
                ans=solve("8",2)+solve("9",n-4)+solve("8",2);
                if(k==8) ans[2]='8';
                ans[n-3]=ans[2];
            }
        }else{
            if(n<3){
                ans=solve(to_string(k),n);
            }else if(k==6){
                int x=(n-3)/2;
                string part=solve("9",x);
                if(n%2){
                    ans="8"+part+"8"+part+"8";
                }else{
                    ans="8"+part+"77"+part+"8";
                }
            }else{
                vector<string> arr;
                int x=(n-1)/2;
                string part=solve("9",x);
                for(int i=0;i<10;i++){
                    arr.push_back(part+ solve(to_string(i),2-n%2)+part);
                }
                for(int i=0;i<arr.size();i++){
                    if(helper(arr[i],7)){
                        ans=arr[i];
                    }
                }
            }
        }
        return ans;
    }
};