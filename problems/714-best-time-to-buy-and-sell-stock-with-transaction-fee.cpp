class Solution {
public:
    unordered_map<string, int> cache;
    int solve(int index, bool canBuy, vector<int>& prices, int& fee){
        if(index == prices.size())
            return 0;
        
        stringstream ss;
        ss << index << "-" << canBuy;
        string key = ss.str();
        if(cache.find(key) != cache.end())
            return cache[key];

        if(canBuy){
            return max(solve(index + 1, false, prices, fee) - prices[index],
                       solve(index + 1, true, prices, fee));
        }
        return max(solve(index + 1, true, prices, fee) + prices[index] - fee,
                   solve(index + 1, false, prices, fee));
    }
    int bottomUp(vector<int>& prices, int fee){
        vector<vector<int> > dp(prices.size() + 5, vector<int>(2, 0));
        for(int i = prices.size()-1;i >= 0;--i){
            dp[i][0] = max(dp[i+1][1] + prices[i] - fee, dp[i+1][0]);
            dp[i][1] = max(dp[i+1][0] - prices[i], dp[i+1][1]);
        }
        return dp[0][1];
    }
    int maxProfit(vector<int>& prices, int fee) {
        return bottomUp(prices, fee);
        // TOP-DOWN
        // return solve(0, true, prices, fee);
    }
};