__author__ = 'kkamil'

# you can use print for debugging purposes, e.g.
# print "this is a debug message"

def solution(A):
    # write your code in Python 2.7
    numbers = [0] * (len(A))
    for num in A:
        if num > len(A) or numbers[num - 1] > 0:
            return 0
        else:
            numbers[num - 1] = 1
    return 1
    pass
