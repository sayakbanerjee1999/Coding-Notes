/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}
    
    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/

class Solution {
    public Node connect(Node root) {
    if (root == null)
      return null;
  
    Queue<Node> q = new LinkedList<>();
  
    // Pushing root node into the queue.
    q.add(root);
  
    // Pushing delimiter into the queue.
    q.add(null);
  
    // Executing loop till queue becomes
    // empty
    while (!q.isEmpty()) {
  
      Node curr = q.poll();
  
      // condition to check the
      // occurence of next level
      if (curr == null) {
        if (!q.isEmpty()) {
          q.add(null);
        }
      } else {
          curr.next = q.peek();
        // Pushing left child current node
        if (curr.left != null)
          q.add(curr.left);
  
        // Pushing right child current node
        if (curr.right != null)
          q.add(curr.right);
      }
    }
        return root;
}
}
