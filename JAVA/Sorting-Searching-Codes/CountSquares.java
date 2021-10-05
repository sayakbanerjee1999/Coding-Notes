class Solution {
    //using binary search
    static int countSquares(int x) {
        // code here
        if (x == 0 || x == 1)
            return 0;
 
        // Staring from 1, try all numbers until
        // i*i is greater than or equal to x.
        int i = 1, result = 1;
         
        while (result < x) {
            i++;
            result = i * i;
        }
        return i - 1;
        
    }
};
