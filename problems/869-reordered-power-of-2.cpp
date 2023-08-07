class Solution {
public:
    bool reorderedPowerOf2(int n) {
        long a = 1;
        stringstream ss;
        ss << n;
        string key = ss.str();
        sort(key.begin(), key.end());
        while(a < INT_MAX){
            ss.str(string());
            ss << a;
            string test = ss.str();
            sort(test.begin(), test.end());
            if(test == key)
                return true;
            a *= 2;
        }
        return false;
    }
};