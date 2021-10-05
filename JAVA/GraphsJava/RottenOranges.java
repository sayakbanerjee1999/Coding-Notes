class Solution {
    //for storing coordinates
    static class Pair {
        int x;
        int y;
        Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
	
    public int orangesRotting(int[][] grid) {
        //for our BFS traversal
        Queue<Pair> q = new LinkedList<>();
        int total = 0, rotten = 0, time = 0;
		
       for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                //total oranges that are not rotten
                if (grid[i][j] == 1 || grid[i][j] == 2) total++;
                //if rotten orange found add to q
                if (grid[i][j] == 2) q.offer(new Pair(i, j));
            }
        }
		//if total 0
        if (total == 0) return 0;		
        while (! q.isEmpty()) {
            int size = q.size();
            //rotten oranges in the queue only
            rotten += size;
            //if total oranges equal to rotten it means all fresh have been made rotten
            if (rotten == total) return time;
            
            //increment time level by 1
            time++;
			//run for q size
            for (int i = 0; i < size; i++) {
                //get the first element
                Pair p = q.peek();
				//check for edge conditions and fresh orange exist or not for all 4 directions
                //then add to queue and change its value to 2
                if (p.x + 1 < grid.length && grid[p.x + 1][p.y] == 1) {
                    grid[p.x + 1][p.y] = 2;
                    q.offer(new Pair(p.x + 1, p.y));
                }
                if (p.x - 1 >= 0 && grid[p.x - 1][p.y] == 1) {
                    grid[p.x - 1][p.y] = 2;
                    q.offer(new Pair(p.x - 1, p.y));
                }
                if (p.y + 1 < grid[0].length && grid[p.x][p.y + 1] == 1) {
                    grid[p.x][p.y + 1] = 2;
                    q.offer(new Pair(p.x, p.y + 1));
                }
                if (p.y - 1 >= 0 && grid[p.x][p.y - 1] == 1) {
                    grid[p.x][p.y - 1] = 2;
                    q.offer(new Pair(p.x, p.y - 1));
                }
                q.poll();
            }
        }
        //if fresh orange still remains and cant be made rotten then -1
        return -1;
    }
}
