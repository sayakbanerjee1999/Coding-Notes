/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

class Solution {
   
  class Point {
	TreeNode root;
	int x;
	int y;
	public Point(TreeNode root, int x, int y) {
		this.root = root;
		this.x = x;
		this.y = y;
	}
  }

public List<List<Integer>> verticalTraversal(TreeNode root) {
  //2d list [[9],[3,15],[20],[7]] as output
	List<List<Integer>> res = new ArrayList<>();
	if (root == null) 
		return res;
//hashmap having the horizontal level treenode and its (x,y) coordinate kept in a sorted order using comparator
	Map<Integer, PriorityQueue<Point>> map = new HashMap<>();
  //BFS application
	Queue<Point> queue = new LinkedList<>();
  //first we start at root and add 0 hor 0 ver distance to it
	queue.offer(new Point(root, 0, 0));
  //for sorting the pqueue of nodes using comparator interface
    Comparator<Point> comparator = (a, b) -> {
      //if vertical distance same, return whose node value is smaller
		if (a.y == b.y) {
			return a.root.val - b.root.val;
		} else {
      //if vert distance not same, then vertical whose smaller has to be returned first
			return a.y - b.y;
		}
	};
  //for getting the min and max hor level
	int minIdx = 0;
	int maxIdx = 0;
  //start bfs
	while (!queue.isEmpty()) {
    //get the first node from queue
		Point point = queue.poll();
		root = point.root;
    //put in hashmap with the horizontal level value and map it to a pqueue where elements will be added based on comparator sorting
		map.putIfAbsent(point.x, new PriorityQueue<>(comparator));
    //add the point to the q corresponding to that hor level
		map.get(point.x).add(point);
    //update the min and max horizontal levels
		minIdx = Math.min(minIdx, point.x);
		maxIdx = Math.max(maxIdx, point.x);
    //if going to left -> horizontal-1 & vertical+1
		if (root.left != null)  queue.offer(new Point(root.left, point.x - 1, point.y + 1));
    //if going to right -> horizontal+1 & vertical+1
		if (root.right != null) queue.offer(new Point(root.right, point.x + 1, point.y + 1));
	}
//traverse from min hor level to max hor level and add to 2d list
	for (int i = minIdx; i <= maxIdx; i++) {
		PriorityQueue<Point> pq = map.get(i);
		List<Integer> list = new ArrayList<>();
		while (!pq.isEmpty()) {
			list.add(pq.poll().root.val);
		}
		res.add(list);
	}

	return res;
  }
}
