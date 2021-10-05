/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> neighbors;
    public Node() {
        val = 0;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val) {
        val = _val;
        neighbors = new ArrayList<Node>();
    }
    public Node(int _val, ArrayList<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}
*/

class Solution {
    public Node cloneGraph(Node node) {
        if (node == null)
        return null;
        Queue<Node> que = new LinkedList<>();
        que.add(node);
        HashMap<Node, Node> map = new HashMap<>();
        Node nnode = new Node(node.val, new ArrayList<>());
        map.put(node, nnode);
        while (!que.isEmpty()) {
            Node temp = que.poll();
            for (Node i: temp.neighbors) {
                if (map.containsKey(i) == false) {
                    que.add(i);
                    map.put(i, new Node(i.val, new ArrayList<>()));
                }
                map.get(temp).neighbors.add(map.get(i));
            }
        }
    return nnode;
    }
}
