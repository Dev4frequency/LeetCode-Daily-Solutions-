class Solution {
private:
    int wordCount(string s){
        string temp = "";
        int ans = 0;
        for(char c : s){
            if(c == ' ' && !temp.empty()){
                ans++;
                temp = "";
            }
            else{
                temp.push_back(c);
            }
        }
        if(!temp.empty()){
                ans++;
        }
        return ans;
    }

public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        unordered_map<string,int>freq;
        int m = 0;
        string ans = "";
        for(int i = 0; i < messages.size(); i++){
            freq[senders[i]] += wordCount(messages[i]);
            if(m < freq[senders[i]]){
                m = freq[senders[i]];
                ans = senders[i];
            }
            else if(m == freq[senders[i]] && ans < senders[i]){
                ans = senders[i];
            }
        }
        return ans;
    }
};