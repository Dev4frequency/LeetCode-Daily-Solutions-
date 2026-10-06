class Solution {
public:
	int minAddToMakeValid(string s) {
		stack<int> st;
		int count=0;
		for(auto it : s){
			if(it == '(')
				st.push(it);
			else if(it == ')') {
				if(!st.empty() && st.top() == '(')
					 st.pop();
				else    st.push(it);
			}
		}
		return st.size();
	}
};