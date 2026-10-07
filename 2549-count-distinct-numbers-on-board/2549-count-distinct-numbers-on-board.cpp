class Solution {
public:
    int distinctIntegers(int n) {
    int s;
    if (n <= 1) {
      s = n;
    } else {
      s = n - 1;
    }
  int B[s], k = 0;
  B[k] = n;
  int d = 1;
  while (d <= 1000)
  {
    for (int i = 0; i < k+1; i++)
    {
      for (int j = 1; j <= n; j++)
      {
        if (B[i] % j == 1)
        {
          int countB = 0;
          for (int a = 0; a < s; a++)
          {
            if (j == B[a])
            {
              countB++;
            }
          }
          if (countB == 0)
          {
           B[k + 1] = j;
            k++;
          }
        }
      }
      d++;
      if (d > 1000)
      {
        break;
      }
    }
  }
  sort(B, B + s);
  int countDis = 0;
  for (int i = 0; i < s; i++) {
    countDis++;
  }
  return countDis;
 }
};