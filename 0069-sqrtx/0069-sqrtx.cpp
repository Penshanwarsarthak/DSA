class Solution {
public:

    long long int binarySearch(int n){
        int st = 0;
        int end = n;
        long long int mid = st + (end - st) / 2;
        long long int ans = 0;

        while(st <= end){
            
            long long int square = mid * mid;

            if(square == n){
                return mid;
            }
            if(square < n){
                ans = mid;
                st = mid + 1;
            }
            else {
                end = mid - 1;
            }
            mid = st + (end - st) / 2;
        }
        return ans;
    }


    int mySqrt(int x) {
        
        return binarySearch(x);
    }
};