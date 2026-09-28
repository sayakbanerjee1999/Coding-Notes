# This is the first Solution to propose (Rejection Sampling) - 
# Approach 1: Rejection sampling
# Enclose the circle in its bounding square, pick a uniform point in the square, 
# and keep it only if it lands inside the circle. Otherwise pick again.

# Why the result is uniform: Every point in the square is equally likely. 
# Discarding the points outside the circle doesn't change the fact that every point inside 
# it was equally likely. So the points we keep are uniform over the circle.

class Solution:
    def __init__(self, radius: float, x_center: float, y_center: float):
        self.radius = radius
        self.x_center = x_center
        self.y_center = y_center

    def randPoint(self) -> list[float]:
        while True:
            # Uniform point in the square [-radius, radius] x [-radius, radius]
            x = random.uniform(-self.radius, self.radius)
            y = random.uniform(-self.radius, self.radius)

            # Keep it only if it's inside the unit circle (boundary included)
            if x * x + y * y <= self.radius * self.radius:
                return [self.x_center + x,
                        self.y_center + y]

# Now the Polar Coordinate Approach
# A point in the circle is an angle θ and a distance r from the center.
# The angle is simple. The circle looks the same in every direction, so θ is uniform in [0, 2π).
# The radius is the tricky part. The obvious choice r = R · random() is wrong. It picks every 
# distance equally often, but there's more area farther out. A ring at distance r has circumference 
# 2πr, so rings near the edge need more points than rings near the center. With r = R · random(), 
# half the points land within R/2 of the center, yet that inner disk is only a quarter of the area. 
# The center ends up twice as crowded as it should be.

# The fix is r = R · √random(). Here's the one-line derivation to give the interviewer:
# The probability that a uniform point lies within distance r of the center is the area of the smaller disk 
# divided by the total area: πr² / πR² = r² / R².
# Set that equal to a uniform number u and solve for r: u = r² / R², so r = R√u.

import math
import random

class Solution:
    def __init__(self, radius: float, x_center: float, y_center: float):
        self.radius = radius
        self.x_center = x_center
        self.y_center = y_center

    def randPoint(self) -> list[float]:
        theta = 2 * math.pi * random.random()              # uniform angle
        r = self.radius * math.sqrt(random.random())       # sqrt corrects for area

        return [self.x_center + r * math.cos(theta),
                self.y_center + r * math.sin(theta)]

# Why is Solution 2 better than Solution 1?
Comparing time complexity of sampling method alternatives.
In expected running time, they're the same: both are O(1). The difference is the worst case:

# Polar always uses exactly 2 random numbers and a fixed amount of math, so it's O(1) in the worst case.
# Rejection is O(1) only in expectation. The number of tries follows a geometric distribution 
# (average 4/π ≈ 1.27, and the chance of needing more than k tries is 0.215^k). No fixed number of tries is ever guaranteed.
# single draw lands inside with probability (circle area / square area) = πR² / (2R)² = π/4 ≈ 0.785. 
# The number of tries is geometric, so the expected number is 4/π ≈ 1.27
# In practice, rejection is often just as fast or faster, because it skips sqrt, cos and sin. 
# So in 2D, polar wins only on guaranteed running time, not on actual speed.
# Where polar clearly wins: higher dimensions. 
