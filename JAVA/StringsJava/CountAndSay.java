public String countAndSay(int n) {
        String s = "1"; // base case 
        for(int i = 1; i < n; i++){ // build the numbers from 1 to n
            s = nextNumber(s);
        }
        return s; // return result
    }
    public static String nextNumber(String s){ 
        // create new StringBuilder
        StringBuilder result = new StringBuilder(); 
        for(int i = 0; i < s.length(); i++){ 
            // take in previous # and prepare to run across it
            // initialize how many times we've seen a #
            int count = 1; 
            // while we don't run off the end 
			// and we're still on the same #
            while(i + 1 < s.length() && s.charAt(i) == s.charAt(i+1)){ 
                // increment our pointer
                i++; 
                // increment how many times we've seen that #
                count++; 
            }
            // and append the count and then the #
            result.append(count).append(s.charAt(i)); 
        }
        return result.toString(); 
    }
