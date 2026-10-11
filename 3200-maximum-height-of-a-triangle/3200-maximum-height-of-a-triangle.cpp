class Solution {
public:
    int check(int a,int b) {
        int h=0,flag=true,l=1;
        while(a>0 || b>0) {
            if(flag==true) {
                if(a>=l) {
                    a=a-l;
                } else
                    break;
            } else {
                if(b>=l) {
                    b=b-l;
                } else
                    break;
            }
            h++;
            l++;
            flag = !flag;
        }
        return h;
    }
    int maxHeightOfTriangle(int r, int b) {
        int k1=check(r,b);
        int k2=check(b,r);
        return max(k1,k2);
    }
};