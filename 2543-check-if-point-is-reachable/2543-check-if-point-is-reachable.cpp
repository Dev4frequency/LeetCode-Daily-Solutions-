class Solution {
public:
    bool isReachable(int targetX, int targetY) {
        int num = gcd(targetX,targetY);
        return num > 0 && (num & (num - 1)) == 0;
    }
};