class Solution {
public:
    int numSquares(int n) {
        vector<int> squares;
        for(int i = 1;i <= 101;i++)
            squares.push_back(i*i);
        vector<int> dp(n + 5, 1e6);
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 0;i <= n;++i){
            for(int j = 0;j < squares.size();++j){
                if(i - squares[j] >= 0)
                    dp[i] = min(dp[i], dp[i-squares[j]] + 1);
            }
        }
        return dp[n];
    }
};

///////////////////////// OPTIMIZED //////////////////////////////////
class Solution {
public:
    int numSquares(int n) {
        int dp[n+5];
        memset(&dp[0], 1e6, sizeof(dp));
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 0;i <= n;++i){
            for(int j = 0;j <= 101;++j){
                if(i - j*j >= 0)
                    dp[i] = min(dp[i], dp[i - j*j] + 1);
            }
        }
        return dp[n];
    }
};