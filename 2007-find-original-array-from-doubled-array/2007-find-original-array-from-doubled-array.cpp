class Solution {
public:
    vector<int> findOriginalArray(vector<int>& a) 
    {
        vector<int> ans;
        sort(a.begin(),a.end());
        map<int,int> m;
        for(auto x:a)
            m[x]++;
        for(int i=0;i<a.size();i++)
        {
            if(m[a[i]]>0)
            {
                m[a[i]]--;
                if(m[2*a[i]]>0)
                {
                    ans.push_back(a[i]);
                    m[2*a[i]]--;
                }
            }
        }
        if(a.size()%2==0 && ans.size()==a.size()/2)
            return ans;
        else
        {
            ans.clear();
            return ans;
        }
    }
    
};