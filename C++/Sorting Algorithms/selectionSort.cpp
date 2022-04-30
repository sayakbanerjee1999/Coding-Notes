class Solution
{
    public:
    void selectionSort(int arr[], int n)
    {
        //code here
        for(int i = 0; i < n-1; i++){
            int minInx = i;
            
            for(int j = i+1; j < n; j++){
                if(arr[j] < arr[minInx])
                    minInx = j;
            }
            
            if(minInx != i){
                swap(arr[i], arr[minInx]);
            }
        }
    }
};
