// Java program to search an element in
// an array where difference between all
// elements is 1
 
import java.io.*;
 
class GFG {
     
    // x is the element to be searched
    // in arr[0..n-1] such that all
    // elements differ by at-most k.
    static int search(int arr[], int n,
                            int x, int k)
    {
         
        // Traverse the given array starting
        // from leftmost element
        int i = 0;
         
        while (i < n) {
             
            // If x is found at index i
            if (arr[i] == x)
                return i;
 
            // Jump the difference between
            // current array element and x
            // divided by k We use max here
            // to make sure that i moves
            // at-least one step ahead.
            i = i + Math.max(1, Math.abs(arr[i]
                                      - x) / k);
        }
 
        System.out.println("number is " +
                                "not present!");
        return -1;
    }
 
    // Driver program to test above function
    public static void main(String[] args)
    {
         
        int arr[] = { 2, 4, 5, 7, 7, 6 };
        int x = 6;
        int k = 2;
        int n = arr.length;
         
        System.out.println("Element " + x +
                        " is present at index "
                        + search(arr, n, x, k));
    }
}
 
