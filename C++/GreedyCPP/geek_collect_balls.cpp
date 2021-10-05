int maxBalls(int N, int M, int a[], int b[]){
    // code here
    int sum1 = 0, sum2 = 0;
    int i = 0, j = 0;
    int ans = 0;
    
    while(i < N  &&  j < M){
        if(a[i] < b[j]){
            sum1 += a[i];
            i++;
        }
        
        else if(b[j] < a[i]){
            sum2 += b[j];
            j++;
        }
        
        
        else {
            sum1 += a[i];
            
            //Handle Duplicates
			while(i+1 < N && a[i+1] == b[j]){
			    i++;
			    sum1 += a[i];
		    }
            
            sum2 += b[j];
            
            //Handle Duplicates
			while(j+1 < M && b[j+1] == a[i]){
			    j++;
			    sum2 += b[j];
		    }
			
			ans += max(sum1, sum2);
			sum1 = sum2 = 0;
			
			i++; j++;
        }
    }
    
    while(i<N){
        sum1 += a[i];
        i++;
    }
    
    while(j<M){
        sum2 += b[j];
        j++;
    }
    
    ans += max(sum1, sum2);
    
    return ans;
}