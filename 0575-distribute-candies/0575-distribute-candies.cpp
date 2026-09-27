class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        
        int n = candyType.size();
        unordered_set<int> uniquecandies;

        for(int candies : candyType){
            uniquecandies.insert(candies); 
        }
          int maxtype = min((int) uniquecandies.size(),n/2);
          return maxtype;
    }
};