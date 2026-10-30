class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        int ans = -1;
        set <int> visited;
        queue <int> q;
        q.push(start);
        visited.insert(start);
        int dist = 0;
        while(!q.empty()){
            int levelSize = q.size();
            for(int i = 0; i < levelSize; i++){
                int curr = q.front();
                q.pop();
                if(curr == goal) return dist;
                for(int j = 0; j < nums.size(); j++){
                    int x = curr + nums[j];
                    int y = curr - nums[j];
                    int z = curr ^ nums[j];

                    if(0 <= x && x <= 1000){
                        if(!visited.count(x)){
                            q.push(x);
                            visited.insert(x);
                        }
                    }else{
                        if(x == goal) return dist + 1;
                    }

                    if(0 <= y && y <= 1000){
                        if(!visited.count(y)){
                            q.push(y);
                            visited.insert(y);
                        }
                    }else{
                        if(y == goal) return dist + 1;
                    }

                    if(0 <= z && z <= 1000){
                        if(!visited.count(z)){
                            q.push(z);
                            visited.insert(z);
                        }
                    }else{
                        if(z == goal) return dist + 1;
                    }
                }
            }
            dist++;
        }
        return -1;
    }
};