# The fundamental challenge is that we need to generate 10 equally likely outcomes using a function
# that only produces 7 equally likely outcomes. Since 10 is not a factor of 7, we can't 
# simply map the outputs directly.

# The key insight is to create a larger uniform sample space that we can evenly divide into 10 parts. 
# If we call rand7() twice, we can think of it as creating a 7×7 grid of possibilities, giving us 
# 49 equally likely outcomes. We can represent each outcome uniquely by treating the two calls 
# as digits in base 7.

# By computing (rand7() - 1) * 7 + rand7(), we generate numbers from 1 to 49 uniformly. The first 
# rand7() - 1 gives us the "row" (0-6), and multiplying by 7 shifts us to the correct row. The second 
# rand7() gives us the "column" (1-7) within that row.

# Now we have 49 uniform outcomes, but we need to map them to 10 outcomes. Since 49 is not divisible 
# by 10, we can't use all 49 values without introducing bias. However, 40 is divisible by 10! So we 
# use only the first 40 values and reject any result greater than 40. This rejection sampling 
# ensures that each of the 40 accepted values has equal probability.

# Finally, we map these 40 values to 1-10 using modulo arithmetic: (x % 10) + 1. This gives each 
# number from 1 to 10 exactly 4 chances out of 40 to be selected, maintaining perfect uniformity. 
# The rejection of values 41-49 means we might need multiple attempts, but this guarantees an unbiased result.

class Solution:
    def rand10(self):
        """
        :rtype: int
        """
        while True:
            # Generate row index (0-6) by subtracting 1 from rand7() result
            row = rand7() - 1
          
            # Generate column index (1-7) directly from rand7()
            col = rand7()
          
            # Map to a number in range 1-49 using 7x7 grid
            # row * 7 gives us 0, 7, 14, 21, 28, 35, 42
            # Adding col gives us values from 1 to 49
            combined_value = row * 7 + col
          
            # Only use values 1-40 for uniform distribution
            # Values 41-49 are rejected to ensure equal probability
            if combined_value <= 40:
                # Map 1-40 to 1-10 with equal probability (4 occurrences each)
                # combined_value % 10 gives 0-9, then add 1 to get 1-10
                return combined_value % 10 + 1
        
