class Main{
  public static void printTargetSumSubsets(int[] arr, int idx, String set, int currSum, int target){
    if (idx==arr.length){
      if (currSum==target){
        System.out.println(set+".");
      }
      return;
    }
    //explore the two choices in hand either include the currVal or exclude
    printTargetSumSubsets(arr, idx+1, set+arr[idx]+",", currSum+arr[idx], target);
    printTargetSumSubsets(arr, idx+1, set, currSum, target);
  }
}
