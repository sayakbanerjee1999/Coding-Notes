class Solution {

    public List<Integer> partitionLabels(String s) {
        int n = s.length();
        //output arraylist
        ArrayList<Integer> res = new ArrayList<>();
        //hashmap storing character and their end index
        HashMap<Character,Integer> hm = new HashMap<>();
        for (int i=0;i<n;i++){
            char c = s.charAt(i);
            hm.put(c,s.lastIndexOf(c));
        }
        //storing initial max end index
        int max = hm.get(s.charAt(0));
        int count = 1;
        for (int i=1;i<n;i++){
            //if index in range of max last index
            if (i<=max){
                //check if its index is less than max
                //then increment count
                if (hm.get(s.charAt(i))<=max){
                count++;
                } else{
                    //else take max of that index and max and inc count
                    max = Math.max(hm.get(s.charAt(i)),max);
                    count++;
                }
            }
            //if index not in range
            else{
                //then first add the count
                //reinitialize count to 1
                //and update max
                res.add(count);
                count = 1;
                max = hm.get(s.charAt(i));
            }
        }
        //add the final count to res arraylist
        res.add(count);
        return res;
    }
}
