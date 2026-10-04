class Solution {
public:
    string truncateSentence(string s, int k) {
        
        stringstream ss(s);
        string word;
        string result;
        int count = 0;

        while(ss >> word) {
            result += word;
            count++;
            if( count == k ) break;
            result += " ";
        }
        return result;
    }
};