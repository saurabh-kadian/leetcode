class Solution {
public:
    int spaceOptimized(vector<vector<char>>& matrix){
        vector<int> answer(matrix[0].size(), 0);
        int maxi = 0;
        for(int i = 0;i < matrix.size();++i){
            vector<int> temp(answer.size(), 0);
            for(int j = 0;j < temp.size();++j){
                if(i == 0){
                    temp[j] = (matrix[i][j] == '1' ? 1 : 0);
                    maxi = max(maxi, temp[j]);
                    continue;
                }
                if(matrix[i][j] == '0'){
                    temp[j] = 0;
                    continue;
                }
                maxi = max(maxi, 1);
                if(j == 0){
                    temp[j] = 1;
                }
                else
                    temp[j] = min(temp[j-1], min(answer[j-1], answer[j])) + 1;
                maxi = max(maxi, temp[j]);
            }
            answer = temp;
        }
        return maxi*maxi;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        return spaceOptimized(matrix);

        // easy to understand
        vector<vector<int>> answer(matrix.size(), vector<int>(matrix[0].size(), 0));
        int maxi = 0;
        for(int i = 0;i < matrix.size();++i){
            for(int j = 0;j < matrix[i].size();++j){
                answer[i][j] = matrix[i][j] - '0';
                maxi = max(maxi, answer[i][j]);
            }
        }
        for(int i = 0;i < matrix.size();++i){
            for(int j = 0;j < matrix[i].size();++j){
                if(matrix[i][j] == '0'){
                    answer[i][j] = 0;
                    continue;
                }
                if(i == 0 && j == 0)
                    continue;
                else if(i == 0)
                    answer[i][j] = 1;
                else if(j == 0)
                    answer[i][j] = 1;
                else
                    answer[i][j] = min(answer[i-1][j], 
                                       min(answer[i-1][j-1], answer[i][j-1])) 
                                    + 1;
                maxi = max(maxi, answer[i][j]);
            }
        }
        return maxi*maxi;
    }
};