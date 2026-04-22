#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> result;
        for (const string& q : queries) {
            bool canMatch = false;
            for (const string& d : dictionary) {
                int diff = 0;
                for (int i = 0; i < q.length(); ++i) {
                    if (q[i] != d[i]) {
                        diff++;
                    }
                    if (diff > 2) break;
                }
                if (diff <= 2) {
                    canMatch = true;
                    break; 
                }
            }
            if (canMatch) {
                result.push_back(q);
            }
        }
         return result;
    }
};