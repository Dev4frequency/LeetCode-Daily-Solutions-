class Solution {
    bool isPrime(int n) {
        if(n < 2) return false;
        if(n % 2 == 0) return n == 2;
        for(long long i = 3; i * i <= n; i += 2) {
            if(n % i == 0) return false;
        }
        return true;
    }

public:
    bool completePrime(int num) {
        string n = to_string(num);
        int m = n.size();

        for(int len = 1; len <= m; len++) {
            int prefix = stoi(n.substr(0, len));
            if(!isPrime(prefix)) return false;

            int suffix = stoi(n.substr(m - len, len));
            if(!isPrime(suffix)) return false;
        }
        return true;
    }
};