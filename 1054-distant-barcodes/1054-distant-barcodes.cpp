class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int, int> ct;
        for(int barcode : barcodes){
            ct[barcode]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq;
        

        for(auto it = ct.begin(); it != ct.end(); it++){
            pq.push(make_pair(it->second, it->first));
        }
        
        vector<int> ans;
        
        while(pq.size() >= 2){
            pair<int, int> a = pq.top(); pq.pop();
            pair<int, int> b = pq.top(); pq.pop();
            
            ans.push_back(a.second);
            ans.push_back(b.second);
            
            a.first--;
            b.first--;
            
            if(a.first > 0) pq.push(a);
            if(b.first > 0) pq.push(b);
        }
        
        if(pq.size() > 0){
            pair<int, int> a = pq.top(); pq.pop();
            ans.push_back(a.second);
        }
        
        return ans;
    }
};