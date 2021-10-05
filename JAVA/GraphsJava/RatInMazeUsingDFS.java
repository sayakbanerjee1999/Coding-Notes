// m is the given matrix and n is the order of matrix ; 0 for blockage 1 for free
class Solution {
    static ArrayList<String> res = new ArrayList<String>();
    static String path = "";

    public static ArrayList<String> findPath(int[][] m, int n) {
        // Your code here
        boolean visited[][] = new boolean[n][n];
        // find the valid paths
        printPath(0, 0, m, n, visited);
        //to remove duplicates from the final arraylist
        ArrayList<String> resWithoutDup = new ArrayList<String>();
        for (String s: res){
            if(!resWithoutDup.contains(s)){
                resWithoutDup.add(s);
            }
        }
        Collections.sort(resWithoutDup);
        return resWithoutDup;
    }
    
    public static void printPath(int row, int col, int[][] m, int n, boolean visited[][]){
        // To check the initial point (i.e. (0, 0)) to start the paths.
        if (row == -1 || row == n || col == -1 || col == n || visited[row][col] || m[row][col] == 0)
            return;
        // If reach the last cell (n-1, n-1) then store the path and return
        if (row == n-1 && col == n-1)
        {
            res.add(path);
            return;
        }
        // Then mark the cell as visited
        visited[row][col] = true;
        
        // Try for all the 4 directions (down, left, right, up) in the given order to get the
        // paths in lexicographical order(imp)
     
        // Check if downward move is valid
        if (isSafe(row + 1, col, m, n, visited))
        {
            path += 'D';
            printPath(row+1, col, m, n, visited);
            path = path.substring(0, path.length() - 1);
        }
     
        // Check if the left move is valid
        if (isSafe(row, col - 1, m, n, visited))
        {
            path += 'L';
            printPath(row, col-1, m, n, visited);
            path = path.substring(0, path.length() - 1);
        }
     
        // Check if the right move is valid
        if (isSafe(row, col + 1, m, n, visited))
        {
            path += 'R';
            printPath(row, col+1, m, n, visited);
            path = path.substring(0, path.length() - 1);
        }
     
        // Check if the upper move is valid
        if (isSafe(row-1, col, m, n, visited))
        {
            path += 'U';
            printPath(row-1, col, m, n, visited);
            path = path.substring(0, path.length() - 1);
        }
     
        // Mark the cell as unvisited for other possible paths
        visited[row][col] = false;
    } 
    
    // Function returns true if the
    // move taken is valid else
    // it will return false.
    static boolean isSafe(int row, int col, int m[][],
                          int n, boolean visited[][])
    {
        if (row == -1 || row == n || col == -1 ||
             col == n || visited[row][col] ||
                         m[row][col] == 0)
            return false;
     
        return true;
    }
    
}
