class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        map<int, Employee*> EmployeeMap;
        map<int, bool> vis;

        for (auto in : employees) {
            EmployeeMap[in->id] = in;
            vis[in->id] = false;
        }
        queue<Employee*> q;
        if (EmployeeMap.find(id) == EmployeeMap.end()) {
            return 0;
        }
        q.push(EmployeeMap[id]);
        vis[id] = true;

        int total = 0;
        while (!q.empty()) {
            auto tp = q.front();
            q.pop();
            
            total += tp->importance;
            for (auto in : tp->subordinates) {
                if (!vis[in] && EmployeeMap.find(in) != EmployeeMap.end()) {
                    q.push(EmployeeMap[in]);
                    vis[in] = true;
                }
            }
        }

        return total;
    }
};