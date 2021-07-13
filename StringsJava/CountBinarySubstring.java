public int countBinarySubstrings(String s) {
        int prev=0, curr=1 , ans=0;
        
        for(int i=1;i<s.length();i++){
          // whenever character switch from (0 to 1) or (1 to 0) increase ans by minimum(previous and current ) because
          //min(countzeros,countones) we have to do
            if(s.charAt(i)!=s.charAt(i-1)){
                ans+=Math.min(curr,prev);
                prev=curr;
              //reset current for next iter
                curr=1;
              //count the continous occurance of 0 and 1.
            }else{
                curr++;
            }
        }
        
         return ans+Math.min(curr,prev);
    }

//Complexity:
//Time:O(n) and Space :O(1)
