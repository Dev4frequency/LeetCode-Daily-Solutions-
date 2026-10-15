class Solution {
public:
vector<int> prefixSums;
vector<vector<int>>rectangles;

    Solution(vector<vector<int>>& rects) {
        rectangles=rects;
        int numRectangles = rectangles.size();
        prefixSums.resize(numRectangles + 1, 0);

        for(int i=0;i<numRectangles;i++){
             prefixSums[i + 1] = prefixSums[i] + 
                                (rectangles[i][2] - rectangles[i][0] + 1) * 
                                (rectangles[i][3] - rectangles[i][1] + 1);
        }
        srand(static_cast<unsigned int>(time(nullptr)));
    }
    
    vector<int> pick() {
         int target = 1 + rand() % prefixSums.back();
          int idx = static_cast<int>(lower_bound(prefixSums.begin(), prefixSums.end(), target) - prefixSums.begin()) - 1;
        auto& rect = rectangles[idx];
        int x = rect[0] + rand() % (rect[2] - rect[0] + 1);
        int y = rect[1] + rand() % (rect[3] - rect[1] + 1);
        return {x, y};
    }
};