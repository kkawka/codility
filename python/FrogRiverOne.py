__author__ = 'kkamil'


# you can use print for debugging purposes, e.g.
# print "this is a debug message"

def solution(X, A):
    # write your code in Python 2.7
    leafs = [0]*X
    max = 0
    for num in range(len(A)):
        if leafs[A[num] - 1] == 0:
            leafs[A[num] - 1] = num
            max = num
    for leaf in leafs:
        if leaf == 0:
            return -1
    return max
    pass
