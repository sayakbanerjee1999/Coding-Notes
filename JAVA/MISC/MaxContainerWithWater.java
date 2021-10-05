class Solution {
    public int maxArea(int[] height) {
        int a_pointer = 0;
        int b_pointer = height.length-1;
        int area = 0;
        while (a_pointer<b_pointer){
            int a_height = height[a_pointer];
            int b_height = height[b_pointer];
            if (a_height<b_height){
                area = Math.max((a_height*(b_pointer-a_pointer)), area);
                a_pointer++;
            }
            else {
                area = Math.max((b_height*(b_pointer-a_pointer)), area);
                b_pointer--;
            }
        }
        return area;
    }
}
