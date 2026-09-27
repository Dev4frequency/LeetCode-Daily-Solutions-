class Solution {
public:
    string reverseParentheses(string s) {
        int speedUp = [] {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    return 0;
}();
        std::stack<int> st; 
        for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            st.push(i);
        } else if (s[i] == ')') {
            int j = st.top();
            st.pop();
            std::reverse(s.begin() + j + 1, s.begin() + i);
        }
    }

    std::string result;
    for (char c : s) {
        if (c != '(' && c != ')') {
            result += c;
        }
    }

    return result;
}
};