class Solution {
public:
    int multi(int b, int e, int& mod){
        if(e == 1)  return b%mod;
        if(e == 2)  return ((b%mod) * (b%mod))%mod;
        return (b%mod * multi(b, e-1, mod)%mod)%mod;
    }
    int removeLastValue(int a, int index, vector<int>& b, int& mod){
        return multi(removeLastDecimal(a, index-1, b, mod), 10, mod)%mod;
    }
    int removeLastDecimal(int a, int index, vector<int>& b, int& mod){
        if(index == 0)
            return (multi(a, b[index], mod)%mod);
        if(b[index] == 0)
            return removeLastValue(a, index, b, mod);
        return ((multi(a, b[index], mod)%mod) * (removeLastValue(a, index, b, mod)%mod))%mod;
    }
    int superPow(int a, vector<int>& b) {
        int mod = 1337;
        return removeLastDecimal(a, b.size() - 1, b, mod);
    }
};