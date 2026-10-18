class Solution {
public:
    string largestTimeFromDigits(vector<int>& arr) {
        string ret = "";
        int maxTime = -1;
        sort(arr.begin(), arr.end());
        do {
            int hours = arr[0] * 10 + arr[1];
            int minutes = arr[2] * 10 + arr[3];
            if (hours < 24 && minutes < 60) {
                int totalMinutes = hours * 60 + minutes;
                if (totalMinutes > maxTime) {
                    maxTime = totalMinutes;
                    ret = (hours < 10 ? "0" : "") + to_string(hours) + ":" + (minutes < 10 ? "0" : "") + to_string(minutes);
                }
            }
        } while (next_permutation(arr.begin(), arr.end()));

        return ret;
    }
};