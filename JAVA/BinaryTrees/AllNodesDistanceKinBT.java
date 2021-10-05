/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public List<Integer> distanceK(TreeNode root, TreeNode target, int K) {
      //storing the result of the final level
        List<Integer> res= new ArrayList<>();
        if(root == null) return res;
      //hashmap for storing node and its parent
        HashMap<TreeNode, TreeNode> parentMap = new HashMap<>();
        findParent(parentMap, root);
      //queue for BFS traversal
        Queue<TreeNode> q = new LinkedList<>();
      //unique case as here we have to see the parent of the node too while BFS hence a hashset for keeping node visited or not
        HashSet<TreeNode> visited = new HashSet<>();
      //first add the target node to q then start BFS on it
        q.add(target);
        
        while(!q.isEmpty()){
            int size= q.size();
            for(int i =0; i <size; i++){
                TreeNode curr = q.poll();
                visited.add(curr);
                if(K == 0){
                  res.add(curr.val);
                }
              //check if map contains curr and its not visited then get its parent and add to q
                if(parentMap.containsKey(curr) && !visited.contains(parentMap.get(curr))){
                    q.add(parentMap.get(curr));
                }
                //add left child if present and non visited
                if(curr.left != null && !visited.contains(curr.left)){
                    q.add(curr.left);      
                }
              //add right child if present and unvisited
                
                if(curr.right != null && !visited.contains(curr.right)){
                    q.add(curr.right);      
                }
            }
          //decrement my final level to reach
            K--;
            if(K < 0) break;
        }
        return res;
    }
    
    //for filling the hashmap getting parent for every node
    private static void findParent(HashMap<TreeNode, TreeNode> hm, TreeNode root){
        if(root == null) return;
        if(root.left != null)
            hm.put(root.left, root);
        
        if(root.right != null)
            hm.put(root.right, root);
    
        findParent(hm, root.left);
        findParent(hm, root.right);
        return;
    }
}
