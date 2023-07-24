class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        vector<int> answers(pairs.size(), 1);
        for(int i = 1;i < pairs.size();++i){
            for(int j = i-1;j >= 0;--j){
                if(pairs[j][1] < pairs[i][0]){
                    answers[i] = max(answers[i], answers[j] + 1);
                }
            }
        }
        return *max_element(answers.begin(), answers.end());
    }
};
