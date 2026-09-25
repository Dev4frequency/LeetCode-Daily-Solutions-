class Solution {
public:

    int cost(int x, int target) {
        return min(x, abs(x - target));
    }

    int cost(int x, int rem, int target) {
        if (x < target) {
            if (x + rem > target) return 0;
            else return target - (x + rem);
        } else {
            return x - target;
        }
    }
    int makeStringGood(string s) {
        map<char, int> freq;
        for(char c : s) {
            freq[c - 'a']++;
        }
        for(char c = 'a'; c <= 'z'; c++) {
            freq[c - 'a'] = freq[c - 'a'];
        }

        vector<int> arr;
        for(auto [c, v] : freq) {
            arr.push_back(v);
        }

        vector<int> targets;
        for(int i = 0; i < 26; i++) {
            targets.push_back(arr[i]);
            if (i + 1 < 26) {
                targets.push_back((arr[i] + arr[i+1])/2);
                targets.push_back((arr[i] + arr[i+1] + 1)/2);
                targets.push_back((arr[i] + arr[i+1]));
            }
        }

        int ans = s.size();
        for(int target : targets) {
            vector<int> f(27);
            f[26] = 0;
            f[25] = cost(arr[25], target);
            for(int i = 24; i >= 0; i--) {
                int x = arr[i];
                f[i] = cost(x, target) + f[i + 1];
                
                if (i + 1 < 26 and arr[i + 1] > 0) {
                    int y = arr[i+1];
                    int rem = (x > target? x - target : x);
                    f[i] = min(f[i], rem + cost(y, rem, target) + f[i + 2]);
                }
            }

            ans = min(ans, f[0]);
        }

        return ans;
    }
};