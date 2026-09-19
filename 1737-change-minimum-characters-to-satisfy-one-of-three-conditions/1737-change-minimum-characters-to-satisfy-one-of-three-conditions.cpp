class Solution {
public:
    
    int check(string a, string b)
    {
        int local = INT_MAX;
        for(char ch = 'b';ch<='z';ch++)
        {
            int temp=0;
            
            for(int i=0;i<a.length();i++)
            {
                if(a[i]>=ch)
                    temp++;
            }
            
            for(int i=0;i<b.length();i++)
            {
                if(b[i]<ch)
                    temp++;
            }
            
            local = min(local,temp);
            
        }
        
        return local;
    }
    
    int minCharacters(string a, string b) {
        int ans = min(check(a,b),check(b,a));
        
        vector<int>ha(26),hb(26);
        
        for(int i=0;i<a.length();i++)
        {
            ha[a[i]-'a']++;
        }
        
        for(int i=0;i<b.length();i++)
        {
            hb[b[i]-'a']++;
        }
        
        
        int case3 = 0;
        for(int i=0;i<26;i++){
            case3 = max(case3,ha[i]+hb[i]);
        }
        case3 = a.length() + b.length() - case3;
        
        return min(ans,case3);
    }
};