class Solution {
public:
    int maxDistance(vector<int>& colors) {
        
        int n = colors.size();   // vector ki length
        
        // case 1: first and last different
        if(colors[0] != colors[n-1])
            return n-1;
        
        int ans = 0;
        
        for(int i = 0; i < n; i++)
        {
            // first house se different
            if(colors[i] != colors[0])
                ans = max(ans, i);
            
            // last house se different
            if(colors[i] != colors[n-1])
                ans = max(ans, n-1-i);
        }
        
        return ans;
    }
};