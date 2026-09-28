# The key idea is that normal numerical sorting doesn't work. Instead, for two numbers n1 and n2, 
# we decide their order by comparing n1 + n2 with n2 + n1. For example, for "3" and "30", we 
# compare "330" vs "303", so "3" should come first. The custom comparator returns -1 when n1 
# should appear before n2, allowing cmp_to_key to use this rule during sorting. Once the numbers 
# are sorted, we concatenate them to form the largest possible number. Finally, converting the 
# result to an integer handles cases such as ["0", "0"], turning "00" into "0".

class Solution:
    def largestNumber(self, nums: list[int]) -> str:
        # Convert to String for comparison
        for i, n in enumerate(nums):
            nums[i] = str(n)
        
        # 3, 30 -> 330 > than 303
        # So basically you compare by concating 2 integers and see which is greater
        # 9, 34 -> Compare 349 and 943 and return 943

        def compare(n1, n2):
            if n1 + n2 > n2 + n1:
                return -1               # Return n1
            else:
                return 1

        nums = sorted(nums, key = cmp_to_key(compare))
        return str(int("".join(nums))) # int conversion for 000 to 0
