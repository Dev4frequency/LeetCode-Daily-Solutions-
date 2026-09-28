class Solution
 {
 public:
  bool validMountainArray(vector<int>& arr) 
{
    int n = arr.size();
    if (n < 3) return false;

    int left = 0, right = n - 1;

    while (left + 1 < n && arr[left] < arr[left + 1]) ++left;
    while (right > 0 && arr[right] < arr[right - 1]) --right;

    return left > 0 && right < n - 1 && left == right;
  }
};