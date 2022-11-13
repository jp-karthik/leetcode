class Solution {
public:
    vector<string> solution;
    int N;
    int O;
    int C;
    
    void helper(string soFar) {
        if (O == C && O + C == 2 * N) {
            solution.push_back(soFar);
        } else if (O + C == 2 * N) {
            return;
        }
        
        if (O < N) {
            O++;
            helper(soFar + "(");
            O--;
        }
        if (C < N && C < O) {
            C++;
            helper(soFar + ")");
            C--;
        }
        return;
    }
    
    vector<string> generateParenthesis(int n) {
        N = n;
        O = 0;
        C = 0;
        helper("");
        return solution;
    }
};