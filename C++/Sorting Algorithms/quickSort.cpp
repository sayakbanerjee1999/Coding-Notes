class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        // code here
        if(low >= high)
        return;
    
        int pivot = partition(arr, low, high);
        
        quickSort(arr, low, pivot-1);
        quickSort(arr, pivot+1, high);
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
        // Your code here
        int pivot = arr[high];       // Initially Pivot is the last element
        int i = low - 1;             // i keeps a track of the place between which to swap
   
        for(int j = low; j <= high-1; j++){
            if(arr[j]<=pivot){
                i++;
                swap(arr[i], arr[j]);
            }
        }    
   
        swap(arr[i+1], arr[high]);         //Swap the initial pivot to the position it will stay on the final soerted array
   
        return i+1;
    }
};
