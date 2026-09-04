class Solution {
public:
    int distinctAverages(vector<int>& num) {
        set<double> s;
        sort(num.begin(),num.end());
        while(num.size()!=0)
        {
            int a=num[0],b=num[num.size()-1];
            s.insert((a+b)/2.0);
            num.erase(num.begin());
            num.erase(num.end()-1);
        }
        return s.size();
    }
};