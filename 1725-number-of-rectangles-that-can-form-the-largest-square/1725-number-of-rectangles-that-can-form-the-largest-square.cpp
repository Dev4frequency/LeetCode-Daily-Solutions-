class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) 
    {
        int sl;
        int larg=0;
        int cnt=0;
        for(int i=0;i<rectangles.size();i++)
        {
            if(rectangles[i][0]<rectangles[i][1])
            {
                sl=rectangles[i][0];
            }
            else  sl=rectangles[i][1];

           larg= max(larg,sl);

        }

         for(int i=0;i<rectangles.size();i++)
        {
            if(rectangles[i][0]<rectangles[i][1])
            {
                sl=rectangles[i][0];
            }
            else  sl=rectangles[i][1];

            if(sl==larg) cnt++;      

        }

        return cnt;
        
    }
};