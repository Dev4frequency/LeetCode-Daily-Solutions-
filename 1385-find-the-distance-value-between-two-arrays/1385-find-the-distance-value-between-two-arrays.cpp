class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
		int r = 0; set<int> s(arr2.begin(), arr2.end());
		for (auto e : arr1) {
           if (s.upper_bound(e + d) == s.lower_bound(e - d)) r++;
        }
		return r;
	}
};