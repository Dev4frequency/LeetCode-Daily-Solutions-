class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) 
    {
        int m = s.length();
        int n = knowledge.size();
        unordered_map<string, string> mp;
        for (int i=0; i<n; i++)
        {
            mp[knowledge[i][0]] = knowledge[i][1];
        }
        string answer = "";
        for (int i=0; i<m; )
        {
            if (s[i] == '(')
            {
                i++;
                string temp = "";
                while (s[i] != ')')
                {
                    temp += s[i];
                    i++;
                }
                if (mp.find(temp) != mp.end())
                    answer += mp[temp];
                else
                    answer += "?";
                i++;
            }
            else
            {
                answer += s[i];
                i++;
            }
        }
        return answer;
    }
};