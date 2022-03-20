void sort012(int a[], int n)
{
        // coode here 
        int count[] = {0, 0, 0};
        
        for(int i = 0; i < n; i++){
            if(a[i] == 0)
                count[a[i]]++;
            else if(a[i] == 1)
                count[a[i]]++;
            else if(a[i] == 2)
                count[a[i]]++;
        }
        
        int index = 0;
        int k = 0;
        while(k < n){
            if(count[index] > 0){
                a[k] = index;
                count[index]--;
                
                if(count[index] == 0){
                    index++;
                }
                
                k++;
            }
        }
}
