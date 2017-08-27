class Solution(object):
    def maxDistance(self, arrays):
        """
        :type arrays: List[List[int]]
        :rtype: int
        """
        distance = max(abs(arrays[1][-1]-arrays[0][0]), abs(arrays[1][0]-arrays[0][-1]))
        min_one = min(arrays[0][0], arrays[1][0])
        max_one = max(arrays[0][-1], arrays[1][-1])
        for i in xrange(2, len(arrays)):
            distance = max(distance, abs(arrays[i][-1]-min_one), abs(arrays[i][0]-max_one))
            min_one = min(min_one, arrays[i][0])
            max_one = max(max_one, arrays[i][-1])
        return distance
