class RandomizedCollection {
public:
    vector<int> nums;
    unordered_map<int, unordered_set<int>> mp;
    RandomizedCollection() {}

    bool insert(int val) {
        nums.push_back(val);
        mp[val].insert(nums.size() - 1);
        return mp[val].size() == 1;
    }

    bool remove(int val) {
        if (mp[val].empty())
            return false;

        int idx = *mp[val].begin();
        mp[val].erase(idx);

        int last = nums.back();
        nums[idx] = last;

        mp[last].insert(idx);
        mp[last].erase(nums.size() - 1);
        nums.pop_back();
        return true;
    }

    int getRandom() { return nums[rand() % nums.size()]; }
};