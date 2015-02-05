import os, sys

# you can use print for debugging purposes, e.g.
# print "this is a debug message"

def solution(A):
    # write your code in Python 2.7
    right = sum(A)
    left = 0
    minimal = sys.maxint
    for num in A[:-1]:
        left += num
        right -= num
        if abs(left - right) < minimal:
            minimal = abs(left - right)
	print left, right, minimal
    return minimal        
    pass


print solution ([2000, 2000])
