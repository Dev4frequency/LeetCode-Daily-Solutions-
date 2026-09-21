class Solution {
public:

    bool check(string& s,int length)
    {
        vector<int>freq1(26,0);
        for(int i=0;i<length;i++)
        {
            freq1[s[i]-'a']++;
        }

        for(int i=length;i<s.size();i+=length)
        {
            vector<int>freq2(26,0);
            for(int j=i;j<i+length;j++)
            {
                freq2[s[j]-'a']++;
            }

            for(int k=0;k<26;k++)
            {
                if(freq1[k]!=freq2[k])
                {
                    return false;
                }
            }
        }
        return true;
    }

    int minAnagramLength(string s) {
        int n=s.size();
        for(int i=1;i<=n;i++)
        {
            if(n%i==0 && check(s,i))
            {
                return i;
            }
        }
        return n;
    }
};