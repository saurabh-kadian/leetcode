class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> answer = triangle;
        for(int i = 0;i < answer.size();++i){
            for(int j = 0;j < answer[i].size();++j){
                if(i == 0)
                    continue;
                if(j == 0)
                    answer[i][j] = answer[i-1][j] + triangle[i][j];
                else if(j == answer[i].size() - 1)
                    answer[i][j] = answer[i-1][j-1] + triangle[i][j];
                else
                    answer[i][j] = min(answer[i-1][j], answer[i-1][j-1]) + triangle[i][j];
            }
        }
        return *min_element(answer[answer.size()-1].begin(),
                            answer[answer.size()-1].end());
    }
};