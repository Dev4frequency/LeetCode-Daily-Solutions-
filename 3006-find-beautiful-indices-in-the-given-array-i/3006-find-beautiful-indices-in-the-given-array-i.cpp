class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> ans;
        int aLength = a.size();
        int bLength = b.size();
        int i = 0;
        vector<int> setOfI;
        vector<int> setOfJ;
        while(i<s.size()){
            if(s.substr(i, aLength) == a){
                setOfI.push_back(i);
            }
            if(s.substr(i, bLength) == b){
                setOfJ.push_back(i);
            }
            i++;
        }
        i = 0;
        int j = 0;
        while(i < setOfI.size() && j < setOfJ.size()){
            if(abs(setOfI[i] - setOfJ[j]) <= k){
                if(ans.empty() || ans.back() != setOfI[i]){
                    ans.push_back(setOfI[i]);
                }
                i++;
            }
            else if(setOfI[i] > setOfJ[j]) j++;
            else i++;
        }
        return ans;
    }
};