class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i = 0;
        int j = 0;
        for (auto x : pushed) {
            pushed[i] = x; 
            i++;
            while (i > 0 && pushed[i - 1] == popped[j]) {
                j++;
                i--;
            }
        }return i == 0;
    }
};

// class Solution { // using STACK .. T-n S-n
// public:
//     bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
//         stack<int> ps; // Create a stack to simulate pushing and popping operations.
//         int i = 0; // Index for iterating through the pushed array.
//         int j = 0; // Index for iterating through the popped array.

//         // Iterate through the pushed array.
//         for (i = 0; i < pushed.size(); i++) {
//             ps.push(pushed[i]); // Push the current element onto the stack.

//             // Check if the top element of the stack matches the current element to be popped.
//             while (!ps.empty() && ps.top() == popped[j]) {
//                 j++; // Move to the next element in the popped array.
//                 ps.pop(); // Pop the element from the stack as it matches the popped order.
//             }
//         }

//         // Check if the stack is empty, indicating successful validation of stack sequences.
//         return ps.empty();
//     }
// };