class Solution {
public:
    bool palindrome(string str){
        int start=0,end=str.size()-1;
        while(start<=end){
            if(str[start]!=str[end]) return false;
            start++,end--;
        }
        return true;
    }
    int count(int num){
        int inc=num,dec=num;
        string binary=bitset<32>(num).to_string();
        binary.erase(0,binary.find_first_not_of('0'));
        while(true){
            
            string a=bitset<32>(inc).to_string();
            string b=bitset<32>(dec).to_string();
            a.erase(0,a.find_first_not_of('0'));
            b.erase(0,b.find_first_not_of('0'));
            if(palindrome(a)) return inc-num;
            
            if(palindrome(b)) return num-dec;
            
            inc++;
            dec--;
        }
        return -1;

    }
    vector<int> minOperations(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            ans[i]=(count(nums[i]));
        }
        return ans;
    }
    
};