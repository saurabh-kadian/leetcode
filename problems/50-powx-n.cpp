class Solution {
public:
    double binPow(double b, long long e){
        // cout << b << " " << e << endl;
        if(e == 0)
            return 1;
        if(e == 1)
            return b;
        if(e == 2)
            return b*b;
        
        double answer;
        if(e%2 == 0){
            answer = binPow(b, e/2);
            return answer*answer;
        }
        return b*binPow(b, e-1);
    }
    double myPow(double x, int n) {
        if(n < 0){
            return 1/binPow(x, (long long)n * -1);
        }
        return binPow(x, n);
    }
};