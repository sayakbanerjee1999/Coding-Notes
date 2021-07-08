class Solution {
    int total = 0;
   public int pathSum(TreeNode root, int sum) {
        if (root == null)
            return 0;
        HashMap<Integer, Integer> hm = new HashMap<>();
     //gain is 0;
        hm.put(0, 1);
     //current node, currnt sum, target sum, hashmap
        findPathSum(root, 0, sum, hm);  
        return total; 
   }
    private void findPathSum(TreeNode curr, int sum, int target, HashMap<Integer, Integer> hm) {
        if (curr == null)
            return;
        //adding to sum
        sum += curr.val;
      //if sum-target there then add value to total
        if(hm.containsKey(sum-target))
          total += hm.get(sum-target);
      //put sumn in the map 
      hm.put(sum, hm.getOrDefault(sum, 0) + 1);
      //so for left n right
         findPathSum(curr.left, sum, target, hm);
         findPathSum(curr.right, sum, target, hm);
        hm.put(sum, hm.get(sum) - 1);
        return;
    }
}
