class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> lists = new ArrayList<>();
        List<Integer> list = new ArrayList<>();
        recursion(lists,list,nums);
        return lists;
    }
    void recursion(List<List<Integer>> lists,List<Integer> tempList,int[] nums)
    {
        //If all elements are present then consider it as one solution and add to 
        //main result list
        if(tempList.size() == nums.length)
        {
            lists.add(new ArrayList(tempList));
            return ;
        }
        else
        {
            for(int i=0;i<nums.length;i++)
            {
                //if num already present in temp list ignore
                if(tempList.contains(nums[i]))  continue;
                //else add the number to templist
                tempList.add(nums[i]);
                //recursively traverse with the templist
                recursion(lists,tempList,nums);
                //backtrack by removing the element and going back to prev step
                tempList.remove(tempList.size()-1);
            }
        }
    }
    
}
