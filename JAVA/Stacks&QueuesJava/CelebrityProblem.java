class Solution
{ 
    static boolean knows(int M[][], int a, int b)
    {
        boolean res = (M[a][b] == 1) ? true : false;
        return res;
    }
    //Function to find if there is a celebrity in the party or not.
    int celebrity(int M[][], int n)
    {
    	// code here 
    	// Handle trivial 
        // case of size = 2
        Stack<Integer> s = new Stack<>();
    
        // Celebrity
        int C; 
    
        // Push everybody to stack
        for (int i = 0; i < n; i++)
            s.push(i);
    
        // Extract top 2
     
    
        // Find a potential celebrity
        while (s.size() > 1)
        {   int A = s.pop();
            int B = s.pop();
            if (knows(M, A, B))
            {
              //if a knows b then a cant be celebrity
              //hence push b
              s.push(B);
            }
            else
            {
              //else push a
              s.push(A);
            }
        }
        // If there are only two people 
        // and there is no
        // potential candicate
        if(s.empty())
            return -1;
      
      
        // Potential candidate is now at top
        C = s.pop();
    
        // Check if C is actually a celebrity or not-final check
        for (int i = 0; i < n; i++)
        {
            // If any person doesn't know 'C' or 'C' knows any person, return -1
            if ( (i != C) && (knows(M, C, i) || !knows(M, i, C)) )
                return -1;
        }
    
        return C;
        }
}
