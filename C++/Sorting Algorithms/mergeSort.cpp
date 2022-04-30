class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
        // Your code here
        // Never consider left as 0 and right as n-1
         
        int n1 = m - l + 1;
        int n2 = r - m;
         
        int arr1[n1], arr2[n2];
        
        for(int i = 0; i < n1; i++){
            arr1[i] = arr[l+i];
        }
        
        for(int i = 0; i < n2; i++){
            arr2[i] = arr[m + i + 1];
        }
        
        int i = 0, j = 0, k = l;        // Very important to start k from left
        while(i < n1 && j < n2){
            if(arr1[i] < arr2[j]){
                arr[k++] = arr1[i++];
            }
            
            else{
                arr[k++] = arr2[j++];
            }
        }
        
        while(i < n1){
            arr[k++] = arr1[i++];
        }
        
        while(j < n2){
            arr[k++] = arr2[j++];
        }
    }
    
    public:
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        if(l >= r)
            return;
            
        int mid = l + (r-l)/2;
        
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        
        merge(arr, l, mid, r);
    }
};
