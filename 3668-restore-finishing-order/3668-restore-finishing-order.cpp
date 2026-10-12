#include<unordered_map>
class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        std::unordered_map<int,int> position;
        std::vector<int> answer = friends;
        for(int i = 0;i<order.size();i++){
            position[order[i]] = i;
        }
        sort(answer.begin(),answer.end(),[&](int a , int b){
            return position[a] < position[b];
        });
        return answer;
    }
};