class Solution {
public:
    bool is_pal(string a) { 
        int i = 0, j = a.size() - 1;
        while (i <= j && a[i] == a[j]) i++, j--;
        return i > j;
    }

    bool func(string &a, string &b) { 
        int na = a.size(), nb = b.size(), i = 0, j = b.size() - 1;
        while (i < na && j > -1 && a[i] == b[j]) i++, j--;
        return i == na || is_pal(a.substr(0, i) + b.substr(i)) || is_pal(b.substr(0, i) + a.substr(i)) || is_pal(a.substr(0, j + 1) + b.substr(j + 1)) || is_pal(b.substr(0, j + 1) + a.substr(j + 1));
    }

    bool checkPalindromeFormation(string a, string b) {
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
        return func(a, b) || func(b, a);
    }
};