class Solution {
public:
    const long long int MOD = (1e9) + 7;
    long long int N;
    //  t[index][profit][people]
    long long t[101][101][101];
    long long int solve(int index, int profit_, int people, int &minProfit, vector<int>& group, vector<int>& profit){
        // if no. of people increases the allowed group size then that scheme will not be taken
        if (people > N) return 0;

        //if index goes out of bound then check if profitable schemes
        if (index >= group.size()){
            if (profit_ >= minProfit){
                return t[index][profit_][people] = 1;
            }else{
                return t[index][profit_][people] = 0;
            }
        }
        // in memoization, if found then return
        if (t[index][profit_][people] != -1){
            return t[index][profit_][people];
        }
        // basic 0-1 knapsack approach of inclusion and exclusion of the certain scheme

        // if any scheme needs to be considered then !!index!! increases for sure, 
        // !!profit_!! will also increase and people will increase

        long long int will_taken = solve(index + 1, min(minProfit, profit_ + profit[index]), people + group[index], minProfit, group, profit) % MOD;

        // if any scheme needs not to be considered then !!index!! increases for sure, 
        // !!profit_!! will also remain same and people will remain same

        long long int will_not_taken = solve(index + 1, min(profit_, minProfit), people, minProfit, group, profit) % MOD;

        return t[index][profit_][people] = (will_taken % MOD + will_not_taken % MOD) % MOD; 
    }

    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        N = n;
        memset(t, - 1, sizeof(t));
        return solve(0, 0, 0, minProfit, group, profit);
    }
};