class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        int prev = 0;
        int maxDuration = 0;
        char ans;

        for(int i = 0; i < releaseTimes.size(); i++){
            if(maxDuration < releaseTimes[i] - prev){
                ans = keysPressed[i];
                maxDuration = releaseTimes[i] - prev;
            }
            else if(maxDuration == releaseTimes[i] - prev && ans < keysPressed[i]){
                ans = keysPressed[i];
                maxDuration = releaseTimes[i] - prev;
            }
            prev = releaseTimes[i];
        }
        return ans;
    }
};