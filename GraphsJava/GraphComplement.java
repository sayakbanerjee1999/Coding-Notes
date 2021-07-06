// All values are complemented except
    // diagonal ones
    int GC[][]=new int[V][V];
    for (int i=0; i<V; i++)
        for (int j=0; j<V; j++)
             GC[i][j] = (i != j)?  -GC[i][j] : 0;
   
