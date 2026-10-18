class TopVotedCandidate {
private:
    vector<int> times;
    vector<int> leaders;
    
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        this->times = times;
        unordered_map<int, int> voteCount;
        int leader = -1, maxVotes = 0;
        for (int i = 0; i < persons.size(); i++) {
            int p = persons[i];
            voteCount[p]++;
            if (voteCount[p] >= maxVotes) {
                leader = p;
                maxVotes = voteCount[p];
            }

            leaders.push_back(leader);
        }
    }

    int q(int t) {
        int idx = upper_bound(times.begin(), times.end(), t) - times.begin() - 1;
        return leaders[idx];
    }
};