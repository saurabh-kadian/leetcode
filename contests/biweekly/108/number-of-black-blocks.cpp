class Solution {
public:
    long long getKey(int x, int y){
        return (x*(long long)1e7) + y;
    }
    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& coordinates) {
        vector<long long> answer(5, 0);
        long long total = (long long)(m-1)*(long long)(n-1);
        unordered_set<long long> blacks;
        for(int i = 0;i < coordinates.size();++i){
            int x = coordinates[i][0];
            int y = coordinates[i][1];
            blacks.insert(getKey(x, y));
        }
        for(int i = 0;i < coordinates.size();++i){
            int x = coordinates[i][0];
            int y = coordinates[i][1];
            // top left
            if(x + 1 < m && y + 1 < n){
                int place = 1;
                place += ((blacks.find(getKey(x    , y + 1)) != blacks.end()) ? 1 : 0);
                place += ((blacks.find(getKey(x + 1, y    )) != blacks.end()) ? 1 : 0);
                place += ((blacks.find(getKey(x + 1, y + 1)) != blacks.end()) ? 1 : 0);
                answer[place]++;
            }
            // top right
            if(x + 1 < m && y - 1 >= 0){
                int place = 1;
                place += ((blacks.find(getKey(x    , y - 1)) != blacks.end()) ? 1 : 0);
                place += ((blacks.find(getKey(x + 1, y    )) != blacks.end()) ? 1 : 0);
                place += ((blacks.find(getKey(x + 1, y - 1)) != blacks.end()) ? 1 : 0);
                answer[place]++;
            }
            // bottom left
            if(x - 1 >= 0 && y + 1 < n){
                int place = 1;
                place += ((blacks.find(getKey(x    , y + 1)) != blacks.end()) ? 1 : 0);
                place += ((blacks.find(getKey(x - 1, y    )) != blacks.end()) ? 1 : 0);
                place += ((blacks.find(getKey(x - 1, y + 1)) != blacks.end()) ? 1 : 0);
                answer[place]++;
            }
            // bottom right
            if(x - 1 >= 0 && y - 1 >= 0){
                int place = 1;
                place += ((blacks.find(getKey(x    , y - 1)) != blacks.end()) ? 1 : 0);
                place += ((blacks.find(getKey(x - 1, y    )) != blacks.end()) ? 1 : 0);
                place += ((blacks.find(getKey(x - 1, y - 1)) != blacks.end()) ? 1 : 0);
                answer[place]++;
            }
        }
        // fix overcounting
        answer[1] /= 1;
        answer[2] /= 2;
        answer[3] /= 3;
        answer[4] /= 4;
        
        // setup empty
        answer[0] = total - (answer[1] + answer[2] + answer[3] + answer[4]);
        return answer;
    }
};