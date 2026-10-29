class LockingTree {
private:
    vector<int> &m_parent;
    vector<int> m_locker;
    vector<vector<int>> m_child;
public:
    LockingTree(vector<int>& parent) : m_parent(parent), m_locker(parent.size()), m_child(parent.size()){
        for (int i = 1;i < parent.size(); ++i) {
            m_child[m_parent[i]].push_back(i);
        }
    }
    
    bool lock(int num, int user) {
        if (m_locker[num] == 0) {
            m_locker[num] = user;
            return true;
        } else {
            return false;
        }
    }
    
    bool unlock(int num, int user) {
        if (m_locker[num] == user) {
            m_locker[num] = 0;
            return true;
        } else {
            return false;
        }
    }
    
    bool recursive_unlock(int num) {
        bool unlock_something = false;
        for (int i : m_child[num]) {
            if (m_locker[i] != 0) {
                unlock_something = true;
                m_locker[i] = 0;
            }
            if (recursive_unlock(i)) unlock_something = true;
        }
        return unlock_something;
    }

    bool upgrade(int num, int user) {
        if (m_locker[num] != 0)
            return false;

        for (int i = num; i != -1; i = m_parent[i]) {
            if (m_locker[i] != 0)
                return false;
        }
        bool unlock_something = recursive_unlock(num);
        if (!unlock_something) {
            return false;
        }
        m_locker[num] = user;
        return true;
    }

};