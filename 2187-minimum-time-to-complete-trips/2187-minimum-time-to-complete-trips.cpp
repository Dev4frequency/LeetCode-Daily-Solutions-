class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long lo = *min_element(time.begin(), time.end()); 
    long long hi = *max_element(time.begin(), time.end()) * (long long) totalTrips; 
    
    while (lo < hi) {
        long long mid = lo + (hi - lo) / 2;
        long long trips = 0;
        for (int t : time) {
            trips += mid / t;
            if (trips >= totalTrips) break;
        }
        if (trips >= totalTrips) hi = mid; 
        else lo = mid + 1; 
    }
    return lo;
    }
};