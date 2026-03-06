class Solution:
    def exclusiveTime(self, n: int, logs: List[str]) -> List[int]:
        prevTime = 0
        stack = []
        function_time = [0] * n

        for log in logs:
            function_id, type_, timestamp = log.split(":")
            function_id = int(function_id)
            timestamp = int(timestamp)

            if type_ == "start":
                if stack:
                    function_executing = stack[-1]
                    function_time[function_executing] += (timestamp - prevTime)

                stack.append(function_id)
                prevTime = timestamp

            else: 
                function_executing = stack.pop()
                function_time[function_executing] += (timestamp - prevTime + 1)

                # When a function ends it has consumed the whole unit of time. 
                # Next job can only start from the next unit of time.
                prevTime = timestamp+1
        
        return function_time
