import java.util.Arrays;
import java.util.Map;
import java.util.TreeMap;
 
class Main
{
    // Function to efficiently sort an array with many duplicated values
    public static void customSort(int[] arr)
    {
        // create an empty `TreeMap` to store the frequency of array elements
        Map<Integer, Integer> freq = new TreeMap<>();
 
        // store distinct values in the input array as keys and
        // their respective counts as values
        for (int i: arr) {
            freq.put(i, freq.getOrDefault(i, 0) + 1);
        }
 
        // sort the map according to its keys' natural ordering
 
        // since we have used `TreeMap` instead of `HashMap`,
        // keys are already sorted by default
 
        // traverse the sorted map and overwrite the input array with sorted elements
        int i = 0;
        for (var entry: freq.entrySet())
        {
            int value = entry.getValue();
            while (value-- > 0) {
                arr[i++] = entry.getKey();
            }
        }
    }
 
    public static void main(String[] args)
    {
        int[] arr = { 4, 2, 40, 10, 10, 1, 4, 2, 1, 10, 40 };
 
        customSort(arr);
        System.out.println(Arrays.toString(arr));
    }
}
