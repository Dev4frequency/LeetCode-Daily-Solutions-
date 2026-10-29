class Solution {
public:
    static bool comparator(vector<int>& v1, vector<int>& v2) {
        if (v1[0] == v2[0]) {
            return v1[1] > v2[1];
        }
        return v1[0] < v2[0];
    }

    int numberOfWeakCharacters(vector<vector<int>>& prop) {
        sort(prop.begin(), prop.end(), comparator);
        stack<pair<int, int>> st; 
        int count = 0;
        for (auto& c : prop) {
            while (!st.empty() && st.top().first < c[0] && st.top().second < c[1]) {
                count++;
                st.pop();
            }
            st.push(make_pair(c[0], c[1])); 
        }

        return count; 
    }
};