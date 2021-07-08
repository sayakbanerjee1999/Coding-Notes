/*
static class Node {
    int data;
    Node left;
    Node right;
  
    Node(int data) {
      this.data = data;
      left = null;
      right = null;
    }
  }
  */


static void levelOrder(Node root) {
    if (root == null)
      return;
  
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
          System.out.println();
        }
      } else {
        // Pushing left child current node
        if (curr.left != null)
          q.add(curr.left);
  
        // Pushing right child current node
        if (curr.right != null)
          q.add(curr.right);
  
        System.out.print(curr.data + " ");
      }
    }
  }
