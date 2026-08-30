class Solution {
public:
    int nextGreaterElement(int n) {
        if(n<10)return -1;
        string num = to_string(n);
        int i = num.size()-2;
        int j = num.size()-1;
        while(i>=0 && num[i]>=num[i+1]){
            i--;
        }
        if(i<0){
            return -1;
        }
        while(num[j]<=num[i]){
            j--;
        }
        swap(num[i],num[j]);
        reverse(num.begin()+i+1,num.end());
        if(stoll(num)>INT_MAX){
            return -1;
        }
        return stoi(num);
    }
};