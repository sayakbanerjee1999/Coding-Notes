class Solution {
    public int firstMissingPositive(int[] A) {
        //idea is to place ith number at ith position ny swap  operation
         //leave negative nums and nums>size(nums) as they are
         //ans will be then first index i that does not have i in its value
        int i = 0;
        while(i < A.length){
            //num 2 should go to index 2-1=1
             //ignore if nums[i] is negative or greater than length and if equal already
             //else swap the values
            if(A[i] == i+1 || A[i] <= 0 || A[i] > A.length) 
                i++;
            else if(A[A[i]-1] != A[i]) 
                swap(A, i, A[i]-1);
            else 
                i++;
        }
        //reinitialie
        i = 0;
        //now the first index whose value is not equal to i is answer
        //if all are present so smallest is n+1
        while(i < A.length && A[i] == i+1) 
            i++;
        return i+1;
    }
    //to swap elements
    private void swap(int[] A, int i, int j){
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
}
