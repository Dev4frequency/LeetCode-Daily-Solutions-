class Solution {
public:
    vector<int> computeLPS(string pattern) {
        int n = pattern.size();
        vector<int> lps(n, 0);
        
        for (int i = 1; i < n; i++) {
             int prevIdx = lps[i-1];
            while (prevIdx > 0 && pattern[i] != pattern[prevIdx]) {
                prevIdx = lps[prevIdx - 1];
            }
            if (pattern[i] == pattern[prevIdx]) {
                prevIdx++;
            }
            lps[i] = prevIdx;
        }
        return lps;
    }

    int shortestMatchingSubstring(string text, string pattern) {
        int textLength = text.length();
        int patternLength = pattern.length();
        if (patternLength < 2) return 0;

        vector<int> starPositions;
        for (int i = 0; i < patternLength; i++) {
            if (pattern[i] == '*') {
                starPositions.push_back(i);
            }
        }


        string prefix = pattern.substr(0, starPositions[0]);
string middle = pattern.substr(starPositions[0] + 1, starPositions[1] - starPositions[0] - 1);
string suffix = pattern.substr(starPositions[1] + 1,patternLength-starPositions[1] - 1);
        
        int prefixLen=prefix.size();
        int middleLen=middle.size();
        int suffixLen=suffix.size();
        vector<int> prefixLPS = computeLPS(prefix+'#'+text);
        vector<int> middleLPS = computeLPS(middle+'#'+text);
        vector<int> suffixLPS = computeLPS(suffix+'#'+text);

        prefixLPS=vector<int>(prefixLPS.begin()+prefixLen+1,prefixLPS.end());
        middleLPS=vector<int>(middleLPS.begin()+middleLen+1,middleLPS.end());
        suffixLPS=vector<int>(suffixLPS.begin()+suffixLen+1,suffixLPS.end());

        int minLength = INT_MAX;
        int i = 0, j = 0, k = 0;

        while (i + middleLen + suffixLen < textLength) {
            while (i < textLength && prefixLPS[i] != prefixLen) i++;
            if (i >= textLength) break;
            
            while (j < textLength && (j < i + middleLen || middleLPS[j] != middleLen)) j++;
            if (j >= textLength) break;
            
            while (k < textLength && (k < j + suffix.size() || suffixLPS[k] != suffixLen)) k++;
            if (k >= textLength) break;
            
            minLength = min(minLength, k - i + prefixLen);
            i++;
        }
        return minLength == INT_MAX ? -1 : minLength;
    }
};