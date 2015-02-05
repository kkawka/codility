# you can use print for debugging purposes, e.g.
# print "this is a debug message"

def solution(X, Y, D):
    # write your code in Python 2.7
    dist = Y - X
    jumps = dist / D
    mod = dist % D
    if mod > 0:
        jumps += 1;
    return jumps
    pass

