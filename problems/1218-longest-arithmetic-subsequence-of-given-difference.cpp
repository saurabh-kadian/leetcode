class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> cache;
        cache[arr[0]] = 1;
        int maxi = 1;
        for(int i = 1;i < arr.size();++i){
            if(cache.find(arr[i]-difference) != cache.end())
                cache[arr[i]] = cache[arr[i]-difference] + 1;
            else
                cache[arr[i]] = 1;
            maxi = max(maxi, cache[arr[i]]);
        }
        return maxi;
    }
};
