class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> answer(cost.size(), 0);
        answer[0] = cost[0];
        answer[1] = cost[1];
        for(int i = 2;i <= answer.size();++i){
            if(i == answer.size()){
                return min(answer[i-1], answer[i-2]);
            }
            answer[i] = min(answer[i-1], answer[i-2]) + cost[i];
        }
        return min(answer[0], answer[1]);
    }
};