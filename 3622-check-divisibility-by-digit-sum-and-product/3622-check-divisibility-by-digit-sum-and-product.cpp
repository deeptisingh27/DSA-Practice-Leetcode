class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int prod = 1;

        int x = n;
        while(x>0){
            int dig = x%10;

            sum += dig;
            prod *= dig;

            x /= 10;
        }

        return n % (sum+prod) == 0;
    }
};