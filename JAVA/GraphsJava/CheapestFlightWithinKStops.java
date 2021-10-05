/* There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

 

Example 1:


Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
Output: 200
Explanation: The graph is shown.
The cheapest price from city 0 to city 2 with at most 1 stop costs 200, as marked red in the picture. */

class Solution {
   public int findCheapestPrice(int n, int[][] flights, int src, int dst, int K) 
    {
      // int->[]->[]->[]
        Map<Integer,List<int[]>> map=new HashMap<>();
        for(int[] f:flights)
        {
            map.putIfAbsent(f[0],new ArrayList<>());
            map.get(f[0]).add(new int[]{f[1],f[2]});
        }
     //put in the [node,cost,kstops] arrays in the queue
        PriorityQueue<int[]> q=new PriorityQueue<>(new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
              //sorting on basis of cost
                return Integer.compare(o1[1],o2[1]);
            }
        });
     //initial
        q.offer(new int[]{src,0 ,K});
        while(!q.isEmpty())
        {
          //applying bfs
            int[] c=q.poll();
            int curr=c[0];
            int cost=c[1];
            int stop=c[2];
          //if destination node reached
            if(curr==dst)
                return cost;
          //if number of stops is greater than 0
            if(stop>=0)
            {   
              //if no edge from node
                if(!map.containsKey(curr))
                    continue;
              //else update cost and decrement stop
                for(int[] next:map.get(curr))
                {
                    q.add(new int[]{next[0], cost+next[1], stop-1});
                }
            }
        }
        return -1;
    }
}
