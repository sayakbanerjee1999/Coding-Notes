class Solution:
    def isRobotBounded(self, instructions: str) -> bool:
        # Direction index: 0=North, 1=West, 2=South, 3=East
        direction = 0
      
        # Track distance moved in each direction
        # North, West, South, East
        distance_per_direction = [0] * 4
      
        # Process each instruction
        for instruction in instructions:
            if instruction == 'L':
                # Turn left: rotate 90 degrees counter-clockwise
                direction = (direction + 1) % 4
            elif instruction == 'R':
                # Turn right: rotate 90 degrees clockwise
                # Adding 3 is equivalent to subtracting 1 with modulo 4
                direction = (direction + 3) % 4
            else:  # instruction == 'G'
                # Move forward in current direction
                distance_per_direction[direction] += 1
      
        # Robot forms a circle if:
        # 1. It returns to origin (North-South distances equal AND East-West distances equal)
        # Here equal means cancelling each other
        # 2. OR it's not facing North after one cycle (will eventually circle back)
        is_at_origin = (distance_per_direction[0] == distance_per_direction[2] and 
                        distance_per_direction[1] == distance_per_direction[3])
        is_not_facing_north = direction != 0
      
        return is_at_origin or is_not_facing_north
