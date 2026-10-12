class Solution {
public:
    vector<int> decimalRepresentation(int n) 
    {
        vector<int> ans;
        long long poww = 1;
        while (n != 0) 
        {
            long long div = pow(10, poww);
            int num = n % div;
            if (num != 0) 
            {
                ans.push_back(num);
            }
            n = n - num;
            poww++;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};