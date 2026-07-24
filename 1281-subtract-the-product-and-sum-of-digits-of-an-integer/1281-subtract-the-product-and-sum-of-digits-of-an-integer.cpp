class Solution {
public:
    int subtractProductAndSum(int n) {
        
        int sum = 0;
        int prod = 1;
        int result = 0;
        
        while(n != 0){
            int digit = n % 10;
            prod *= digit;
            sum += digit;

            n = n / 10;
        }
        result = prod - sum;
        return result;
    }
};