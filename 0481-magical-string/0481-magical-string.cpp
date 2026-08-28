class Solution {
public:
    int magicalString(int n) {
        if (n <= 3) return 1;

        vector<int> s = {1, 2, 2};

        int head = 2;
        int num = 1;
        int onesCount = 1;

        while (s.size() < n) {
            int freq = s[head];

            for (int i = 0; i < freq && s.size() < n; i++) {
                s.push_back(num);

                if (num == 1)
                    onesCount++;
            }

            num = (num == 1) ? 2 : 1;
            head++;
        }

        return onesCount;
    }
};