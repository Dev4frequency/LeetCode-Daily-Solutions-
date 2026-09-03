class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        int q=queries.size();
        vector<bool> ans;
        for(auto &query:queries)
        {
            int j=0;
            bool match=true;
            for(int i=0;i<query.length();i++)
            {
                if(j<pattern.length() && query[i]==pattern[j])
                {
                    j++;
                }
                else if(isupper(query[i]))
                {
                    match=false;
                    break;
                }
            }
            if(j!=pattern.length())
            {
                match=false;                 
            }
            ans.push_back(match);
        }
        return ans;
    }
};