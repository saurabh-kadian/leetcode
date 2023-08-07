class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> modulus(k, 0);
        for(int i = 0;i < arr.size();++i){
            if(arr[i] < 0)
                modulus[((arr[i]%k) + k)%k]++;
            else
                modulus[arr[i]%k]++;
        }
        for(int i = 1;i < k;++i){
            if(modulus[i] != modulus[k-i])
                return false;
            if(i == k/2 && k%2 == 0 && modulus[i]%2 == 1){
                return false;
            }
        }
        return true;
    }
};