class Solution {
    //store elements of the array as pair to reduce finding 4 elements to 2 pairs
    static class pair {
        int first, second;
        public pair(int first, int second)
        {
            this.first = first;
            this.second = second;
        }
    }
    public ArrayList<ArrayList<Integer>> fourSum(int[] arr, int k) {
        // hashmap storing the pairwise sum and the pair values
        int n = arr.length;
        HashMap<Integer, pair> mp = new HashMap<Integer, pair>();
        //storing the pairwise sums
        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++)
                mp.put(arr[i] + arr[j], new pair(i, j));
        
        ArrayList<ArrayList<Integer>> res = new ArrayList<ArrayList<Integer>>();
        //traversing the hashmap and finding pairs with k-sum
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int sum = arr[i] + arr[j];
                //checking if k-sum is present as key in hashmap
                if (mp.containsKey(k - sum)) {
                    pair p = mp.get(k - sum);
                    if (p.first != i && p.first != j
                        && p.second != i && p.second != j){
                        ArrayList<Integer> a = new ArrayList<Integer>();
                        a.add(arr[i]);
                        a.add(arr[j]);
                        a.add(arr[p.first]);
                        a.add(arr[p.second]);
                        Collections.sort(a);
                        res.add(a);
                    }
                }
            }
        }
        return res;
    }
}
