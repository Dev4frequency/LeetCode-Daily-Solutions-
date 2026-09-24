class Solution {
public:
    vector<int> recoverArray(int n, vector<int>& sums) {
        map <int, int> frecv;
        vector <int> v;

        sort (sums.begin(), sums.end());
        for (int i=0; i<n; ++i){
            int sum = sums[1] - sums[0];
            vector <int> l, r;
            bool flag = false;
            for (int j=0; j<sums.size(); ++j){
                if(!frecv[sums[j]]){
                    l.push_back(sums[j]);
                    frecv[sums[j] + sum]++;
                    if (sums[j] == 0)
                        flag = true;
                }   
                else{
                    r.push_back(sums[j]);
                    frecv[sums[j]]--;
                }
            }

            if (flag){
                v.push_back(sum);
                sums = l;
            }
            else{
                v.push_back(-sum);
                sums = r;
            }
        }

        return v;
    }
};