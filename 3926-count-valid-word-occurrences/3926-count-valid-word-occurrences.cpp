class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        unordered_map<string, int> mp;

        string s = "", seq = "";
        for (auto& vl: chunks) s += vl;

        s.push_back(' ');
        int c = 0;

        for (int i=0;i<s.length();i++){
            if (s[i] == ' '){
                if(!seq.empty() and seq.back() == '-'){
                    seq.pop_back();
                }

                mp[seq]++;
                seq = "";

            } else if(s[i] == '-'){
                if (!seq.empty() and seq.back() != '-' and seq.back() != ' '){
                    seq.push_back(s[i]);

                } else {
                    if (!seq.empty()){
                        seq.pop_back();
                        mp[seq]++;
                        seq = "";
                    }
                }

            } else {
                seq.push_back(s[i]);
            }
        }

        vector<int> ans;
        for (auto& vl: queries){
            ans.push_back(mp[vl]);
        }

        return ans;
    }
};