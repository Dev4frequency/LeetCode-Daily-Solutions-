class OrderedStream {
private:
    vector<string> res;
    int i;
public:
    OrderedStream(int n) {
        res.resize(n);
        i=0;
    }
    vector<string> insert(int idKey, string value) {
        res[idKey-1]=value;
        vector<string> vc;
        while(i<res.size() and res[i].size()!=0){
            vc.push_back(res[i]);
            i++;
        }
        return vc;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */