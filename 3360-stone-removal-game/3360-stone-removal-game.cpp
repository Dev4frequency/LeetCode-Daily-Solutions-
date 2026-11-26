#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canAliceWin(int n) 
    {
        int toRemove = 10;
        int moves = 0;
        while (toRemove > 0 && n >= toRemove) 
        {
            n -= toRemove;
            toRemove--;
            moves++;
        }
        return (moves % 2 == 1);
    }
};