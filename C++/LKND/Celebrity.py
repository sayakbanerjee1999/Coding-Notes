# The knows API is already defined for you.
# return a bool, whether a knows b
# def knows(a: int, b: int) -> bool:

# The key insight is that when we ask if person a knows person b, we can eliminate one 
# candidate from being the celebrity:

# If a knows b, then a cannot be the celebrity (celebrities don't know anyone)
# If a doesn't know b, then b cannot be the celebrity (everyone must know the celebrity)
# This elimination property allows us to find a potential celebrity candidate efficiently. 
# We can start with person 0 as our initial candidate and compare them with each subsequent person. 
# Each comparison eliminates exactly one person from consideration.

# By doing this for all n people, we'll be left with exactly one candidate who hasn't been eliminated. 
# This takes only n - 1 calls to the knows function.

# However, this candidate might not actually be a celebrity - they're just the only person who wasn't 
# eliminated. We need to verify two conditions:

# The candidate doesn't know anyone else (check if knows(candidate, i) is false for all other people)
# Everyone else knows the candidate (check if knows(i, candidate) is true for all other people)

# 2(n-1) calls -> O(n)


class Solution:
    def findCelebrity(self, n: int) -> int:
        # Step 1: Find a candidate for celebrity
        # If current candidate knows person i, then candidate cannot be a celebrity
        # Person i becomes the new candidate
        candidate = 0
        for i in range(1, n):
            if knows(candidate, i):
                candidate = i

        # Step 2: Verify if the candidate is actually a celebrity
        # Check two conditions:
        # 1. Celebrity should not know anyone (except themselves)
        # 2. Everyone should know the celebrity
        for i in range(n):
            if candidate != i:
                # If candidate knows person i, or person i doesn't know candidate
                # then candidate is not a celebrity
                if knows(candidate, i) or not knows(i, candidate):
                    return -1

        return candidate
