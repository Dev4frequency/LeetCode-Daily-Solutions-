class Solution {
public:
string expression;
 int pos = 0;
  set<string> unite(const set<string>& a, const set<string>& b ){
    set<string> result = a;
     result.insert(b.begin(), b.end());
     return result;
  }
  set<string> multiply(const set<string>& a, const set<string>& b){
    set<string> result;
    for(const string& x:a){
        for(const string& y:b){
            result.insert(x+y);
        }
    }
    return result;
  }
   set<string> parseExpression() {
        set<string> result;
        set<string> current = {""};

        while (pos < expression.size() && expression[pos] != '}') {
            if(expression[pos] == ','){
                result = unite(result, current);
                current = {""};
                pos++;
            }
            else{
                set<string> next;
                if(expression[pos] == '{'){
                    pos++;
                    next = parseExpression();
                    pos++;
                }
                  else {
                    next.insert(string(1, expression[pos]));
                    pos++;
                }

                current = multiply(current, next);
            }
        }
        result = unite(result, current);
        return result;
   }
    vector<string> braceExpansionII(string expression) {
        this -> expression = expression;
        pos = 0;
        set<string> result = parseExpression();
        return vector<string>(result.begin(), result.end());
    }
};