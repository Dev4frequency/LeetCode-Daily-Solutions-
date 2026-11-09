class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {

        set<int> availableServers;

        for (int server = 0; server < k; server++) {
            availableServers.insert(server);
        }

        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > busyServers;

        vector<int> handledCount(k, 0);

        int n = arrival.size();

        for (int request = 0; request < n; request++) {

            long long currentTime = arrival[request];

            while (!busyServers.empty() &&
                   busyServers.top().first <= currentTime) {

                availableServers.insert(busyServers.top().second);
                busyServers.pop();
            }

            if (availableServers.empty()) {
                continue;
            }

            int preferredServer = request % k;

            auto it = availableServers.lower_bound(preferredServer);

            if (it == availableServers.end()) {
                it = availableServers.begin();
            }

            int assignedServer = *it;

            availableServers.erase(it);

            handledCount[assignedServer]++;

            busyServers.push({
                currentTime + load[request],
                assignedServer
            });
        }

        int maxHandled = *max_element(
            handledCount.begin(),
            handledCount.end()
        );

        vector<int> answer;

        for (int server = 0; server < k; server++) {
            if (handledCount[server] == maxHandled) {
                answer.push_back(server);
            }
        }

        return answer;
    }
};