class Solution {
public:
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {

        vector<long long> out;
        out.reserve(queries.size());

        long long const first = pow(10L, (intLength-1)/2);
        long long count = 9*first;

        for (auto q : queries) {
            if (q > count) out.push_back(-1);
            else {
                long long p = first + q - 1;
                long long r = intLength & 1 ? p/10 : p;
                while (r) {
                    p = p*10 + (r % 10);
                    r /= 10;
                }
                out.push_back(p);
            }
        }

        return out;
    }
};