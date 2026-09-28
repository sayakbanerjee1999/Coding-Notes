class Solution:
    def findOrder(self, numCourses: int, prerequisites: list[list[int]]) -> list[int]:
        # Build for Adjacency List and InDegrees
        coursesList = [[] for _ in range(numCourses)]
        inDegrees = [0] * numCourses

        # In Adjacency List Store 
        # Prerequisite is index. In list store all the courses.
        # Courses depend on Prerequisites so inDegrees of courses increase based on how many prerequisites
        for course, prerequisite in prerequisites:
            coursesList[prerequisite].append(course)
            inDegrees[course] += 1

        # Now Kadane's Algorithm 
        q = deque()
        for i in range(numCourses):
            if inDegrees[i] == 0:
                q.append(i)
        
        # Pop course from the queue. 
        # If Indegree of downstream course related to this course. 
        # Delete the indegree and if indegree == 0 push to queue 
        res = []
        while q:
            course = q.popleft()
            res.append(course)

            for downstream_courses in coursesList[course]:
                inDegrees[downstream_courses] -= 1

                if inDegrees[downstream_courses] == 0:
                    q.append(downstream_courses)
        
        return [] if len(res) != numCourses else res
