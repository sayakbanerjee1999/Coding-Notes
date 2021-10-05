//Using KMP String matching algorithm
//assume s2 = pattern
//s1+s1->text
//so now s2 can be definetely found as a substring in text if they are rotations of each other

class Solution
{
    //Function to check if two strings are rotations of each other or not.
    public static boolean areRotations(String s1, String s2 )
    {
        // Your code here
        boolean ans = false;
        String text = s1+s1;
        if (text.indexOf(s2)!=-1)
            ans = true;
        else
            ans = false;
        return ans;
        
    }
    
}
