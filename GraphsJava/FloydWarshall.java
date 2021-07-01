
class Solution
{
    
    public void shortest_distance(int[][] matrix)
    {
        int n = matrix.length;
	   
	    for(int i = 0; i < n; i++){
	        for(int j = 0; j < n; j++){
	            if(matrix[i][j] == -1)
	                matrix[i][j] = Integer.MAX_VALUE;
	        }
	    }
	    
	    // Applying the formula A[i][j] = min(A[i][j], A[i][k]+A[k][j])
	    for(int k = 0; k < n; k++){
	        for(int i = 0; i < n; i++){
	            for(int j = 0; j < n; j++){
	                
	                // Just make sure that intermediate paths are not Infinity
	                if (matrix[k][j] != Integer.MAX_VALUE && matrix[i][k] != Integer.MAX_VALUE)     
                        matrix[i][j]=Math.min(matrix[i][j], matrix[i][k]+matrix[k][j]);
	            }
	        }
	    }
	    
	    for(int i = 0; i < n; i++){
	        for(int j = 0; j < n; j++){
	            if(matrix[i][j] == Integer.MAX_VALUE)
	                matrix[i][j] = -1;
	        }
	    }
    }
}
