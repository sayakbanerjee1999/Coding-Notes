int minimumDays(int S, int N, int M){
    // code here
    
    int x = S/7;        //Number of Sundays that will occur
    int y = S-x;        //Number of days on which I can buy food
    
    int totalFood = S*M;        //Total food required for survival on the island
    int days = totalFood/N;     //Number of days I have to buy food
    
    if(totalFood%N != 0){
        days++;
    }
    
    if(days <= y)
        return days;
    
    else
        return -1;
}