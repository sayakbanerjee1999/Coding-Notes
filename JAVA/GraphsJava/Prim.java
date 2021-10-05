import java.util.*;

class Prim{
  
  public static int minWeight(int weight[], Boolean visited[]){
    int V = weight.length;
    int min = Integer.MAX_VALUE, minIndex = -1;
    for (int v= 0;v<V;v++){
      if(visited[v] == false && weight[v]<min){
        min = weight[v];
        minIndex = v;
      }
    }
    return minIndex;
  }
  
  public static void printMST(int parent[], int adj[][]){
    for (int i=1;i<V;i++)
      System.out.print(parent[i] + "-"+ i +"-->" +adj[i][parent[i]]); 
  }
  
  public static void prim(int adj[][]){
    //initializations
    int V = adj.length;
    int parent[] = new int[V];
    int weight[] = new int[V];
    Boolean visited[] = new Boolean[V];
    for (int i=0;i<v;i++){
      weight[i] = Integer.MAX_VALUE;
      visited[i] = false;
      parent[i] = -1;
    }
    //starting with vertex 0 
    weight[0] = 0;
    for (int i=0;i<V;i++){
      //get the vertex with the min weight to be my current node
      int u = minWeight(weight,visited);
      visited[u] = true;
      //check for all vertices which are not visited and not 0 and also if weight is lesser
      for (int v =0;v<V;v++){
        if (adj[u][v]!=0 && visited[v] == false && adj[u][v] < weight[v]){
          parent[v] = u;
          weight[v] = adj[u][v];
        }
      }
    }
    printMST(parent,adj);
    
  }
  
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int v = sc.nextInt();
    int e = sc.nextInt();
    int adjMat[][] = new int[v][v];
    for (int i=0;i<e;i++){
      int v1 = sc.nextInt();
      int v2 = sc.nextInt();
      int weight = sc.nextInt();
      adjMat[v1][v2] = weight;
      adjMat[v2][v1] = weight;
    }
    prim(adjMat);
  }
}
