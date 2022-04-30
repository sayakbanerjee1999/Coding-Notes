class Solution
{
    public:
    
    //Function to sort the array using insertion sort algorithm.
    void insertionSort(int arr[], int n)
    {
        //code here
        for(int i = 1; i < n; i++){
            int key = arr[i];
            
            int j = i - 1;
            while(j >= 0  &&  arr[j] > key){
                arr[j+1] = arr[j];
                j--;
            }
            
            // Think for 1st element j-- makes it -1
            // so j+1 makes it 0 and inserted in first position
            arr[j+1] = key;
        }
    }
};
