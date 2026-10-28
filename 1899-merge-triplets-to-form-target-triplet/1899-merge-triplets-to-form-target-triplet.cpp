class Solution {
public:
  bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
    bool foundA = false, foundB = false, foundC = false;

    for (const auto& triplet : triplets) {
      if (triplet[0] > target[0] || triplet[1] > target[1] || triplet[2] > target[2])
        continue;
      if (triplet[0] == target[0]) foundA = true;
      if (triplet[1] == target[1]) foundB = true;
      if (triplet[2] == target[2]) foundC = true;
      if (foundA && foundB && foundC)
        return true;
    }

    return false;
  }
};