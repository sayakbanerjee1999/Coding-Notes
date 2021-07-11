public class Main{
  //passing the original array, value to find occurences of, current index(start with 0), occurence count(start with 0)
  public static int[] findAllIndices(int[] arr, int x, int idx, int occ){
    if (idx==arr.length){
      //return an array with length equal to the num of occurences of x
      return new int[occ];
    }
    if (arr[idx]==x){
      //if element found then add found index to occurence undex in the array, 
      //bottom up approach type; like my final array set to occ len is returned which we are filling now
      int[] indexArr = findAllIndices(arr, x, idx+1, occ+1);
      indexArr[occ] = idx;
      return indexArr;
    } else{
      int[] indexArr = findAllIndices(arr, x, idx+1, occ);
      return indexArr;
    }
  }
}
