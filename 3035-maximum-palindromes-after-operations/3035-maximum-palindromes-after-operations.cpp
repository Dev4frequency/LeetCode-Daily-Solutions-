class Solution {
public:
    int maxPalindromesAfterOperations(vector<string>& words) {
        int n = words.size();
        unordered_map<char,int>mp;
        int count =0;
        for(int i=0;i<n;i++){
            string s = words[i];
            for(char ch: s){
                mp[ch]++;
            }
        }
        vector<int>freq;
        for(auto it: mp){
            freq.push_back(it.second);
        }
        sort(freq.begin(),freq.end());
        vector<int>stringsize;
        for(int i =0;i<n;i++){
            stringsize.push_back(words[i].length());
        }
        sort(stringsize.begin(),stringsize.end());
        int m = stringsize.size();
        int f = freq.size();
        for(int i =0;i<m;i++){
            int len = stringsize[i];
            if(len%2 == 0){
                int times = len/2;
                int p =0;
                while(p<f && times!=0){
                    if(freq[p]>=2){
                        freq[p] = freq[p]-2;
                        times--;
                    }
                    else{
                        p++;
                    }
                }
                if(times==0){
                    count++;
                }
            }
            else{
                 int times = (len-1)/2;
                 int p=0;
                  while(p<f && times!=0){
                    if(freq[p]>=2){
                        freq[p] = freq[p]-2;
                        times--;
                    }
                    else{
                        p++;
                    }
                 }
                 if(times==0){
                    bool falg = false;
                    int p=0;
                    while(p<f && falg == false){
                        if(freq[p]>=1&& freq[p]%2 !=0){
                           freq[p] = freq[p]-1;
                            falg = true;
                           break;
                        }
                        p++;
                    }
                    p=0;
                    while(p<f && falg ==false){
                        if(freq[p]>=1 && freq[p]%2 ==0){
                           freq[p] = freq[p]-1;
                            falg = true;
                        }
                        p++;
                    }
                    if(falg == true){
                        count++;
                    }
                 }
                }
        }
        return count;
    }
};