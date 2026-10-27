class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>hp;

        for(int i = 0;i<tasks.size();i++){
            hp.push({tasks[i][0],{tasks[i][1],i}});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>st;
        int counter = hp.top().first;
        vector<int>ans;

        while(!hp.empty()){
            auto task = hp.top();
            if(task.first <= counter){
                st.push({task.second.first,task.second.second});
                hp.pop();
            }

            else if(!st.empty()){
                auto currentTask = st.top();
                st.pop();
                counter +=currentTask.first;
                ans.push_back(currentTask.second);
            }
            else{
                counter = task.first;
            }
        }
        while(!st.empty()){
            ans.push_back(st.top().second);
            st.pop();
        }
        return ans;
    }
};