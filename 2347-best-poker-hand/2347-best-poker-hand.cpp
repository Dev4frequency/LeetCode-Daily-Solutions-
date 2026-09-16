class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        vector<int> suitCount(4, 0);
        for (char suit : suits) {
            if (++suitCount[suit - 'a'] == 5)
                return "Flush"; 
        }
        vector<int> rankCount(14, 0); 
        bool hasPair = false;
        for (int r : ranks) {
            if (++rankCount[r] == 3)
                return "Three of a Kind"; 
            if (rankCount[r] == 2)
                hasPair = true;
        }
        if (hasPair) return "Pair"; 
        return "High Card";         
    }
};