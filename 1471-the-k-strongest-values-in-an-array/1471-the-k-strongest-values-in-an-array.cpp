class Solution {
public:
static bool comp(const pair<int,int>& p1, const pair<int,int>& p2){
        if(p1.first == p2.first){
            return p1.second > p2.second;
        }
        return p1.first > p2.first; 
    }

    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int med = arr[(arr.size()-1)/2];
        vector<pair<int, int>>strongest(arr.size(), {0,0});
        for(int i=0; i<arr.size(); ++i){
            strongest[i].first = abs(arr[i]-med);
            strongest[i].second = arr[i];
        }
        sort(strongest.begin(), strongest.end(), comp);
        vector<int>res;
        for(int i=0; i<k; ++i){
            res.push_back(strongest[i].second);
        }
        return res;
    }
};