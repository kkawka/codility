# you can use print for debugging purposes, e.g.
# print "this is a debug message"

def solution(A):
    # write your code in Python 2.7
    size = len(A) + 1
    sum_num = sum(A)
    return (((1 + size)*size)/2) - sum_num
    pass

