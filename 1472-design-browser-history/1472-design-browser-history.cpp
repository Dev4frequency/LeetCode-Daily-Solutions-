class BrowserHistory {

    vector<string> v;
    int pos;
    
public:
    BrowserHistory(string homepage) {
        v.push_back(homepage);
        pos = 0;
    }
    void visit(string url) {
        int s = v.size() - 1;
        while (s > pos) {
            v.pop_back();
            s--;
        }
        v.push_back(url);
        pos++;
    }
    string back(int steps) {
        pos = pos - steps;
        if (pos < 0) pos = 0;
        return v[pos];
    }
    string forward(int steps) {
        pos = pos + steps;
        if (pos > v.size() - 1) pos = v.size() - 1;
        return v[pos];
    }
};