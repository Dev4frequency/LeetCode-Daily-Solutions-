class Solution {
public:
    string getmincycle(string x){ 
        int n = x.size(), i = 0, j = 1, k = 0;
        while(i < n && j < n && k < n){
            if(x[(i+k)%n] == x[(j+k)%n]){
                k++;
            }
            else{
                if(x[(i+k)%n] < x[(j+k)%n]){
                    j = j + k + 1;
                }
                else{
                    i = i + k + 1;
                }
                if(i == j){
                    j++;
                }
                k = 0;
            }
        }
        string v = "";
        i = min(i, j); k = 0;
        while(k < n){
            v += x[(i+k)%n];
            k++;
        }
        return v;
    }

    int minimumGroups(vector<string>& words) {
        unordered_set<string>st;
        for(auto &x : words){
            int n = x.size();
            string a = "", b = "";
            for(int i = 0; i < n; i++){
                if(i % 2 == 0){
                    a += x[i];
                }
                else{
                    b += x[i];
                }
            }
            a = getmincycle(a);
            b = getmincycle(b);
            st.insert(a+"#"+b);
        }

        return st.size();
    }
};