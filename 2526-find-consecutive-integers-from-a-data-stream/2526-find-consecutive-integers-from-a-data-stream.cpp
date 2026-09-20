class DataStream {
public:
    int cap,val,count = 0;
    DataStream(int value, int k) {
        cap = k;
        val = value;
    }
    
    bool consec(int num) {
        if(num == val){
            count++;
            if(count >= cap){
                return true;
            }
            return false;
        }
        count = 0;
        return false;
    }
};