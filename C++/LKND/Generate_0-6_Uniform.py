# # The idea in one sentence: first turn the biased coin into a fair coin, 
# # then use the fair coin to build a uniform number from 0 to 6, redrawing whenever you get 7.

# Step 1: Fair bit from a biased coin (von Neumann's trick)
# Flip the biased coin twice:

# Pair      Probability	      Action
# (0, 1)	  p · (1−p)	        return 0
# (1, 0)	  (1−p) · p	        return 1
# (0, 0)	  p²	              discard, flip two more
# (1, 1)	  (1−p)²	          discard, flip two more

# Intuition: (0,1) and (1,0) contain the same two outcomes, one 0 and one 1, 
# in opposite order. Their probabilities are both p(1−p), no matter what p is, 
# so the order of the two flips is a fair coin. Equal pairs (00, 11) could be either way, so we throw them out.

# Detail to mention: use non-overlapping pairs, i.e. flips (1,2), (3,4), and so on. 
# Sliding pairs like (1,2), (2,3) share a flip, so the resulting bits aren't independent.

# Step 2: Uniform over 0–6 from fair bits (rejection sampling)
# Three fair bits make a uniform number in 0–7, where each value has probability 1/8. If the result is 7, throw it away and draw three new bits.
# Why this gives exactly 1/7 each: 
# in any single attempt, each of 0–6 has the same probability, 1/8. 
# Rejecting 7 removes one outcome but treats the other seven identically, so the accepted values are equally likely: (1/8) / (7/8) = 1/7.

# Cost
# One fair bit: each pair succeeds with probability 2p(1−p), so it takes an expected 1 / (p(1−p)) flips.
# One attempt: 3 fair bits, and an attempt is accepted with probability 7/8, so on average there are 8/7 attempts.
# Total expected flips: 3 · (8/7) · 1/(p(1−p)) = 24 / (7p(1−p)). For a fair coin that's about 13.7 flips. 
#   It grows as p approaches 0 or 1, because nearly every pair is then 00 or 11 and gets discarded.
# Memory: O(1).


def solution(stream):
    n = len(stream)                      # total number of biased flips available
    i = 0                                # pointer to the next unread flip

    while True:                          # one pass = one attempt to produce a value in 0..6
        value = 0                        # number built from fair bits (reset each attempt)
        bits = 0                         # fair bits collected so far in this attempt

        while bits < 3:                  # need 3 fair bits -> uniform value in 0..7
            if i + 1 >= n:               # fewer than 2 flips left: can't read a full pair
                return -1                # stream exhausted before a result was produced

            a = stream[i]                # first flip of the pair
            b = stream[i + 1]            # second flip of the pair
            i += 2                       # advance past both flips (non-overlapping pairs)

            if a != b:                   # (0,1) or (1,0): each has probability p(1-p) -> fair
                value = value * 2 + a    # shift left, append fair bit: (0,1)->0, (1,0)->1
                bits += 1                # one more fair bit collected
            # else: (0,0) or (1,1) are unbalanced -> discard, read the next pair

        if value < 7:                    # 0..6 each had probability 1/8 -> 1/7 after rejecting 7
            return value                 # accept
        # value == 7: reject and start a fresh attempt with new bits (never reuse old ones)
