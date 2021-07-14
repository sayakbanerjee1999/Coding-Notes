/* Implement the next permutation, which rearranges the list of numbers into Lexicographically next greater permutation of list of numbers. If such arrangement is not possible, it must be rearranged to the lowest possible order i.e. sorted in an ascending order. You are given an list of numbers arr[ ] of size N.

Example 1:

Input: N = 6
arr = {1, 2, 3, 6, 5, 4}
Output: {1, 2, 4, 3, 5, 6}
Explaination: The next permutation of the 
given array is {1, 2, 4, 3, 5, 6}.  */


class Solution{
    static List<Integer> nextPermutation(int N, int arr[]){
        // code here
        //List<Integer> res = new ArrayList<>();
        int idx = -1;
        for (int i=N-1;i>0;i--){
            //to get the first a[i-1]<a[i] from right side and store the index
            if (arr[i-1]<arr[i]){
                idx = i;
                break;
            }
        }
        List<Integer> res = new ArrayList<Integer>();
            for (int i=0;i<N;i++){
                res.add(arr[i]);
            }
        //if nothing found means its in decreasing order so just reverse and return
        if (idx==-1){
            Collections.reverse(res);
            return res;
        } else{
            //store the prev index
            int prev = idx;
            for (int i=idx+1;i<N;i++){
                //if arr[i] greater than the ele at idx-1 and also smaller than the prev value
                if (arr[i]>arr[idx-1] && arr[i]<arr[prev]){
                    prev = i;
                }
            }
            //swapping the array positions
            
            Collections.swap(res, idx-1, prev); 
            //for storing the remaining array from idx to end in reverse order
            List<Integer> temp = new ArrayList<Integer>();
            
            for (int i=0;i<=idx-1;i++){
                temp.add(res.get(i));
            }
            for (int i=N-1;i>=idx;i--){
                temp.add(res.get(i));
            }
            return temp;
        }
        
    }
}
