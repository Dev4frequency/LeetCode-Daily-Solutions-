class Solution {
public:
   vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
  for (vector<int>& vec : image) {
    reverse(vec.begin(), vec.end());
    for (int& n : vec) n = 1 - n;
  }
  return image;
}
};