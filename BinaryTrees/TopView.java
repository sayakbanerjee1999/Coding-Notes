static ArrayList<Integer> topView(Node root)
    {
        class QueueObj {
            Node node;
            int level;
 
            QueueObj(Node node, int hd)
            {
                this.node = node;
                this.level = level;
            }
        }
        ArrayList<Integer> res = new ArrayList<Integer>();
        Queue<QueueObj> q = new LinkedList<QueueObj>();
        Map<Integer, Node> topViewMap
            = new TreeMap<Integer, Node>();
 
        if (root == null) {
            return null;
        }
        else {
          //first starting with level 0
            q.add(new QueueObj(root, 0));
        }
 
        
        while (!q.isEmpty()) {
            QueueObj tmpNode = q.poll();
          //grouping hor level values together
            if (!topViewMap.containsKey(tmpNode.level)) {
                topViewMap.put(tmpNode.level, tmpNode.node);
            }
           //decrement if going to left
            if (tmpNode.node.left != null) {
                q.add(new QueueObj(tmpNode.node.left,
                                   tmpNode.level - 1));
            }
          //increment if going to right
            if (tmpNode.node.right != null) {
                q.add(new QueueObj(tmpNode.node.right,
                                   tmpNode.level + 1));
            }
        }
        for (Entry<Integer, Node> entry : topViewMap.entrySet()) {
            res.add(entry.getValue().data);
        }
  return res;
}


