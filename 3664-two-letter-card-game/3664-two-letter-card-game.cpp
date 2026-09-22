class Solution {
public:
    int score(vector<string>& cards, char x) {
        unordered_map<string,int>mp1;
        unordered_map<string,int>mp2;

        int left=0;
        int right=0;
        int both=0;
        int max_left=0;
        int max_right=0;

        for(int i=0;i<cards.size();i++)
        {
            if(cards[i][0]==x && cards[i][1]!=x)
            {
                left++;
                mp1[cards[i]]++;
                max_left=max(max_left,mp1[cards[i]]);
            }
            else if(cards[i][0]!=x && cards[i][1]==x)
            {
                right++;
                mp2[cards[i]]++;
                max_right=max(max_right,mp2[cards[i]]);
            }
            else if(cards[i][0]==x && cards[i][1]==x)
            {
                both++;
            }
        }

        int result=0;
        int l_pair=min(left/2,left-max_left);
        int leftover=left-2*l_pair;

        int r_pair=min(right/2,right-max_right);
        leftover+=right-2*r_pair;

        result=l_pair+r_pair+min(leftover,both);
        if(both>leftover)
        {
            result+=min(l_pair+r_pair,(both-leftover)/2);
        }

        return result;
    }
};