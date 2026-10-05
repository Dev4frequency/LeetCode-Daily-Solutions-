class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        int i, j;
        double taxes;
        for(i=0 ; i<brackets.size() ; i++)
        {
            if(i==0)
            {
                if(income>=brackets[i][0])
                {
                    taxes += (double)brackets[i][0]*brackets[i][1]/100;
                    income -= brackets[i][0];
                }
                else
                {
                    taxes += (double)income*brackets[i][1]/100;
                    return taxes;
                }
            }
            else
            {
                if(income>=(brackets[i][0]-brackets[i-1][0]))
                {
                    taxes += (double)(brackets[i][0]-brackets[i-1][0])*brackets[i][1]/100;
                    income -= (brackets[i][0]-brackets[i-1][0]);
                }
                else
                {
                    taxes += (double)income*brackets[i][1]/100;
                    return taxes;
                }
            }
        }
        return taxes;
    }
};