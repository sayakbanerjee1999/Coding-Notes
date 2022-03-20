long long findMinDiff(vector<long long> a, long long n, long long m){
      //code
      sort(a.begin(), a.end());
      long long minimumDiff = INT_MAX;
      
      long long i = 0, j = 0;
      while(j < n){
          if(j - i + 1 < m){
              j++;
          }
            
          else if(j - i + 1 == m){
              long long diff = a[j] - a[i];
              minimumDiff = min(diff, minimumDiff);
              i++;
              j++;
          }
      }
        
      return minimumDiff;
}
