# Scenario	                                                            Exclusive time	        Inclusive time
# Sequential repeats (same function called several times, not nested)	  Same as your code	      Same as the previous inclusive code
# Recursion, counting each call separately (the 13 in LC example 2)	    Same as your code	      Same as the previous inclusive code
# Recursion, counting only the outermost call (the 8, as profilers do)	Same as your code	      Changes

# Your exclusive code never needs to change. It gives each time unit to whichever frame 
# is on top of the stack, so it doesn't care which function that frame belongs to, or whether 
# that function is already active lower in the stack.

# Keep a depth counter for each function. Record the start time only when that 
# function's depth goes from 0 to 1. Add the duration only when its depth returns to 0.
class Solution:
    def inclusiveTime(self, n: int, logs: List[str]) -> List[int]:
        # Only if UnORDERED
        logs = sorted(logs, key=self._sort_key)
      
        depth = [0] * n          # number of active frames per function
        outer_start = [0] * n    # start timestamp of each function's outermost active frame
        function_time = [0] * n

        for log in logs:
            function_id, type_, timestamp = log.split(":")
            function_id = int(function_id)
            timestamp = int(timestamp)

            if type_ == "start":
                # Only if Depth = 0; then add otherwise skip
                if depth[function_id] == 0:
                    outer_start[function_id] = timestamp
                depth[function_id] += 1

            else:
                depth[function_id] -= 1
                if depth[function_id] == 0:
                    function_time[function_id] += timestamp - outer_start[function_id] + 1

        return function_time


    # UNORDERED EVENTS
    def _sort_key(log: str):
        _, type_, timestamp = log.split(":")
        # Sort by time; at equal timestamps, "start" (0) comes before "end" (1)
        return (int(timestamp), 0 if type_ == "start" else 1)

    # SORTING LOGIC FOR TIE BREAK
    # logs = ["1:end:6", "0:end:7", "0:start:2", "1:start:6", "0:end:5", "0:start:0"]
    # order_logs(logs)
    # ['0:start:0', '0:start:2', '0:end:5', '1:start:6', '1:end:6', '0:end:7']
    # exclusive → [7, 1]   (same as the simple sort key; no hard ties here)
    from collections import Counter
    from itertools import groupby
    
    def order_logs(logs, inclusive_end=True):
        events = sorted(
            (int(ts), int(fid), type_)
            for fid, type_, ts in (log.split(":") for log in logs)
        )
        ordered, stack = [], []
    
        for t, group in groupby(events, key=lambda e: e[0]):
            starts, ends = [], Counter()
            for _, fid, type_ in group:
                if type_ == "start":
                    starts.append(fid)
                else:
                    ends[fid] += 1
    
            while starts or +ends:                      # +ends drops zero counts
                top_can_end = bool(stack) and ends[stack[-1]] > 0
    
                # Inclusive end: nothing can start in a unit that an ending call used,
                #   so starts go first; ends follow in stack (LIFO) order.
                # Half-open end: calls finishing at t hand the unit over, so ends go
                #   first; a zero-length call's end is matched right after its start.
                if top_can_end and (not inclusive_end or not starts):
                    fid = stack.pop()
                    ends[fid] -= 1
                    ordered.append(f"{fid}:end:{t}")
                elif starts:
                    fid = starts.pop(0)                 # parent/child unknowable if >1
                    stack.append(fid)
                    ordered.append(f"{fid}:start:{t}")
                else:
                    raise ValueError(f"end at t={t} doesn't match the running call")
    
        return ordered
    
