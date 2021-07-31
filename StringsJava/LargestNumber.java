/*
Given a list of non-negative integers nums, arrange them such that they form the largest number.

Note: The result may be very large, so you need to return a string instead of an integer.

 

Example 1:

Input: nums = [10,2]
Output: "210"
Example 2:

Input: nums = [3,30,34,5,9]
Output: "9534330"
*/

public class Solution {
     public String largestNumber(int[] num) {
		if(num == null || num.length == 0)
		    return "";
		
		// Convert int array to String array, for string sorting
		String[] arr = new String[num.length];
		for(int i = 0; i < num.length; i++)
		    arr[i] = String.valueOf(num[i]);
			
		// add the two strings once str1 at first and once str2 at first and decide which is bigger
		Comparator<String> comp = new Comparator<String>(){
		    @Override
		    public int compare(String str1, String str2){
		        String s1 = str1 + str2;
				String s2 = str2 + str1;
				return s2.compareTo(s1); // reverse order here,for append() later
		    }
	     };
		
		Arrays.sort(arr, comp);
		if(arr[0].charAt(0) == '0')
			return "0";
            
		StringBuilder sb = new StringBuilder();
		for(String s: arr)
	        sb.append(s);
		
		return sb.toString();
		
	}
}
