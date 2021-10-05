class GFG
{
    ArrayList<Long> find(long arr[], int n, int x)
    {
        // code here
        ArrayList<Long> res = new ArrayList<Long>();
        int count = 0;
        int occFirst = -1;
        int occLast = -1;
        for (int i=0;i<n;i++){
            if(arr[i]==x){
                occLast=i;
                count++;
            }
        }
        if (occLast!=-1)
            occFirst = occLast - count + 1;
            
        res.add(Long.valueOf(occFirst));
        res.add(Long.valueOf(occLast));
        return res;
    }
}
