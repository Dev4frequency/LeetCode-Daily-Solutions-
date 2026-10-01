class Solution {
	public:
	bool isValid(string s) {
		stack<char> st;
		for(auto& it: s){
			if(it == '[' || it == '{' || it == '(')
				st.push(it);
			else if(!st.empty()){
				auto tp = st.top();
				if(it == ')' && tp == '(' || it == '}' && tp == '{' || it == ']' && tp == '[')
					st.pop();
				else    return false;
			}
			else
				return false;
		}
		if(st.empty())
			return true;
		else    return false;
	}
};